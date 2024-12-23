#include <iostream>
#define Max 10
using namespace std;

template <typename type> class Queue {
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
        if (r != Max-1)
            return false;
        cout << "\nQueue is Full";
        return true;
    }

    void enqueue() {
        if(r == Max-1) {
            cout << "Insertion from Rear is not available";
            return;
        }
        cout << "\nEnter the value you want to enqueue: ";
        type a;
        cin >> a;
        if (r == -1) 
        {    r++; f++; arr[r] = a;  }
        else 
        {    r++; arr[r] = a;   }
    }

    void dequeueFromFront() {
        if(isEmpty())
            return;
        cout << endl << arr[f] << " is dequeue\n";
        f++;
        if (f > r)
            f = r = -1;
    } 

    void dequeueFromRear() {
        if(isEmpty())
            return;
        cout << endl << arr[r] << " is dequeue\n";
        r--;
        if (f > r)
            f = r = -1;
    } 

    void peek() {
        if (isEmpty())
            return;
        cout << "\nFront of Queue: " << arr[f] << endl;
    }

    void traverse() {
        if (isEmpty()) 
            return;
        cout << "\nElements in queue are: \n";
        for (int i = f; i <= r; i++)
            cout << arr[i] << endl;
    }
};

int main() {
    short int flag = 1;
    Queue<int> q;

    do {
        system("cls");
        cout << "Queue Menu\n";
        invalid:cout << "\nEnter Corresponding to execute functions:\n1 to Enqueue\n2 to Dequeue\n3 to Peek\n4 to Traverse\n0 to Exit\nEnter: ";
        cin >> flag;

        switch(flag) {
            case 1: q.enqueue(); break;
            case 2: 
                Dequeue:
                cout << "\n\nEnter Corresponding to execute functions:\n1 to Dequeue from front\n2 to Dequeue from Rear\n3 to skip\nEnter: ";
                cin >> flag;
                switch (flag) {
                    case 1: q.dequeueFromFront(); break;
                    case 2: q.dequeueFromRear(); break;
                    case 3: break;
                    default: 
                        cout << "\n\nInvalid Input"; 
                        goto Dequeue;
                }
                break;
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