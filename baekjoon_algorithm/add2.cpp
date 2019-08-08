#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string str = "", tmp;
    while (getline(cin, tmp)) str += tmp;

    size_t sum = 0, i, j;
    for (i = 0, j = 0; i < str.size(); ++i) {
        if (str[i] == ',') {
            sum += stoi(str.substr(j, i-j));
            j = i+1;
        }
    }

    sum += stoi(str.substr(j, i-j));
    cout << sum << "\n";

    return 0;
}