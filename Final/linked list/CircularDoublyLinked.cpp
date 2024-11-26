#include <iostream> 
using namespace std;

template <typename type> struct Node {
    type data;
    struct Node <type> *next = nullptr, *pre = nullptr;

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
        
        void insertFirstNode(type data) {
            newnode = avail;
            avail = avail->next;
            newnode->data = data;
            newnode->next = start;
            start = newnode;
            start->pre = newnode;
            return;
        }
        void insertAtLast(type data) {
            if (!getMemory())
                return;
            
            if (start == nullptr) {
                insertFirstNode(data);
            }
            else {
                newnode = avail;
                avail = newnode->next;
                newnode->data = data;
                newnode->next = start;
                newnode->pre = start->pre;
                start->pre->next = newnode;
                start->pre = newnode;
            }
            return;
        }

        void insertAtFirst(type data) {
            if (!getMemory())
                return;
            
            if (start == nullptr) {
                insertFirstNode(data);
            }
            else {
                newnode = avail;
                avail = newnode->next;
                newnode->data = data;
                newnode->next = start;
                newnode->pre = start->pre;
                start->pre->next = newnode;
                start->pre = newnode;
                start = newnode;
            }
            return;
        }

        void insertAfterDesired(type data, type position) {
            if (start == nullptr) {
                cout << "List is empty";
                return;
            }
            struct Node <type>* p = start;
            while (p->data != position) {
                if (p->next == start){
                    cout << "No Element found";
                    return;
                }
                p = p->next;
            }
            if (p->next == start) {
                insertAtLast(data); return;
            }
            if (!getMemory())
            {    return;    }
            newnode = avail;
            avail = newnode->next;
            newnode->data = data;
            newnode->next = p->next;
            p->next->pre = newnode;
            newnode->pre = p;
            p->next = newnode;         
            return; 
        }

        void insertBeforeDesired(type data, type position) {
            if (start == nullptr) {
                cout << "List is empty";
                return;
            }
            if (position == start->data) {
                insertAtFirst(data);  return;
            }
            struct Node <type>* p = start;
            while (p->data != position) {
                if (p->next == start){
                    cout << "No Element found";
                    return;
                }
                p = p->next;
            }
            if (p->pre == start) {
                insertAtFirst(data); return;
            }
            if (!getMemory())
            {    return;    }
            newnode = avail;
            avail = newnode->next;
            newnode->data = data;
            newnode->next = p;
            newnode->pre = p->pre;
            p->pre->next = newnode;
            p->pre = newnode;      
            return;
        }

        void deleteFirst() {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }
            struct Node <type>* p = start;
            if (p->next == start) {
                start = nullptr;
            }
            else {
                start = p->next;
                start->pre = p->pre;
                start->pre->next = start;
            }
            cout << "\nNode deleted: " << *p;
            free(p);
            return;
        }

        void deleteLast() {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type> *p = start->pre;

            if (start->pre == start) {
                start == nullptr;
            }
            else {
                p->pre->next = start;
                start->pre = p->pre;
            }

            cout << "\nNode deleted: " << *p;
            free(p);
            return;    
        }

        void deleteBeforeDesired(type pos) {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            if (pos == start->data) {
                if (start->pre == start){
                    cout << "\nNo node attached before given node\n";
                    return;
                }
            }
            if (pos == start->next->data) {
                deleteFirst(); return;
            }
            struct Node <type> *p1 = start;
            while (p1->data != pos) {
                if (p1->next == start){
                    cout << "No Element found";
                    return;
                }
                p1 = p1->next;
            }
            p1 = p1->pre;
            p1->next->pre = p1->pre;
            p1->pre->next = p1->next;
            cout << "\nNode deleted: " << *p1;
            free(p1);
            return;
        }

        void deleteAfterDesired(type pos) {
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type> *p1 = start;
            while (p1->data != pos) {
                if (p1->next == start){
                    cout << "No Element found";
                    return;
                }
                p1 = p1->next;
            }
            if (p1 -> next == start) {
                if (p1 == start) {
                    cout << "\nNo node attached before given node\n"; return;
                }
                deleteFirst();
                return;
            }
            // if (p1->next->next == start) {
            //     deleteLast(); return;
            // }
            p1 = p1->next;
            p1->next->pre = p1->pre;
            p1->pre->next = p1->next;
            cout << "\nNode deleted: " << *p1;
            free(p1);
            return;
        }

        void traverse(){
            if (start == nullptr) {
                cout << "list is empty";
                return;
            }

            struct Node <type>* p = start;
            do{
                cout << *p;
                p = p->next;
            }while (p != start);
            return;
        }
};

int main () {
    LinkedList <int> ll;
    short int flag = 1;

    do {
        system("cls");
        cout << "Linked List Menu\n";

        invalid:
        cout << "\nEnter corresponding to execute functions: \n1 to Insert at last\n2 to Insert from Front\n3 to Insert after Desired position\n4 to Insert before Desired Position\n5 to Delete First Element\n6 to Delete Last Element\n7 to Delete Before Desired Position\n8 to Delete After Desired Position\n9 to traverse\n0 to Exit\nEnter: ";

        cin >> flag;
        int data,pos;
        cout << endl;


        switch (flag) {
            case 1:
                cout << "\nEnter Data Value: ";
                cin >> data;
                ll.insertAtLast(data);
                break;

            case 2:
                cout << "\nEnter Data Value: ";
                cin >> data; 
                ll.insertAtFirst(data);
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
                ll.deleteBeforeDesired(pos);
                break;

            case 8:
                cout << "\nEnter Data Value of Position: ";
                cin >> pos;
                ll.deleteAfterDesired(pos);
                break;

            case 9: 
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