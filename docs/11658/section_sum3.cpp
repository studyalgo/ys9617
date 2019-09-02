#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T sum(T *t, size_t i) {
    long long ans = 0;
    while (i > 0) {
        ans += t[i];
        i -= (i & -i);
    }
    return ans;
}

template<typename T>
void update(T *t, size_t i, T diff, size_t n) {
    while(i < n+1) {
        t[i] += diff;
        i += (i & -i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, w;
    cin >> N >> M;

    vector<vector<int>> vec(N, vector<int>(N));
    vector<vector<int>> p_tree(N+1, vector<int>(N+1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> vec[i-1][j-1];
            update(&p_tree[i][0], j, vec[i-1][j-1], N+1);
        }
    }

    for (int i = 0; i < M; ++i) {
        cin >> w;
        
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;

            update(&p_tree[x][0], y, c-vec[x-1][y-1], N+1);
            vec[x-1][y-1] = c;
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int result = 0;
            for (int j = x1; j <= x2; ++j) {
                result 
                += (sum(&p_tree[j][0], y2) - sum(&p_tree[j][0], y1-1));
            }

            cout << result << "\n";
        }
    }

    return 0;
}