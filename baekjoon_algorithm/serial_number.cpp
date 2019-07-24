#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    
    vector<string> serial(N);
    for (auto &s : serial) cin >> s;

    sort(begin(serial), end(serial), [N](const string a, const string b){
        size_t a_len = a.length(), b_len = b.length();
        
        if (a_len == b_len){
            int sum_a = 0, sum_b = 0;
            for (int i = 0; i < a_len; ++i){
                if (a[i] >= '0' && a[i] <= '9') sum_a += a[i] - '0';
                if (b[i] >= '0' && b[i] <= '9') sum_b += b[i] - '0';
            }

            if (sum_a != sum_b) return (sum_a < sum_b);
        }
        else {
            return (a_len < b_len);
        }
        
        return (a < b);
    });
    
    for (auto s : serial) cout << s << "\n";

    return 0;
}