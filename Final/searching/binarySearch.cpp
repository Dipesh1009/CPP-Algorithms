#include <iostream>
using namespace std;

int searchBinary(int *arr, int size){
    int key, mid, lb = 0, ub = size-1;

    cout << "\nEnter Element you want to search in array: ";
    cin >> key;

    do{
        mid = (lb + ub)/2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (key < arr[mid]) {
            ub = mid-1;
        }
        else if (key > arr[mid]) {
            lb = mid+1;
        }  
    }while (lb <= ub);
    return -1;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int i = searchBinary(arr, sizeof(arr)/sizeof(int));
    
    if (i == -1) {
        cout << "\nkey not found";
    }
    else {
        cout << "\nkey found at " << i;
    }

    return 0;
}