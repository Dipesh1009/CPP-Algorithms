#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    a = a+b;
    b = a-b;
    a = a-b;
    return;
}

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
            }
            else {
                break;
            }
        }
    }
    return;
}

int main () {
    int arr[10] = {10,2,4,7,3,1,5,8,6,9};
    insertionSort(arr, 10);
    for (int i : arr) {
        cout << i << "\t";
    }
    return 0;
}