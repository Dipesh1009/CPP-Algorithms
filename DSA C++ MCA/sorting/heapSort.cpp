#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

void maxHeapify(int arr[], int i) {
    if (arr[i] <= arr[i/2]){
        return;
    }
    swap(arr[i],arr[i/2]);
    maxHeapify(arr,i/2);
    return;
}
void heapSort(int arr[], int size) {
    for (int n = size-1; n > 0; n--){
        for (int i = 0; i <= n; i++) {
            maxHeapify(arr,i);
        }
        swap(arr[0],arr[n]);
    }
    
}

int main () {
    int arr[10] = {10,2,4,7,3,1,5,8,6,9};
    heapSort(arr, 10);
    for (int i : arr) {
        cout << i << "\t";
    }
    return 0;
}