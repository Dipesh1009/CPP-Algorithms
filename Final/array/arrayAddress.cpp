#include <iostream>
using namespace std;

int main() {
    int arr[10],i;
    cout << "Enter array elements: \n";
    for (int &i : arr) {
        cout << "Element: ";
        cin >> i;
    }

    cout << "\nArray Elements: ";
    for(int i : arr) {
        cout << "\t" << i;
    }
    
    cout << "\n\nEnter the Index to find address: ";
    cin >> i;
    int *p = &arr[0];
    int *add = p+i;

    cout << "Address of given index: " << add << endl;
    cout << "Value at the address: " << *add;

    return 0;
}