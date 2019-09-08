#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, max = 0, max_idx;
    cin >> N;

    vector<pair<int, int>> AB(N), L = {{-1, -1}};
    vector<int> pos(N, -1), lis;

    for (auto &ab : AB) {
        cin >> ab.first >> ab.second;
    }

    sort(begin(AB), end(AB));

    for (int i = 0; i < N; ++i) {
        int v = AB[i].second;

        if (L.back().second < v) {
            pos[i] = L.back().first;
            L.push_back({i, v});
        }
        else {
            auto itr = 
            lower_bound(begin(L), end(L), make_pair(i, v), [](auto l1, auto l2){
                return l1.second < l2.second;
            });

            pos[i] = (itr-1)->first;
            *itr = {i, v};
        }
    }

    for (int i = L.back().first; i != -1; i = pos[i]) {
        AB[i].first = 500001;
    }

    sort(begin(AB), end(AB));

    int n_del = N - (L.size() - 1);
    
    cout << n_del << endl;
    
    for (int i = 0; i < n_del; ++i) cout << AB[i].first << "\n";

    return 0;
}