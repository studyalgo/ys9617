#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), L = { -1000000001 };
    for (auto &a : A) cin >> a;

    for (int i = 0; i < N; ++i) {
        if (L.back() < A[i]) {
            L.push_back(A[i]);
        }
        else {
            *lower_bound(begin(L), end(L), A[i]) = A[i];
        }
    }

    cout << L.size() - 1;

    return 0;
}