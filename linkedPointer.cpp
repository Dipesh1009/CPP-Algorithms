#include <iostream> 
using namespace std;

struct Node {
    int data;
    struct Node *next = nullptr;

    friend ostream& operator << (ostream& os, const struct Node &node){
        os << endl << node.data;
        return os;
    }
};

bool getMemory(struct Node *&avail){
    avail = (struct Node*) malloc(sizeof(struct Node));
    if (avail == nullptr) {
        std::cout << "Memory Overflow";
        return false;
    }
    avail->next = nullptr;
    return true;
}

void insertFirstNode(int data, struct Node *&start, struct Node *&avail, struct Node *&newnode) {
    newnode = avail;
    avail = avail->next;
    newnode->data = data;
    start = newnode;
    return;
}

void insertLast(int data, struct Node *&start, struct Node *&avail) { 
    if (!getMemory(avail))
        return;
    struct Node *newnode;
    if (start == nullptr) {
        insertFirstNode(data,start,avail,newnode);
    }
    else {
        newnode = avail;
        avail = newnode->next;
        newnode->data = data;
        struct Node *p = start;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = newnode;
    }
    
}

void insertFirst(int data, struct Node *&start, struct Node *&avail) {
    if (!getMemory(avail))
        return;
    struct Node *newnode;
    if (start == nullptr) {
        insertFirstNode(data,start,avail,newnode);
    }
    else {
        newnode = avail;
        avail = newnode->next;
        newnode->data = data;
        newnode->next = start;
        start = newnode;
    }    
}

void insertAfterDesired(int data, int position, struct Node *&start, struct Node *&avail) {
    if (start == nullptr) {
        cout << "List is empty";
        return;
    }
    struct Node *p = start;
    while (p->data != position) {
        if (p->next == nullptr){
            cout << "No Element found";
            return;
        }
        p = p->next;
    }
    if (!getMemory(avail))
    {    return;    }
    struct Node *newnode = avail;
    avail = newnode->next;
    newnode->data = data;
    newnode->next = p->next;
    p->next = newnode;          
}

void insertBeforeDesired(int data, int position, struct Node *&start, struct Node *&avail) {
    if (start == nullptr) {
        cout << "List is empty";
        return;
    }
    if (position == start->data) {
        insertFirst(data, start, avail);  return;
    }
    struct Node  *p2 = start, *p1 = start;
    while (p1->data != position) {
        if (p1->next == nullptr){
            cout << "No Element found";
            return;
        }
        p2 = p1;
        p1 = p1->next;
    }
    if (!getMemory(avail))
    {    return;    }
    struct Node *newnode = avail;
    avail = newnode->next;
    newnode->data = data;
    newnode->next = p1;
    p2->next = newnode;          
}


void deleteFirst(struct Node *&start) {
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    struct Node *p = start;
    start = start->next;
    cout << "\nNode deleted: " << *p;
    free(p);
}

void deleteLast(struct Node *&start) {
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    struct Node *p1 = start;
    if (p1->next == nullptr) {
        start = nullptr;
    }
    else {  
        struct Node *p2;
        while (p1->next != nullptr) {
            p2 = p1;
            p1 = p1->next;
        }

        p2->next = start;
    }
    cout << "\nNode deleted: " << *p1;
    free(p1);

}

void deleteDesired(int pos, struct Node *&start) {
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    if (pos == start->data) {
        deleteFirst(start); return;
    }
    struct Node  *p2 = start, *p1 = start;
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
    return;
}

void deleteBeforeDesired(int pos, struct Node *&start) {
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    if (pos == start->data) {
        cout << "\nNo node attached before given node\n";
        return;
    }

    if (pos == start->next->data) {
        deleteFirst(start); return;
    }

    struct Node *p1 = start, *p2 = start;
    while (p1->next->data != pos) {
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
    return;
}

void deleteAfterDesired(int pos, struct Node *&start) {
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    struct Node *p1 = start;
    while (p1->data != pos) {
        if (p1->next == nullptr){
            cout << "No Element found";
            return;
        }
        p1 = p1->next;
    }
    if (p1 -> next == start) {
        cout << "\nNo node available next to given node";
        return;
    }
    struct Node *p2 = p1->next;
    p1->next = p2->next;
    cout << "\nNode deleted: " << *p2;
    free(p2);
    return;
}

void traverse(struct Node *&start){
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    struct Node *p = start;
    while (p != nullptr){
        cout << *p;
        p = p->next;
    }
}

int main () {
    struct Node  *start = nullptr, *avail = nullptr, *newnode = nullptr;
    short int flag = 1;

    do {
        system("cls");
        cout << "Linked List Menu\n";

        invalid:
        cout << "\nEnter corresponding to execute functions: \n1 to Insert at last\n2 to Insert from Front\n3 to Insert after Desired position\n4 to Insert before Desired Position\n5 to Delete First Element\n6 to Delete Last Element\n7 to Delete at Desired Element\n8 to Delete Before Desired Position\n9 to Delete After Desired Position\n10 to traverse\n0 to Exit\nEnter: ";
        cin >> flag;
        int data,pos;
        cout << endl;


        switch (flag) {
            case 1:
                cout << "\nEnter Data Value: ";
                cin >> data;
                insertLast(data,start,avail);
                break;

            case 2:
                cout << "\nEnter Data Value: ";
                cin >> data; 
                insertFirst(data,start,avail);
                break;

            case 3: 
                cout << "\nEnter Data Value: ";
                cin >> data;
                cout << "\nEnter Data Value of position: ";
                cin >> pos;
                insertAfterDesired(data,pos,start,avail);
                break;

            case 4:
                cout << "\nEnter Data Value: ";
                cin >> data;
                cout << "\nEnter Data Value of position: ";
                cin >> pos; 
                insertBeforeDesired(data,pos,start,avail);
                break;

            case 5:
                deleteFirst(start);
                break;

            case 6: 
                deleteLast(start);
                break;

            case 7:
                cout << "\nEnter Data Value of Position: ";
                cin >> pos;
                deleteDesired(pos, start);
                break;

            case 8:
                cout << "\nEnter Data Value of Position: ";
                cin >> pos;
                deleteBeforeDesired(pos,start);
                break;

            case 9:
                cout << "\nEnter Data Value of Position: ";
                cin >> pos;
                deleteAfterDesired(pos,start);
                break;

            case 10: 
                traverse(start);
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