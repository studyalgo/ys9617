#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500], tmp[500][500], n, max_life;

int findMaxLife(int r, int c){
    int l1 = 1, l2 = 1, l3 = 1, l4 = 1;

    if (r+1 < n && arr[r+1][c] > arr[r][c]){
        if (tmp[r+1][c] != 0) l1 += tmp[r+1][c];
        else l1 += findMaxLife(r+1, c);
    }

    if (r-1 >= 0 && arr[r-1][c] > arr[r][c]){
        if (tmp[r-1][c] != 0) l2 += tmp[r-1][c];
        else l2 += findMaxLife(r-1, c);
    }

    if (c+1 < n && arr[r][c+1] > arr[r][c]){
        if (tmp[r][c+1] != 0) l3 += tmp[r][c+1];
        else l3 += findMaxLife(r, c+1);
    }

    if (c-1 >= 0 && arr[r][c-1] > arr[r][c]){
        if (tmp[r][c-1] != 0) l4 += tmp[r][c-1];
        else l4 += findMaxLife(r, c-1);
    }

    int t = max(max(l1, l2), max(l3, l4));

    if (t > tmp[r][c]) tmp[r][c] = t;
    max_life = max(max_life, t);

    return t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (tmp[i][j] == 0) findMaxLife(i, j);
        }
    }

    cout << max_life << endl;

    return 0;
}