#include <iostream>
#include <stack>
using namespace std;

bool checkPara(string str) {
    stack<char> para;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            para.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (para.empty()) {
                return false;
            }
            if (str[i] == ')' && para.top() != '(' ) {
                return false;
            }
            if (str[i] == '}' && para.top() != '{' ) {
                return false;
            }
            if (str[i] == ']' && para.top() != '[' ) {
                return false;
            }
            para.pop();
            
        }
    }
    if (!para.empty()) {
        return false;
    }
    return true;
}

int main() {
    string str;
    cout << "Enter: ";
    getline (cin, str);

    if (checkPara(str)) {
        cout << "String is correct;";
    }
    else {
        cout << "String is wrong paranthesis sequence;";
    }
    return 0;
}