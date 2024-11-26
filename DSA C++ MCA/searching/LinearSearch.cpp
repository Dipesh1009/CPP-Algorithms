#include <iostream>
using namespace std;

int searchLinear(int *arr, int size) {
    int key;
    cout << "\nEnter Element you want to search in array: ";
    cin >> key;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int i = searchLinear(arr, sizeof(arr)/sizeof(int));
    if (i == -1) {
        cout << "\nkey not found";
    }
    else {
        cout << "\nkey found at " << i;
    }

    return 0;
}