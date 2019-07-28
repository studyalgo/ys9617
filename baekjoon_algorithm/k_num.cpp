#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<int> vec(N);
    for (auto &v : vec) cin >> v;

    sort(begin(vec), end(vec));

    cout << vec[K-1] << "\n";

    return 0;
}