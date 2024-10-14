#include <iostream>
using namespace std;

int findFactorial(int num) {
    if (num == 0){
        return 1;
    }
    int fact = 1;
    for (int i = 2; i <= num; i++){
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    cout << "Enter a number for factorial: ";
    cin >> num;
    cout << "factorial is: " << findFactorial(num);
    return 0;
}