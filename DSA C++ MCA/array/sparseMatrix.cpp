#include <iostream>
using namespace std;

int main() {
    int r,c;
    cout << "Enter no. of rows: ";
    cin >> r;
    cout << "Enter no. of columns: ";
    cin >> c;

    int arr[r][c], lim = 0;
    cout << "Enter array elements: \n";
    for (auto &row : arr) {
        for (auto &col : row){
            cout << "Element: ";
            cin >> col;
            if (col == 0) {
                lim++;
            }   
        }
    }

    cout << "\nArray Elements:\n";
    for (auto &row : arr) {
        for (auto &col : row){
            cout << "\t" << col;  
        }
        cout << endl;
    }

    if (lim > (r*c*(2/3))) {
        cout << "\nMatrix is Sparse";
    }
    else {
        cout << "\nMatrix is not sparse";
    }

    return 0;
}