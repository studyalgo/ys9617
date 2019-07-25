#include <iostream>
using namespace std;

int partition(int **arr, int l, int r){
    int pvt1 = arr[r][0], pvt2 = arr[r][1];
    int i = l-1;

    for (int j = l; j <= r-1; ++j){
        if (arr[j][1] < pvt2){
            swap(arr[++i], arr[j]);
        }
        else if (arr[j][1] == pvt2 && arr[j][0] <= pvt1){
            swap(arr[++i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int **arr, int l, int r){
    if (l < r){
        int pvt = partition(arr, l, r);

        quickSort(arr, l, pvt-1);
        quickSort(arr, pvt+1, r);
    }
}

int main() {
    int N;
    cin >> N;

    int **arr = new int*[N];
    for (int i = 0; i < N; ++i){
        arr[i] = new int[2];
    }

    for (int i = 0; i < N; ++i){
        cin >> arr[i][0] >> arr[i][1];
    }

    quickSort(arr, 0, N-1);

    for (int i = 0; i < N; ++i){
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    for (int i = 0; i < N; ++i){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}