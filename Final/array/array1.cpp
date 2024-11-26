#include <iostream>
using namespace std;

int main() {
    int arr[5];
    cout << "Enter array elements: \n";
    for (int &i : arr) {
        cout << "Element: ";
        cin >> i;
    }

    cout << "\nArray Elements: ";
    for(int i : arr) {
        cout << "\t" << i;
    }
    return 0;
}