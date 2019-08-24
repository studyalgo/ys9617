#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;
    
    sort(begin(A), end(A));
    sort(rbegin(B), rend(B));

    cout << inner_product(begin(A), end(A), begin(B), 0) << "\n";

    return 0;
}