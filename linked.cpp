#include <iostream> 
using namespace std;

template <typename type> struct Node {
    type data;
    struct Node <type>* next = nullptr;

    friend ostream& operator << (ostream& os, const struct Node <type>& node){
        os << endl << node.data;
        return os;
    }
};

template <typename type> class LinkedList {
    private: 
        struct Node <type> *start = nullptr, *avail = nullptr, *newnode = nullptr;
        
    public:

        bool getMemory(){
            avail = (struct Node<int>*) malloc(sizeof(struct Node<int>));
            if (avail == nullptr) {
                cout << "Memory Overflow";
                return false;
            }
            avail->next = nullptr;
            return true;
        }
        
        void insertLast(type data) {
            if (!getMemory())
                return;
            
            if (start == nullptr) {
                newnode = avail;
                avail = avail->next;
                newnode->data = data;
                start = newnode;
            }
            else {
                newnode = avail;
                avail = newnode->next;
                newnode->data = data;
                struct Node <type>* p = start;
                while (p->next != nullptr) {
                    p = p->next;
                }
                p->next = newnode;
            }
            
        }

        void insertAfterDesired(type data, type position) {
            if (!getMemory())
                return;

            if (start == nullptr) {
                cout << "List is empty";
                return;
            }
                newnode = avail;
                avail = newnode->next;
                newnode->data = data;
                struct Node <type>* p = start;
                while (p->data != position) {
                    if (p->next == nullptr){
                        cout << "No Element found";
                        return;
                    }
                    p = p->next;
                }
                newnode->next = p->next;
                p->next = newnode;          
        }

        void insertBeforeDesired(type data, type position) {
            if (!getMemory())
                return;

            if (start == nullptr) {
                cout << "List is empty";
                return;
            }
                newnode = avail;
                avail = newnode->next;
                newnode->data = data;
                struct Node <type> *p2 = start, *p1 = start;
                while (p1->data != position) {
                    if (p1->next == nullptr){
                        cout << "No Element found";
                        return;
                    }
                    p2 = p1;
                    p1 = p1->next;
                }
                newnode->next = p1;
                p2->next = newnode;          
        }

        void insertFirst(type data) {
            if (!getMemory())
                return;
            
            if (start == nullptr) {
                newnode = avail;
                avail = avail->next;
                newnode->data = data;
                start = newnode;
            }
            else {
                newnode = avail;
                avail = newnode->next;
                newnode->data = data;
                newnode->next = start;
                start = newnode;
            }
            
        }

        void deleteFirst() {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type>* p = start;
            start = start->next;
            cout << "\nNode deleted: " << *p;
            free(p);
        }

        void deleteLast() {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type> *p1 = start, *p2 = start;
            while (p1->next != nullptr) {
                p2 = p1;
                p1 = p1->next;
            }

            p2->next = nullptr;
            cout << "\nNode deleted: " << *p1;
            free(p1);
        
        }

        void deleteDesired(type pos) {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type> *p2 = start, *p1 = start;
            while (p1->data != pos) {
                if (p1->next == nullptr){
                    cout << "No Element found";
                    return;
                }
                p2 = p1;
                p1 = p1->next;
            }
            p2->next = p1->next;
            cout << "\nNode deleted: " << *p1;
            free(p1);

        }

        void traverse(){
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type>* p = start;
            while (p != nullptr){
                cout << *p;
                p = p->next;
            }
        }
};

int main () {
    LinkedList <int> ll;
    short int flag = 1;

    do {
        system("cls");
        cout << "Linked List Menu\n";

        invalid:
        cout << "\nEnter corresponding to execute functions: \n1 to Insert at last\n2 to Insert from Front\n3 to Insert after Desired position\n4 to Insert before Desired Position\n5 to Delete First Element\n6 to Delete Last Element\n7 to Delete at Desired Element\n8 to traverse\n0 to Exit\nEnter: ";

        cin >> flag;
        int data,pos;
        cout << endl;


        switch (flag) {
            case 1:
                cout << "\nEnter Data Value: ";
                cin >> data;
                ll.insertLast(data);
                break;

            case 2:
                cout << "\nEnter Data Value: ";
                cin >> data; 
                ll.insertFirst(data);
                break;

            case 3: 
                cout << "\nEnter Data Value: ";
                cin >> data;
                cout << "\nEnter Data Value of position: ";
                cin >> pos;
                ll.insertAfterDesired(data,pos);
                break;

            case 4:
                cout << "\nEnter Data Value: ";
                cin >> data;
                cout << "\nEnter Data Value of position: ";
                cin >> pos; 
                ll.insertBeforeDesired(data,pos);
                break;

            case 5:
                ll.deleteFirst();
                break;

            case 6: 
                ll.deleteLast();
                break;

            case 7:
                cout << "\nEnter Data Value of Position: ";
                cin >> pos;
                ll.deleteDesired(pos);
                break;

            case 8: 
                ll.traverse();
                break;

            case 0:
                cout << "\nThanks for using Linked List\n";
                break;

            default:
                cout << "\n\nInvalid input";
                goto invalid;
        } 
        cout << "\nEnter any key to continue";
        getchar();
        getchar();
    } while (flag != 0);
    return 0;
}