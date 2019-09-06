#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, max = 0, max_idx;
    cin >> N;

    vector<int> A(N), L(N, 1), pos(N, -1), lis;
    for (auto &a : A) cin >> a;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i] && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
                pos[i] = j;
            }
        }

        if (max < L[i]) {
            max = L[i];
            max_idx = i;
        }
    }

    for (int i = max_idx; i != -1; i = pos[i]) {
        lis.push_back(A[i]);
    }

    cout << max << endl;
    
    for (auto l = rbegin(lis); l != rend(lis); ++l) {
        cout << *l << " ";
    }

    return 0;
}