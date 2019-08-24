#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename T>
T segInit(vector<T> &v, vector<T> &t, int n, int s, int e) {
    if (s == e) return t[n] = v[s];
    else {
        return t[n] = segInit(v, t, n*2, s, (s+e)/2) + 
                      segInit(v, t, n*2+1, (s+e)/2+1, e);
    }
}

template<typename T>
T sum(vector<T> &t, int n, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    else if (l <= s && e <= r) return t[n];
    else {
        return sum(t, n*2, s, (s+e)/2, l, r) + 
               sum(t, n*2+1, (s+e)/2+1, e, l, r);
    }
}

template<typename T>
void update(vector<T> &t, int n, int s, int e, int idx, T d) {
    if (idx >= s && idx <= e) {
        t[n] += d;

        if (s != e) {
            update(t, n*2, s, (s+e)/2, idx, d);
            update(t, n*2+1, (s+e)/2+1, e, idx, d);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K, a, b;
    cin >> N >> M >> K;

    int h = ceil(log2(N));
    vector<long long> vec(N), seg_tree(1 << (h+1));
    for (auto &v : vec) cin >> v;

    segInit(vec, seg_tree, 1, 0, N-1);
    
    long long c;
    for (int i = 0; i < M+K; ++i) {
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - vec[b-1];
            vec[b-1] = c;
            update(seg_tree, 1, 0, N-1, b-1, diff);
        }
        else if (a == 2) {
            cout << sum(seg_tree, 1, 0, N-1, b-1, c-1) << "\n";
        }
    }

    return 0;
}