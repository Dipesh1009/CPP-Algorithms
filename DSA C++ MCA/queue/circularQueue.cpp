#include <iostream>
#define Max 5
using namespace std;

template <typename type> class circularQueue {
    private:
    type arr[Max];
    int f = -1, r = -1;

    public:
    bool isEmpty() {
        if (r != -1)
            return false;
        cout << "\nQueue is empty\n";
        return true;
    }

    bool isFull() {
        if((r == Max-1 && f == 0) || r == f-1){
            cout << "\nQueue is Full\n";
            return true;  
        }
        return false;
    }

    void enqueue() {
        if (isFull())
            return;
        cout << "\nEnter the value you want to enqueue: ";
        type a;
        cin >> a;
        
        if (r == Max-1 && f != 0)
        {    r = 0; arr[r] = a; }
        else if (r == -1) 
        {    r++; f++; arr[r] = a;  }
        else 
        {    r++; arr[r] = a;   }
    }

    void dequeue() {
        if (isEmpty()) 
            return;
        
        if (f == Max -1 && r < f) {
            cout << endl << arr[f] << " is dequeued\n";
            f = 0; return;
        }
        cout << endl << arr[f] << " is dequeued\n";
        if (f == r)
            f = r = -1;
        else 
            f++;
    }

    void peek() {
        if (isEmpty())
            return;
        cout << "\nFront of Queue: " << arr[f] << endl;
    }

    void traverse () {
        if(isEmpty())
            return;
        cout << "\nElements in queue are: \n";
        if (r<f) {
            for (int i = f; i < Max; i++) 
            {    cout << arr[i] << endl;    }
            for (int i = 0; i <= r; i++)
            {    cout << arr[i] << endl;    }
        }
        else {
            for (int i = f; i <= r; i++)
                cout << arr[i] << endl;
        }
    }
};

int main() {
    short int flag = 1;
    circularQueue<int> q;

    do {
        system("cls");
        cout << "\nQueue Menu\n";
        invalid:cout << "\nEnter Corresponding to execute functions:\n1 to Enqueue\n2 to Dequeue\n3 to Peek\n4 to Traverse\n0 to Exit\nEnter: ";
        cin >> flag;

        switch(flag) {
            case 1: q.enqueue(); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.traverse(); break;
            case 0:
                cout << "\nThanks for using Queue\n";
                break;
            default: 
                cout << "\n\nInvalid Input"; 
                goto invalid;
        }
        cout << "\nEnter any key to continue";
        getchar(); getchar();
    } while( flag != 0 );
    return 0;
}