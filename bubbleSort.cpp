#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

void bubbleSort(int *arr, int size) {
    for (int i = size-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    cout << "\nSorted Array\n";
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}