#include <iostream>
#include <queue>
using namespace std;

class Process
{
    private: 
        string pID;
        int arrivalTime = 0, burstTime, waitingTime = 0, turnATime = 0, responseTime = 0;
    public: 
        Process(string pID, int burstTime, int arrivalTime) {
            this->pID = pID;
            this->arrivalTime = arrivalTime;
            this->burstTime = burstTime;
        }
        Process (string pID, int burstTime) {
            this->pID = pID;
            this->burstTime = burstTime;
        }

        int getBT() {return burstTime;}
        int getAT() {return arrivalTime;}
        int getWT() {return waitingTime;}
        int getTAT() {return turnATime;}
        int getRT() {return responseTime;}

        void setResponseTime(int responseTime) {
            this->responseTime = responseTime;
        }

        void setTurnAroundTime(int turnATime) {
            this->turnATime = turnATime - this->arrivalTime;
        }

        void setWaitingTime() {
            waitingTime = turnATime - burstTime;
        }

        friend ostream& operator << (ostream& os, Process& process) {
            os << process.pID << "\t" << process.burstTime << "\t" << process.arrivalTime << "\t" << process.waitingTime << "\t" << process.turnATime << "\t" << process.responseTime << "\n";

            return os;
         }
};


void findAverageTime(int size, Process* arrOfProcess) {

    int averageWT = 0, averageTAT = 0, averageRT = 0;

    for (int i = 0; i < size; i++) {
        averageWT += arrOfProcess[i].getWT();
        averageTAT += arrOfProcess[i].getTAT();
        averageRT += arrOfProcess[i].getRT();
    }

    cout << "\nAverage Waiting Time: \t" << averageWT/size;
    cout << "\nAverage Turn Around Time: \t" << averageTAT/size;
    cout << "\nAverage Response Time: \t" << averageRT/size;
}

bool compareByArrivalTime(Process &p1, Process &p2) {
    return p1.getAT() < p2.getAT();
}

int main () {
    auto compareByArrival = [] (Process *p1, Process *p2) -> bool {
        return p1->getAT() > p2->getAT();
    };
    
    int clk = 0;
    
    priority_queue<Process*, vector<Process*>, decltype(compareByArrival)> readyQ(compareByArrival);
    Process processArr[5] = {
        Process("P0",6,2),
        Process("P1",4,1),
        Process("P2",9,1),
        Process("P3",2,3),
        Process("P4",3,4)
    };

    for (int i = 0; i < 5; i++) {
        readyQ.push(&processArr[i]);
    }

    while (!readyQ.empty()) {
        if( clk >= readyQ.top()->getAT()) {
            readyQ.top()->setResponseTime(clk);
            clk += readyQ.top()->getBT();
            readyQ.top()->setTurnAroundTime(clk);
            readyQ.top()->setWaitingTime();
            readyQ.pop();
        }
        else {
            clk++;
        }
    }
    cout << "\nPID\tCBT\tAT\tWT\tTAT\tRT\n";
    for (int i = 0; i < 5; i++) {
        cout << processArr[i];
    }

    findAverageTime(5,processArr);

    cout << "\nCPU exited at " << clk;

    return 0;
}