#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a; a = b; b = temp;
    return;
}

void selectionSort(int arr[], int size) {
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i; j < size; j++){
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
    return;
}

int main () {
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(arr, 10);
    for (int i : arr) {
        cout << i << "\t";
    }
    return 0;
}