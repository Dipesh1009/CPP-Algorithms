#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Fibonacci Series upto n\n";
    cout << "Enter Number (n): ";
    cin >> n;
    if (n > 0) {

        int num1 = 0, num2 = 1;
        int fib = num1 + num2;
        cout << "Series is: \n";
        cout << num1 << "\n" << num2 << "\n";
        while(fib <= n) {
            cout << fib << "\n";
            num1 = num2;
            num2 = fib;
            fib = num1 + num2;
        }
    
    }
    else {
        cout << "0\n";
    }
    cout << "End of Program";

    return 0;
}