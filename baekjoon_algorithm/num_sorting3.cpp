#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, a;
    cin >> N;

    int arr[10001] = { 0 };
    for (int i = 0; i < N; ++i){
        cin >> a;
        arr[a]++;
    }

    for (int i = 1; i <= 10000; ++i){
        if (arr[i] != 0){
            for (int j = 0; j < arr[i]; ++j){
                cout << i << "\n";
            }
        }
    }

    return 0;
}