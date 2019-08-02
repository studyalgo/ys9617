#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b, c;
    cin >> n >> m;

    vector<int> vec(n);
    for (auto &v : vec) cin >> v;

    for (int i = 0; i < m; ++i){
        cin >> a >> b >> c;

        vector<int> vec2 = vec;
        sort(begin(vec2)+a-1, begin(vec2)+b);
        cout << vec2[a+c-2] << "\n";
    }

    return 0;
}