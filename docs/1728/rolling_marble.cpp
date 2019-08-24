#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, k;

bool checkValid(vector<vector<int>> &p, int s0, int v) {
    for (int i = 2; i < N+1; ++i){
        int s = (s0 + i * v);

        for (int j = 0; j < N; ++j) {
            if (p[i][j] == s) break;

            if (j == N-1) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;

    vector<vector<int>> P(N+1, vector<int>(N));
    for (int i = 0; i < N+1; ++i){
        for (int j = 0; j < N; ++j){
            cin >> P[i][j];
        }
    }

    vector<pair<int, int>> result(N);
    for (int i = 0; i < N; ++i){
        int s0 = P[0][i];

        for (int j = 0; j < N; ++j){
            int v = P[1][j] - s0;

            if (checkValid(P, s0, v)) {
                result[k++] = make_pair(s0, v);
                break;
            }
        }
    }
    
    sort(begin(result), end(result));

    for (auto r : result) cout << r.first << " " << r.second << "\n";

    return 0;
}