#include <iostream>
using namespace std;

int main() {
	int r,c;
	cout << "Enter no. of rows: ";
	cin >> r;
	cout << "Enter no. of columns: ";
	cin >> c;
	int arr[r][c];
	cout << "\nEnter elements of array:\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << "Enter element: ";
			cin >> arr[i][j];
		}
	}
	cout << "\n\nElements of array are: \n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}

	int transpose[c][r];
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			transpose[i][j] = arr[j][i];
		}
	}
	cout << "\n Transposed matrix:\n";
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			cout << transpose[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}