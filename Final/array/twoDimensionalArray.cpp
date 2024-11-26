#include <iostream>
using namespace std;

int main() {
    int r,c;
    cout << "Enter no. of rows: ";
    cin >> r;
    cout << "Enter no. of columns: ";
    cin >> c;

    int arr[r][c];
    cout << "Enter array elements: \n";
    for (auto &row : arr) {
        for (auto &col : row){
            cout << "Element: ";
            cin >> col;   
        }
    }

    cout << "\nArray Elements:\n";
    for (auto &row : arr) {
        for (auto &col : row){
            cout << "\t" << col;  
        }
        cout << endl;
    }
    return 0;
}