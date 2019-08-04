#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (auto &v : vec) cin >> v.first >> v.second;

    sort(begin(vec), end(vec));

    for (auto v : vec) cout << v.first << " " << v.second << "\n";

    return 0;
}