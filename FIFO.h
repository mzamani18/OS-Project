#include <iostream>
#include "./Process.h"

using namespace std;

class QueueNode
{

private:
    QueueNode *nextPtr;
    Process *process;

public:
    QueueNode(Process *process)
    {
        this->process = process;
        this->nextPtr = nullptr;
    }

    QueueNode *updateNextPtr(Process *process)
    {
        this->nextPtr = new QueueNode(process);
        return this->nextPtr;
    }

    QueueNode *getNextPtr()
    {
        return this->nextPtr;
    }

    Process *getProcess()
    {
        return this->process;
    }

    void swapNextPtr(QueueNode &a, QueueNode &b)
    {
        QueueNode &tmp = a;
        a = b;
        b = tmp;
    }

    void swapProcess(Process &a, Process &b)
    {
        Process &tmp = a;
        a = b;
        b = tmp;
    }
};

class FIFO
{
private:
    QueueNode *firstPtr;
    QueueNode *lastPtr;
    int size;

public:
    FIFO()
    {
        this->firstPtr = this->lastPtr = nullptr;
        this->size = 0;
    }

    void insert(Process *process)
    {
        if (this->firstPtr == nullptr)
        {
            this->firstPtr = this->lastPtr = new QueueNode(process);
            this->size++;
            return;
        }

        this->lastPtr = this->lastPtr->updateNextPtr(process);
        this->size++;
    }

    void pop()
    {
        if (this->firstPtr == nullptr)
        {
            return;
        }

        this->firstPtr = this->firstPtr->getNextPtr();
        this->size--;
    }

    Process *top()
    {
        return this->firstPtr->getProcess();
    }

    void print()
    {
        QueueNode *tmpPtr = this->firstPtr;
        while (tmpPtr != nullptr)
        {
            cout << tmpPtr->getProcess()->getPID() << " ";
            tmpPtr = tmpPtr->getNextPtr();
        }
        cout << endl;
    }

    QueueNode *getFirstPtr()
    {
        return this->firstPtr;
    }
};