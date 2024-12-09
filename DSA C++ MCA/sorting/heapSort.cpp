#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

void check(int arr[], int i) {
    if (arr[i] >= arr[i/2]){
        return;
    }
    if (arr[i] < arr[i/2]){
        swap(arr[i],arr[i/2]);
        check(arr,i/2);
    }
    return;
}
void insertionSort(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        check(arr,i);
    }
    
}

int main () {
    int arr[10] = {10,2,4,7,3,1,5,8,6,9};
    insertionSort(arr, 10);
    for (int i : arr) {
        cout << i << "\t";
    }
    return 0;
}