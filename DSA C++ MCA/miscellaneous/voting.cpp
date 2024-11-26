#include <iostream>
#include <cstdlib> 
using namespace std;

struct Election {
    int A = 0,B = 0,C = 0;

    friend ostream& operator << (ostream& os, const struct Election& e) {
        os << "\nVote count of election\nParty A: " << e.A << "\nParty B: " << e.B << "\nParty C: " << e.C;
        return os;
    }
};

void vote(struct Election& e) {
    cout << "Enter your Party name to vote it: \nParties in Election: \tA\tB\tC\nYour vote: ";
    char v;
    cin >> v;
    if ((e.A+e.B+e.C+1)%5 == 0){
        e.C++;
    }
    else {
        switch(v) {
            case 'a':
            case 'A':
                e.A++;
                break;
            case 'b':
            case 'B':
                e.B++;
                break;
            case 'c':
            case 'C':
                e.C++;    
        }
    }
    cout << "\nThanks for voting";
    cout << "\npress any key to continue";
    getchar();
    getchar();
    system("cls");
}

int main () {
    int flag;
    struct Election e;
    do {
        cout << "Election Menu\n";
        cout << "1 for voting\n2 for count\n0 for exiting\nEnter : ";
        cin >> flag;
        switch(flag) {

        case 1:
            vote(e);
            break;
        case 2:
            cout << "\nResults are: \n" << e;
            cout << "Enter any key to continue";
            getchar();
            break;
        case 0:
            cout << "Thanks for voting in the Election, results are mentioned below";
            cout << endl << e;
            getchar();
            break;
        default:
            cout << "Invalid Input\nEnter any key to continue";
            getchar();
            continue;
        }
    } while (flag != 0);
    return 0;
}