#include <iostream>
#define MAX 10
using namespace std;

int main() {
    int arr[MAX];
    cout << "Enter array elements: \n";
    for (int i = 0; i < 5; i++) {
        cout << "Element: ";
        cin >> arr[i];
    }

    cout << "\nArray Elements: ";
    for(int i : arr) {
        cout << "\t" << i;
    }
    return 0;
}