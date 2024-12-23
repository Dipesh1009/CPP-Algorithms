#include <iostream>
using namespace std;

void shellSort(int arr[], int size) {
    int temp, j;
    for (int diff = size/2; diff > 0; diff /= 2) {
        for (int i = diff; i < size; i++) {
            temp = arr[i];
            for (j = i ; j >= diff && arr[j - diff] > temp; j -= diff)
                arr[j] = arr[j-diff];
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[10] = {10,2,4,7,3,1,5,8,6,9};
    shellSort(arr, 10);
    for (int i : arr) {
        cout << i << "\t";
    }
    return 0;
}