#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n;

    string result = "";
    result.reserve(2*n);
    vector<int> vec(n); stack<int> tmp;
    for (auto &v : vec) cin >> v;

    for (k = 1; k <= vec[0]; ++k) {
        tmp.push(k);
        result += '+';
    }

    for (int i = 0; i < n; ++i){
        if (!tmp.empty() && vec[i] == tmp.top()){
            tmp.pop();
            result += '-';
        }
        else if (tmp.empty() || vec[i] > tmp.top()){
            while(k < vec[i]){
                tmp.push(k++);
                result += '+';
            }

            k++;
            result += "+-";
        }
        else {
            result = "NO";
            break;
        }
    }

    if (result == "NO") cout << result << "\n";
    else for (auto r : result) cout << r << "\n";

    return 0;
}