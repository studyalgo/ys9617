#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (auto &v : vec){
        cin >> v.second >> v.first;
    }
    
    sort(begin(vec), end(vec));

    for (auto v : vec){
        cout << v.second << " " << v.first << "\n";
    }

    return 0;
}