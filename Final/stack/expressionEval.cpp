#include <iostream>
#include <stack>
#include <string>
using namespace std;

int isNumber(const string& exp, int& i){
    string numS;
    if(isdigit(exp[i])) {
        while (isdigit(exp[i])){
            numS += exp[i];
            i++;
        }
        i--;
        return stoi(numS);
    }
    return -1;
}

char isOperator(const string& exp, int& i) {
    if (exp[i] == '+' || exp[i] == '-'|| exp[i] == '*' || exp[i] == '/' || exp[i] == '(' || exp[i] == ')') {
        return exp[i];
    }
    return '\0';
}

int precedence (char op) {
    switch(op) {
        case '-':
            return 1;
        case '+':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        default:
            return 0;
    }
}

int calculateExp(stack<int> &operand,stack<char> &opStack) {
    int a, b, result;
    
    b = operand.top(); operand.pop();
    a = operand.top(); operand.pop();

    if (opStack.top() == ')') {
        opStack.pop();
    }
    char op = opStack.top(); opStack.pop();

    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    
    default:
        cout << "\n\nCalculation failed\n\n";
        return INT_MIN;
    }
    
    return result;
}

int evaluateExp(const string &exp) {
    stack<char> op;
    stack<int> operand;
    char opbuffer;
    int buffer;
    op.push('(');
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') {
            continue;
        }
        buffer = isNumber(exp, i);
        if (buffer == -1) {
            opbuffer = isOperator(exp,i);

            if(opbuffer == '\0') {
                cout << "\n\nExpression is not suitable\n\n";
                return -1;
            }
            else if (opbuffer == ')') {
                 
                while (op.top() != '(') {
                    buffer = calculateExp(operand, op);
                    if (buffer != INT_MIN) {
                        operand.push(buffer);
                    }
                    else {
                        cout << "Something went wrong!";
                        return -1;
                    }
                } 
                
                if (!op.empty() && op.top() == '(') {
                    op.pop();
                }
                
                if (isdigit(exp[i+1])) {
                    op.push('*');
                }
                continue;
            }
            else if (opbuffer == '(') {
                if (isdigit(exp[i-1])){
                    op.push('*');
                }
                op.push(opbuffer);
            }
            else {
                while ( !op.empty() && precedence(op.top()) >= precedence (opbuffer))
                {
                        buffer = calculateExp(operand, op);
                        if (buffer != INT_MIN) {
                            operand.push(buffer);
                        }
                        else {
                            cout << "Something went wrong!";
                            return -1;
                        }                
                }
                op.push(opbuffer);
            }
        }
        else {
            operand.push(buffer);
        }
    }
    return operand.top();
}

int main() {
    bool flag;
    do {
        system("cls");
        cout << "Evaluate expression\n\n1 for calculating\n0 for exiting\n\nEnter your Choice: ";
        cin >> flag;
        if (flag) {
            system ("cls");
            string exp;
            getchar();
            cout << "Enter your expression for evaluation\n\n";
            cout << "Expression: ";
            getline(cin,exp);
            exp += ')';
            int result = evaluateExp(exp);
            cout << "Result is: " << result;
            cout << "\n\nPress any key to continue";
            getchar();
        }
        else {
            cout << "Thanks for using";
        }
    } while (flag);

    return 0;
}