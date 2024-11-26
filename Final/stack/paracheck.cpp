#include <iostream>
#include <string>
#include <cstdlib>
#define MAX 10
using namespace std;

void push(int &top, char *st) {
	if (top == MAX - 1) {
		cout << "Stack is full";
	}
	else {
		st[++top] = '(';
	}
}

void pop(int &top) {
	if (top == -1) {
		cout << "Stack is empty";
	} 
	else {
		--top;
	}
}

int findClosingPara(string str, int index) {
	if (str[index] != '(') {
		return -1;
	}
	char st[MAX];
	int top = -1;
	
	for (int i = index; i < str.length(); i++) {
		if (str[i] == '(') {
			push(top,st);
		}
		else if (str[i] == ')'){
			pop(top);
			if (top == -1) {
				return i;
			}
		}
	} 
	return -2;
}
int main() {
    system("cls");
	string str;
	int index;
	
	cout << "Enter a string :\n";
	getline(cin, str);
	label:
	cout << "Enter index of concerned paranthesis: ";
    cin >> index;
    int check = findClosingPara(str,index);
    if (check == -1) {
        cout << "No paranthesis at given index, enter correct paranthesis\n";
        goto label;
    }
    else if (check == -2) {
        cout << "No closing paranthesis of corresponding parantheis is found";
    }
    else {
        cout << "Closing paranthesis at: " << check;
    }
	return 0;
}
