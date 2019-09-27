#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int int_min = -1000000000;

template <typename T>
void LIS(vector<T>& A, vector<pair<int, int>>& L, vector<T>& lis) {
    vector<int> pos(A.size(), -1);
    
    for (size_t i = 0; i < A.size(); ++i) {
        if (L.back().second < A[i]) {
            pos[i] = L.back().first;
            L.push_back({i, A[i]});
        }
        else {
            auto itr = 
            lower_bound(begin(L), end(L), make_pair(i, A[i]), [](auto l1, auto l2){
                return l1.second < l2.second;
            });

            pos[i] = (itr-1)->first;
            *itr = {i, A[i]};
        }
    }

    for (int i = L.back().first; i != -1; i = pos[i]) {
        lis.push_back(A[i]);
    }
}

int main() {
    int N, max = 0, max_idx;
    cin >> N;

    vector<int> A(N), lis;
    vector<pair<int, int>> L = {{-1, int_min}};

    for (auto& a : A) {
        cin >> a;
    }

    LIS(A, L, lis);

    cout << L.size() - 1 << endl;

    for (auto l = rbegin(lis); l != rend(lis); ++l) {
        cout << *l << " ";
    }

    return 0;
}