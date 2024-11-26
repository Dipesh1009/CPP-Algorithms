#include <iostream>
using namespace std;

void swap(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
    return;
}

int divide(int arr[], int l, int r) {

    int pivot = arr[l], i = r+1;
    for (int j = r; j > l; j--) {
        if (arr[j] > pivot){
            i--;    
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i-1], arr[l]);
    return i-1;
    
}

void quickSort(int arr[], int l, int r) {

    if (l < r) {

        int pi = divide(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }

    return;
}


int main() {
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    quickSort(arr, 0, 9);
    cout << "\nSorted Array\n";
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}