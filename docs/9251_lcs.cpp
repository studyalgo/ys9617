#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    vector<vector<int>> lcs(A.size()+1, vector<int>(B.size()+1, 0));

    int lcs_len = 0;

    for (size_t i = 1; i <= A.size(); ++i) {
        for (size_t j = 1; j <= B.size(); ++j) {
            if (A[i-1] == B[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }

            if (lcs[i][j] > lcs_len) lcs_len = lcs[i][j];
        }
    }

    for (size_t i = 0; i <= A.size(); ++i) {
        for (size_t j = 0; j <= B.size(); ++j) {
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }

    cout << lcs_len << endl;

    return 0;
}