#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vec(N), L = {-1};
    for (auto& v : vec) cin >> v;

    for (auto v : vec) {
        if (L.back() < v) {
            L.push_back(v);
        }
        else {
            *lower_bound(begin(L), end(L), v) = v;
        }
    }

    cout << N - (L.size() - 1) << endl;

    return 0;
}
