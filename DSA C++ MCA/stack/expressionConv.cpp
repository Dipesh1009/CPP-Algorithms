#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence (char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

string reverseString(const string &exp) {
    string reverse;
    int l = exp.length() - 1;
    for (int i = l; i >= 0; i--) {
        if (exp[i] == '(') 
            reverse += ')';
        else if (exp[i] == ')') 
            reverse += '(';
        else
            reverse += exp[i];
    }
    return reverse;
}

string infixToPostfix(const string &infix) {
    stack<char> op;
    string postfix;

    for (char ch: infix) {
        
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            op.push('(');
        }
        else if ( ch == ')') {
            while (!op.empty() && op.top() != '(') {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else {
            while (!op.empty() && precedence(op.top()) >= precedence(ch)){
                postfix += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }
    while (!op.empty()) {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}

string postfixForPrefix(const string &infix) {
    stack<char> op;
    string postfix;

    for (char ch: infix) {
        
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            op.push('(');
        }
        else if ( ch == ')') {
            while (!op.empty() && op.top() != '(') {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else {
            while (!op.empty() && precedence(op.top()) > precedence(ch)){
                postfix += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }
    while (!op.empty()) {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}


string infixToPrefix(const string &infix) {
    string prefix = reverseString(infix);
    prefix = postfixForPrefix(prefix);
    return reverseString(prefix);
}

int main() {
    bool flag;
    int c;
    do {
        system("cls");
        cout << "Convert expression\n\n1 for Converting\n0 for Exiting\n\nEnter your Choice: ";
        cin >> flag;
        if (flag) {
            system ("cls");
            string exp;
            getchar();
            cout << "Enter your expression for evaluation\n\n";
            cout << "Expression: ";
            getline(cin,exp);

            choice:
            cout << "Choose the Conversion:\n\n1 for Infix to Prefix\n2 for Infix to Postfix\nEnter here (1/2): ";
            cin >> c;
            switch (c) {
                case 1:
                    cout << "Prefix of Given Expression: " << infixToPrefix(exp);
                    break;
                case 2:
                    cout << "Postfix of Given Expression: " << infixToPostfix(exp);
                    break;
                default: 
                    cout << "Invalid Input\n\nPress any key to continue";
                    getchar();
                    getchar();
                    goto choice;
            }
            getchar();
            getchar();
        }
        else {
            cout << "Thanks for using";
        }
    } while (flag);
    return 0;
}