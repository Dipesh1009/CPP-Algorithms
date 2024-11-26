#include <iostream> 
using namespace std;


struct Node {
    int data;
    struct Node *next;
};

bool getMemory(struct Node **avail){
    *avail = (struct Node*) malloc(sizeof(struct Node));
    if (*avail == nullptr) {
        cout << "Memory Overflow";
        return false;
    }
    (*avail) -> data;
    return true;
}

void insertLast(int data, struct Node **avail, struct Node **start, struct Node **newnode) {
    if (!getMemory(avail))
        return;
    
    if (*start == nullptr) {
        *newnode = *avail;
        *avail = (*avail)->next;
        (*newnode)->data = data;
        *start = *newnode;
    }
    else {
        *newnode = *avail;
        *avail = (*newnode)->next;
        (*newnode)->data = data;
        struct Node *p = *start;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = *newnode;
    }
    return;
    
}

void deleteLast(struct Node **start) {
    if (*start == nullptr) {
        cout << "list is empty";
        return;
    }

    struct Node *p1 = *start, *p2 = *start;
    while (p1->next != nullptr) {
        p2 = p1;
        p1 = p1->next;
    }

    p2->next = nullptr;
    cout << "\nNode deleted: " << p1->data;
    free(p1);

}

void traverse(struct Node *start){
    if (start == nullptr) {
        cout << "list is empty";
        return;
    }

    struct Node *p = start;
    while (p != nullptr){
        cout << p->data << endl;
        p = p->next;
    }
}


int main () {
    struct Node *avail = nullptr, *start = nullptr, *newnode = nullptr;

    insertLast(1, &avail, &start, &newnode);
    insertLast(2, &avail, &start, &newnode);
    insertLast(3, &avail, &start, &newnode);
    insertLast(4, &avail, &start, &newnode);
    insertLast(5, &avail, &start, &newnode);
    traverse(start);
   
    // short int flag = 0;

    // do {
    //     system("cls");
    //     cout << "Linked List Menu\n";

    //     invalid:
    //     cout << "\nEnter corresponding to execute functions: \n1 to Insert at last\n2 to Delete Last Elemen\n0 to Exit\nEnter: ";

    //     getchar();
    //     cin >> flag;
    //     int data,pos;
    //     cout << endl;

    //     switch (flag) {
    //         case 1:
    //             cout << "\nEnter Data Value: ";
    //             cin >> data;
    //             insertLast(data, &avail, &start, &newnode);
    //             break;

    //         case 2: 
    //             deleteLast(&start);
    //             break;

    //         case 3: 
    //             cout << "\nlinked list\n";
    //             traverse(start);
    //             break;

    //         case 0:
    //             cout << "\nThanks for using Linked List\n";
    //             break;

    //         default:
    //             cout << "\n\nInvalid input";
    //             goto invalid;
    //     } 
    //     cout << "\nEnter any key to continue";
    //     getchar();
    //     getchar();
    // } while (flag != 0);
    return 0;
}