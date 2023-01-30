#include <iostream>

using namespace std;

class Process{
private:    
    int PID;
    int burstTime;

public:
    Process(int burstTime, int PID);
    int getPID();
    int getBurstTime();
};

Process::Process(int burstTime, int PID){
    this->burstTime = burstTime;
    this->PID = PID;
}

int Process::getPID(){
    return this->PID;
}

int Process::getBurstTime(){
    return this->burstTime;
}


