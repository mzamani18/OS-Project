#include <iostream>
// #include "./FCFS.h"
#include "./SJF.h"

using namespace std;

int lastPID = 1;

int main()
{

    // Shortest Job First :
    SJF *sjf = new SJF();
    sjf->getInput();
    sjf->printAllProcess();
    sjf->calculateTurnaroundTime();
    sjf->calculateWaitTime();

    // // First Come First Service Test :
    // FCFS* fcfs = new FCFS();
    // fcfs->getInput();
    // fcfs->printAllProcess();
    // fcfs->calculateTurnaroundTime();
    // fcfs->calculateWaitTime();
}