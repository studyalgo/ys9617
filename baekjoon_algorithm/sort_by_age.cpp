#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<tuple<int, int, string>> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> get<0>(vec[i]) >> get<2>(vec[i]);
        get<1>(vec[i]) = i;
    }

    sort(begin(vec), end(vec));

    for (auto v : vec) cout << get<0>(v) << " " << get<2>(v) << "\n";

    return 0;
}