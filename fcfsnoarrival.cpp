#include <iostream>
#include <queue>
using namespace std;

class Process
{
    public: 
        string pID;
        int aT = 0, bT, wT = -1, tAT = -1, rT = -1;
        
        Process(string pID, int bT, int aT) {
            this->pID = pID;
            this->aT = aT;
            this->bT = bT;
        }
        Process (string pID, int bT) {
            this->pID = pID;
            this->bT = bT;
        }

        void setResponseTime(int rT) {
            this->rT = rT;
        }

        void setTurnAroundTime(int tAT) {
            this->tAT = tAT - this->aT;
        }

        void setWaitingTime() {
            wT = tAT - bT;
        }

        friend ostream& operator << (ostream& os, Process& process) {
            os << process.pID << "\t" << process.bT << "\t" << process.aT << "\t" << process.wT << "\t" << process.tAT << "\t" << process.rT << "\n";

            return os;
         }
};


void findAverageTime(int size, Process* arrOfProcess) {

    float averageWT = 0, averageTAT = 0, averageRT = 0;

    for (int i = 0; i < size; i++) {
        averageWT += arrOfProcess[i].wT;
        averageTAT += arrOfProcess[i].tAT;
        averageRT += arrOfProcess[i].rT;
    }

    cout << "\nAverage Waiting Time: \t" << averageWT/size;
    cout << "\nAverage Turn Around Time: \t" << averageTAT/size;
    cout << "\nAverage Response Time: \t" << averageRT/size;
}


int main () {

    int clk = 0;
    queue<Process*> readyQR;

    Process processArr[5] = {
        Process("P0",6),
        Process("P1",4),
        Process("P2",9),
        Process("P3",2),
        Process("P4",3)
    };


    for (int i = 0; i < 5; i++) {
        readyQR.push(&processArr[i]);
    }

    while (!readyQR.empty()) {
        readyQR.front()->setResponseTime(clk);
        clk += readyQR.front()->bT;
        readyQR.front()->setTurnAroundTime(clk);
        readyQR.front()->setWaitingTime();
        readyQR.pop();
    }

    cout << "\nPID\tCBT\tAT\tWT\tTAT\tRT\n";
    for (int i = 0; i < 5; i++) {
        cout << processArr[i];
    }

    findAverageTime(5,processArr);

    cout << "\nCPU exited at " << clk;

    return 0;
}