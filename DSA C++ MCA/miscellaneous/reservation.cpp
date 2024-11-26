#include <iostream>
#include <cstdlib>
using namespace std;

struct Station {
    public:
    char name;
    int seats = 0;
};

class Reservation
{
    public:
    struct Station stations[4];
    
    Reservation() {}

    Reservation(char st1, char st2, char st3, char st4){
        stations[0].name = st1;
        stations[1].name = st2;
        stations[2].name = st3;
        stations[3].name = st4;

    }

    bool isAvailable(int source, int destination) {
        for (int i = source; i < destination; i++) {
            if (stations[i].seats ==4 ) {
                return false;
            }
        }
        return true;
    }

    bool bookTicket(int source, int destination){
        if(!isAvailable(source, destination)) {
            cout << endl << "Seats are not available\n\n";
            return false;
        }
        
        for (int i = source; i < destination; i++) {
            stations[i].seats++;
        }
        return true;
    }

    friend ostream& operator << (ostream& os, const Reservation &r) {
        os << "Stations" << "\t" << "Seats" << "\n\n";
        
        for (const Station &st : r.stations) {
            os << st.name << "\t\t" << st.seats << "\n";
        }

        return os;
    }
};

int main () {
    int s, d;
    bool flag = true;
    Reservation ABC('A','B','C','D'), CBA('D','C','B','A');
    
    do{
        cout << "To book tickets, enter 1\nTo go back, enter 0\n\n";
        cin >> flag;
        if (flag) {
            system("cls");
            cout << "Book tickets"<< endl;
            cout << "Available stations: A, B, C, D";
            cout << "\n\n0 for A,\n1 for B,\n2 for C\n3 for D\n";
            cout << "Enter the source station: ";
            cin >> s;
            cout << "Enter the Destination: ";
            cin >> d;

            if (s < d){
                if(ABC.bookTicket(s,d)) {
                    cout << "Your tickets are booked in ABC exp\n\n";
                }
            }
            else if (s > d) {
                if (CBA.bookTicket(d,s)) {
                    cout << "Your tickets are booked in CBA exp\n\n";
                }
            }
            else {
                cout << "Invalid input";
            }
            cout << "Enter any key to proceed";
            getchar();
            getchar();
            system("cls");
        }
        else {
            cout << "Hope you enjoyed our services\n\n";
        }
    }while(flag);

    cout << ABC << endl;
    cout << CBA;
    
    
    return 0;
}