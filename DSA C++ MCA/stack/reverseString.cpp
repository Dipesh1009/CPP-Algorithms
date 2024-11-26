#include <iostream>
using namespace std;

string reverseString(string &str, int n) {
    if (str[n] == '\0') {
        return "";
    }
    return reverseString(str, n+1) + str[n];
}

int main() {
    string str = "Hi, I am Dipesh";
    string strR = reverseString(str,0);
    cout << strR;
    return 0;
}