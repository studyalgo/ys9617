#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LIS O(N^2)
void LIS1(vector<pair<int, int>> &AB, vector<int> &L) {
    for (int i = 0; i < L.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (AB[j].second < AB[i].second && L[i] < L[j] + 1) {
                L[i] = L[j] + 1;
            }
        }
    }
}

// LIS O(Nlg(N)), binary search
void LIS2(vector<pair<int, int>> &AB, vector<int> &L) {
    vector<int> L2 = { -1 };

    for (int i = 0; i < AB.size(); ++i) {
        int v = AB[i].second;

        if (L2.back() < v) {
            L2.push_back(v);
        }
        else {
            *lower_bound(begin(L2), end(L2), v) = v;
        }
    }

    L = L2;
}


int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> AB(N);
    vector<int> L(N, 1);
    for (int i = 0; i < N; ++i) {
        cin >> AB[i].first >> AB[i].second;
    }

    sort(begin(AB), end(AB));

    // LIS1
    //LIS1(AB, L);
    //cout << N - *max_element(begin(L), end(L)) << "\n";

    // LIS2
    LIS2(AB, L);
    cout << N - (L.size()-1) << "\n";

    return 0;
}