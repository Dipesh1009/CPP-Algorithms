#include <iostream>
#define MAX 5
using namespace std;

class Stack {
    private:
    int st[MAX], top = -1;

    public:
    void push() {
        if (top == MAX -1){
            cout << "Stack is full";
            return;
        }
        int num;
        cout << "\nEnter value: ";
        cin >> num;
        top++;
        st[top] = num;
    }

    void pop () {
        if (top == -1){
            cout << "Stack is empty";
            return;
        }
        cout << st[top] << " is popped from stack";
        top--;
    }

    void peek () {
        if (top == -1) {
            cout << "Stack is empty";
            return;
        }
        cout << st[top];
    }

    void traverse () {
        if (top == -1) {
            cout << "Stack is empty";
            return;
        }
        cout << "Elements in Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << endl << st[i];
        }
    }

};

int main() {
    Stack st;
    int flag = -1;
    do {
        system("cls");
        cout << "Stack operations\n";
        cout << "Enter 1 for push\n2 for pop\n3 for peek\n4 for traverse\n0 to exit\nEnter your choice: ";
        cin >> flag;

        switch(flag) {
            case 1: 
                st.push();
                break;
            case 2: 
                st.pop();
                break;
            case 3: 
                st.peek();
                break;
            case 4: 
                st.traverse();
                break;
            case 0: 
                st.traverse();
                cout << "\nThanks for using stack";
                break;
            default:
                cout << "Invalid Input";
        }
        cout << "\nPress any key to continue";
        getchar();
        getchar();
        
    } while (flag != 0);
    return 0;
}