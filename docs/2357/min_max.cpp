#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename T, typename fuc>
T segInit(vector<T> &v, vector<T> &t, int n, int s, int e, fuc f) {
    if (s == e) return t[n] = v[s];
    else {
        return t[n] = f(segInit(v, t, n*2, s, (s+e)/2, f),
                        segInit(v, t, n*2+1, (s+e)/2+1, e, f));
    }
}

template<typename T, typename fuc>
T sec(vector<T> &t, int n, int s, int e, int l, int r, fuc f) {
    if (l > e || r < s) return t[0];
    else if (l <= s && e <= r) return t[n];
    else {
        return f(sec(t, n*2, s, (s+e)/2, l, r, f),
                 sec(t, n*2+1, (s+e)/2+1, e, l, r, f));
    }
}

long long minValue(long long a, long long b) { return a < b ? a : b; }
long long maxValue(long long a, long long b) { return a > b ? a : b; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, a, b;
    cin >> N >> M;

    int h = ceil(log2(N));
    vector<long long> vec(N), min_tree(1 << (h+1), 1e9), max_tree(1 << (h+1), 0);
    for (auto &v : vec) cin >> v;

    segInit(vec, min_tree, 1, 0, N-1, minValue);
    segInit(vec, max_tree, 1, 0, N-1, maxValue);

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;

        cout << sec(min_tree, 1, 0, N-1, a-1, b-1, minValue) << " "
             << sec(max_tree, 1, 0, N-1, a-1, b-1, maxValue) << "\n";
    }

    return 0;
}