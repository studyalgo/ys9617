#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), L(N, 1);
    for (auto &a : A) cin >> a;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
            }
        }
    }

    cout << *max_element(begin(L), end(L));

    return 0;
}