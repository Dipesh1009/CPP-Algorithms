#include <iostream> 
using namespace std;

struct Node {
    int data;
    struct Node *l = nullptr, *r = nullptr;

    friend ostream& operator << (ostream& os, struct Node& n) {
        os << "\t" << n.data;
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
    }

    void insertRight(struct Node *&p, int data) {
        if (!getMem()) {
            return;
        }
        nn->data = data;
        p->r = nn;     
    }
    void insertRoot(struct Node *&p, int data) {
        if (!getMem()) {
            return;
        }
        nn->data = data;
        p = nn;
    }
};

class BinaryTree {
    public: 
    Tree t;
    struct Node *root = nullptr;
    
    void insert (struct Node *&p, int data) {
        short flag;
        system("cls");
        if (p == nullptr) {
            t.insertRoot(root,data);
        }
        else if (p->l != nullptr && p->r != nullptr) {
            JUMP:
            cout << "Enter 1 to go left\n2 to go right\nAt node: " << p->data << "\nEnter your choice: "; cin >> flag;
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
            cout << "Enter 1 to insert left\n2 to insert right\nAt node: " << p->data << "\nEnter your choice: "; cin >> flag;
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
            cout << "At node: " << p->data << " left subtree is null, and right subtree exists\nEnter 1 to insert at left\nEnter 2 to go to right sub tree\nEnter: ";
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
            cout << "At node: " << p->data << " right subtree is null, and left subtree exists\nEnter 1 to go to left subtree\nEnter 2 to insert at right\nEnter: ";
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
        else if (p->l == nullptr) {
            return;
        } 
        inorder(p->l);
        cout << *p << "\t";
        if (p->r == nullptr) {
            return;
        }
        inorder(p->r);

    }

};

int main() 
{
    short flag; int data;
    BinaryTree t;
    do {
        JUMP3:
        system("cls");
        cout << "\n1 for insert\n2 for traverse\nEnter: ";
        cin >> flag;
        switch(flag) {
            case 1:
                cout << "\nEnter: "; cin >> data;
                t.insert(t.root,data);
                break;
            case 2:
                t.inorder(t.root);
                getchar();getchar();
            case 0:
                break;
            default:
                goto JUMP3;
        }
        getchar(); getchar();
    } while(flag != 0);
    
    return 0;
}