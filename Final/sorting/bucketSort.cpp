#include <iostream>
#include <cmath>
using namespace std;

int getMax(int arr[], int s) {
    int max = arr[0];
    for (int i = 1; i < s; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int s) {
    int maxDigit = log10(getMax(arr, s));
    int exp = 1, indx;
    int buckets[10][s], count[10];

    for (int i = 0; i <= maxDigit; i++) {
        fill(count, count+10, 0);
        for (int j = 0; j < s; j++) {
            indx = (arr[j] / exp) % 10;
            buckets[indx][count[indx]++] = arr[j];
        }
        indx = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < count[j]; k++) {
                arr[indx++] = buckets[j][k];
            }
        }
        exp *= 10;
    }

}

int main() {
    int arr[5] = {123, 32, 44, 623, 100};
    radixSort(arr, 5);
    cout << "\nSorted Array\n";
    for (int i : arr) {
        cout << i << endl;
    }
    return 0;
}