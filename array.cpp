#include <iostream>
using namespace std;

int main() {
    int array[10];

    for (int i = 1; i <= 10; i++) {
        cout << "Enter no: ";
        cin >> array[i];
        cout << endl;

    }

    cout << endl << array[10] << endl;
    int j = array[10];

    for (int i = 1; i <= 10; i++) {
        cout << "\t" << array[i];
    }

    cout << endl << j;
    cout << endl << array[10];
    cout << endl << array[0];

    return 0;
}