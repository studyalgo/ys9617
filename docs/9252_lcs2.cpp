#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string A, B, LCS = "";
    cin >> A >> B;

    vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));

    for (size_t i = 1; i <= A.size(); ++i) {
        for (size_t j = 1; j <= B.size(); ++j) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for (int i = A.size(), j = B.size(); i > 0 && j > 0;) {
        if (dp[i][j] == dp[i][j-1]) j--;
        else if (dp[i][j] == dp[i-1][j]) i--;
        else {
            LCS = A[i-1] + LCS;
            i--;
            j--;
        }
    }

    cout << dp[A.size()][B.size()] << endl;
    cout << LCS << endl;

    return 0;
}