#include <iostream>
using namespace std;

// reverse stack algo to print 0 -> a, 1 -> b, 12 -> bc

void convertNumAlpha(int num, string &str) {
    if (num <= 9) {
        str += (char)(65+num);
        return;
    }
    convertNumAlpha(num/10,str);
    str += (char)(num%10 + 65);

}

int main() {
    int a;
    cin >> a;
    string str;
    convertNumAlpha(a,str);
    cout << str;
    return 0;
}