#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<string> vec(N);
    for (auto &v : vec) cin >> v;

    sort(begin(vec), end(vec), [](const string a, const string b){
        if (a.length() == b.length()) return a < b;
        else return (a.length() < b.length());
    });

    auto e = unique(begin(vec), end(vec));
    for (auto v = begin(vec); v != e; ++v) cout << *v << "\n";

    return 0;
}