#include <iostream> 
using namespace std;

struct Node {
    int data;
    struct Node *l = nullptr, *r = nullptr;

    friend ostream& operator << (ostream& os, struct Node& n) {
        os << n.data << "\t";
        return os;
    }
};

class Tree {
    private:
    struct Node *nn = nullptr;

    public:

    bool getMem(){
        nn = new struct Node();
        if (nn == nullptr) {
            cout << "\nInsufficient Memory\n";
            return false;
        }
        return true;
    }

    void insertLeft(struct Node *&p, int data) {
        if (!getMem()) {
            return;
        }
        nn->data = data;
        p->l = nn;     
        cout << "\n" << data << " is inserted at left of " << *p << endl;
    }

    void insertRight(struct Node *&p, int data) {
        if (!getMem()) {
            return;
        }
        nn->data = data;
        p->r = nn;    
        cout << "\n" << data << " is inserted at right of " << *p << endl; 
    }
    void insertRoot(struct Node *&p, int data) {
        if (!getMem()) {
            return;
        }
        nn->data = data;
        p = nn;
        cout << "\n" << data << " is inserted at root node" << endl;
    }
};

class BinaryTree {
    public: 
    Tree t;
    struct Node *root = nullptr;
    
    void insert (struct Node *&p, int data) {
        short flag;
        if (p == nullptr) {
            t.insertRoot(root,data);
        }
        else if (p->l != nullptr && p->r != nullptr) {
            JUMP:
            system("cls");
            cout << "At node: " << p->data << endl;
            cout << "Enter 1 to go left\nEnter 2 to go right\n\nEnter your choice: "; 
            cin >> flag;
            switch(flag) {
                case 1:
                    insert(p->l,data);
                    break;
                case 2:
                    insert(p->r,data);
                    break;
                default:
                    cout << "\nInvalid input\n";
                    goto JUMP;
            } 
        }
        else if (p->l == nullptr && p->r == nullptr) {
            JUMP2:
            system("cls");
            cout << "At node: " << p->data << endl;
            cout << "\nEnter 1 to insert left\nEnter 2 to insert right\n\nEnter your choice: "; 
            cin >> flag;
            switch(flag) {
                case 1:
                    t.insertLeft(p,data);
                    break;
                case 2:
                    t.insertRight(p,data);
                    break;
                default:
                    cout << "\nInvalid input\n";
                    goto JUMP2;
            } 
        }
        else if (p->l == nullptr) {
            JUMP3:
            system("cls");
            cout << "At node: " << p->data << "\nLeft subtree is null, and Right subtree exists\n\nEnter 1 to insert at left\nEnter 2 to go to right sub tree\n\nEnter: ";
            cin >> flag;
            switch(flag) {
                case 1: 
                    t.insertLeft(p,data);
                    break;
                case 2:
                    insert(p->r, data);
                    break;
                default:
                    cout << "\nInvalid input\n";
                    goto JUMP3;
            }
        }
        else {
            JUMP4:
            system("cls");
            cout << "At node: " << p->data << "\nRight subtree is null, and Left subtree exists\n\nEnter 1 to go to left subtree\nEnter 2 to insert at right\n\nEnter: ";
            cin >> flag;
            switch(flag) {
                case 1: 
                    insert(p->l,data);
                    break;
                case 2:
                    t.insertRight(p, data);
                    break;
                default:
                    cout << "\nInvalid input\n";
                    goto JUMP4;
            }
        }
        
        return;
    }

    void inorder(struct Node *&p) {
        if (p == nullptr) {
            cout << "\nTree is empty\n";
            return;
        }
        if(p->l != nullptr) {
            inorder(p->l);
        }
        cout << *p;
        if (p->r != nullptr) {
            inorder(p->r);
        }
    }

};

int main() 
{
    short flag; int data;
    BinaryTree t;
    do {
        JUMP3:
        system("cls");
        cout << "Binary Tree Menu";
        cout << "\n1 for insert\n2 for traverse\nEnter: ";
        cin >> flag;
        switch(flag) {
            case 1:
                cout << "\nEnter data to insert: "; cin >> data;
                t.insert(t.root,data);
                break;
            case 2:
                cout << "\nTree Inorder Traversal:\n";
                t.inorder(t.root);
            case 0:
                break;
            default:
                cout << "\nInvalid input:(";
                getchar(); getchar();
                goto JUMP3;
        }
        cout << "\nPress any key to continue:)";
        getchar(); getchar();
    } while(flag != 0);
    
    return 0;
}