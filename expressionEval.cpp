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

void pushOperand(int op, int& top, int *operand)
{
    if (top == 9) {
        cout << "Operand stack is full\n";
        return;
    }
    top++;
    operand[top] = op;
    return;
}

int popOperand (int& top, int *operand) {
    if (top == -1) {
        cout << "Stack is empty";
        return -1;
    }
    top--;
    return operand[top+1];
}

char popOperator (int& top, char *opStack) {
    if (top == -1) {
        cout << "Operator stack is empty";
        return '\0';
    }
    top--;
    return opStack[top+1];
}

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

int calculateExp(int *operand,char *opStack, int &topOperator, int &topOperand) {
    int a, b, result;
    b = popOperand(topOperand, operand);
    a = popOperand(topOperand, operand);
    if (opStack[topOperator] == ')') {
        popOperator(topOperator, opStack);
    }
    char op = popOperator(topOperator, opStack);

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
    char op[10], opbuffer;
    int operand[10], topOperator = -1, topOperand = -1, buffer;
    pushOperator('(',topOperator,op);
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
                 
                while (op[topOperator] != '(') {
                    buffer = calculateExp(operand, op, topOperator, topOperand);
                    if (buffer != INT_MIN) {
                        pushOperand(buffer, topOperand, operand);
                    }
                    else {
                        cout << "Something went wrong!";
                        return -1;
                    }
                } 
                
                if (topOperator != 0 && op[topOperator] == '(') {
                    popOperator(topOperator, op);
                }
                
                if (isdigit(exp[i+1])) {
                    pushOperator('*', topOperator, op);
                }
                continue;
            }
            else if (opbuffer == '(') {
                if (isdigit(exp[i-1])){
                    pushOperator('*', topOperator, op);
                }
                pushOperator(opbuffer, topOperator, op);
            }
            else {
                while ( topOperand != -1 && precedence(op[topOperand]) >= precedence (opbuffer))
                {
                        buffer = calculateExp(operand, op, topOperator, topOperand);
                        if (buffer != INT_MIN) {
                            pushOperand(buffer, topOperand, operand);
                        }
                        else {
                            cout << "Something went wrong!";
                            return -1;
                        }                
                }
                pushOperator(opbuffer, topOperator, op);
            }
        }
        else {
            pushOperand(buffer, topOperand, operand);
        }
    }
    return popOperand(topOperand, operand);
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