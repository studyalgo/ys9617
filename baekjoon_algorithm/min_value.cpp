#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int segInit(vector<int> &v, vector<int> &t, int n, int s, int e) {
    if (s == e) return t[n] = v[s];
    else {
        return t[n] = 
        min(segInit(v, t, n*2, s, (s+e)/2), segInit(v, t, n*2+1, (s+e)/2+1, e));
    }
}

int minValue(vector<int> &t, int n, int s, int e, int l, int r) {
    if (l > e || r < s) return 1e9;
    else if (l <= s && e <= r) return t[n];
    else {
        return min(minValue(t, n*2, s, (s+e)/2, l, r),minValue(t, n*2+1, (s+e)/2+1, e, l, r));
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, a, b;
    cin >> N >> M;

    int h = ceil(log2(N));
    vector<int> vec(N), seg_tree(1 << (h+1));
    
    for (auto &v : vec) cin >> v;
    
    segInit(vec, seg_tree, 1, 0, N-1);

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        cout << minValue(seg_tree, 1, 0, N-1, a-1, b-1) << "\n";
    }

    return 0;
}