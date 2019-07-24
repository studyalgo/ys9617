#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str;
    cin >> str;

    sort(begin(str), end(str), greater<char>());

    cout << str << "\n";

    return 0;
}