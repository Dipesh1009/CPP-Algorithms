#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1], arr2[n2];
    
    for (int i = 0; i < n1; i++){
        arr1[i] = arr[l+i];
    }
    
    for (int i = 0; i < n2; i++){
        arr2[i] = arr[mid+1+i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr[k] = arr1[i]; 
            k++; 
            i++;
        }
        else {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n1) {
        arr[k] = arr1[i]; 
        k++; 
        i++;
    }
    while (j < n2) {
        arr[k] = arr2[j];
        k++;
        j++;
    }

}

void mergeSort(int arr[], int l, int r) {
    
    if (l<r) {
        int mid = (l+r) / 2;
        mergeSort(arr, mid+1, r);
        mergeSort(arr, l, mid);

        merge(arr, l, mid, r);
    }
    return;
}

int main() {
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    mergeSort(arr, 0, 9);
    cout << "\nSorted Array\n";
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}