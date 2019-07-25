#include <iostream>
using namespace std;

void printArr(int arr[], int n){
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i){
        for (int j = 0; j < n-i-1; ++j){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    for (int i = n; i > 0; --i){
        int max_idx = 0;
        for (int j = 1; j < i; ++j){
            if (arr[max_idx] < arr[j]) max_idx = j;
        }

        int tmp = arr[max_idx];
        arr[max_idx] = arr[i-1];
        arr[i-1] = tmp;
    }
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; ++i){
        int j, tmp = arr[i];
        for (j = i; j > 0 && arr[j-1] > tmp; --j) arr[j] = arr[j-1];
        
        arr[j] = tmp;
    }
}

void merge(int arr[], int l, int m, int r){
    int i = l, j = m+1, k = 0;
    int *tmp = new int[r-l+1];

    while (i <= m && j <= r){
        if (arr[i] < arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while(i <= m) tmp[k++] = arr[i++];
    while(j <= r) tmp[k++] = arr[j++];

    for (int i = 0; i < r-l+1; ++i) arr[l+i] = tmp[i];

    delete[] tmp;
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int r){
    int pvt = arr[r];
    int i = l-1;

    for (int j = l; j <= r-1; ++j){
        if (arr[j] <= pvt){
            swap(arr[++i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if (l < r){
        int pvt = partition(arr, l, r);

        quickSort(arr, l, pvt-1);
        quickSort(arr, pvt+1, r);
    }
}


int main() {
    int arr[] = { 0, 4, 3, 5, 7, 8, 9, 1, 2, 6 };

    quickSort(arr, 0, 9);

    printArr(arr, 10);

    return 0;
}