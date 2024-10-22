#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void pushOperator(char op, int& top, char *opStack)
{
    if (top == 9) {
        cout << "Operator Stack is full\n";
        return;
    }
    top++;
    opStack[top] = op;
    return;
}

char popOperator (int& top, char *opStack) {
    if (top == -1) {
        cout << "Operator stack is empty";
        return '\0';
    }
    top--;
    return opStack[top+1];
}

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
    char op[10];
    int top = -1;
    string postfix;

    for (char ch: infix) {
        
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            pushOperator (ch, top, op);
        }
        else if ( ch == ')') {
            while (top > -1 && op[top] != '(') {
                postfix += popOperator(top, op);
            }
            popOperator(top, op);
        }
        else {
            while (top > -1 && precedence(op[top]) > precedence(ch)){
                postfix += popOperator(top, op);
            }
            pushOperator(ch, top, op);
        }
    }
    while (top > -1) {
        postfix += popOperator(top,op);
    }

    return postfix;
}

string infixToPrefix(const string &infix) {
    string prefix = reverseString(infix);
    prefix = infixToPostfix(prefix);
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
                    cout << "Invalid Input";
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