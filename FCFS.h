#include <iostream>
#include "./FIFO.h"
#include <iomanip>

using namespace std;

class FCFS
{

private:
    int numOfProcess;
    FIFO *FIFOQueue;

public:
    FCFS();
    void getInput();
    void printAllProcess();
    void calculateWaitTime();
    void calculateTurnaroundTime();
};

FCFS::FCFS()
{
    this->numOfProcess = 0;
    this->FIFOQueue = new FIFO();
}

void FCFS::getInput()
{
    cout << endl
         << "Please enter number of processs that you want to have: " << endl;

    cin >> this->numOfProcess;

    int burstTime;
    for (int i = 1; i <= this->numOfProcess; i++)
    {
        cout << endl
             << "Please enter burst time of " << i << "'th process" << endl;
        cin >> burstTime;

        Process *tmpProcess = new Process(burstTime, i);

        this->FIFOQueue->insert(tmpProcess);
    }
}

void FCFS::printAllProcess()
{
    cout << left << setw(10) << "PID" << left << setw(10) << "BurstTime" << left << setw(15) << "runing-interval" << endl;

    QueueNode *tmpPtr = this->FIFOQueue->getFirstPtr();
    int timer = 0;

    for (int i = 0; i < this->numOfProcess; i++)
    {
        cout << left << setw(10) << tmpPtr->getProcess()->getPID() << left << setw(10) << tmpPtr->getProcess()->getBurstTime()
             << left << setw(15) << "[ " + to_string(timer) + " , " + to_string(timer + tmpPtr->getProcess()->getBurstTime()) + " ]" << endl;
        timer += tmpPtr->getProcess()->getBurstTime();
        tmpPtr = tmpPtr->getNextPtr();
    }
}

void FCFS::calculateTurnaroundTime()
{
    float turnaroundTime = 0;

    QueueNode *tmpPtr = this->FIFOQueue->getFirstPtr();
    int timer = 0;

    for (int i = 0; i < this->numOfProcess; i++)
    {
        timer += tmpPtr->getProcess()->getBurstTime();
        turnaroundTime += timer;
        tmpPtr = tmpPtr->getNextPtr();
    }

    cout << endl
         << "The turnaround time of FCFS algorithm is : " << turnaroundTime << endl;
    cout << "The average turnaround time of FCFS algorithm is : " << turnaroundTime / this->numOfProcess << endl
         << endl;
}

void FCFS::calculateWaitTime()
{
    float waitingTime = 0;

    QueueNode *tmpPtr = this->FIFOQueue->getFirstPtr();
    int timer = 0;

    for (int i = 1; i < this->numOfProcess; i++)
    {
        timer += tmpPtr->getProcess()->getBurstTime();
        waitingTime += timer;
        tmpPtr = tmpPtr->getNextPtr();
    }

    cout << "The waiting time of FCFS algorithm is : " << waitingTime << endl;
    cout << "The average waiting time of FCFS algorithm is : " << waitingTime / this->numOfProcess << endl;
}
