#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, elm;
    cin >> N;

    string str;
    stack<int> stk;
    for (int i = 0; i < N; ++i){
        cin >> str;

        if (str == "push") {
            cin >> elm;
            stk.push(elm);
        }
        else if (str == "pop") {
            if (!stk.empty()) {
                cout << stk.top() << "\n";
                stk.pop();
            }
            else cout << -1 << "\n";
        }
        else if (str == "size") cout << stk.size() << "\n";
        else if (str == "empty") cout << stk.empty() << "\n";
        else if (str == "top") {
            if (!stk.empty()) cout << stk.top() << "\n";
            else cout << -1 << "\n";
        }
    }

    return 0;
}