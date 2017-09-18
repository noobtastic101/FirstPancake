//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_PROCESSES_H
#define INC_1_PROCESSES_H

#include <unordered_map>
#include <iostream>
#include <vector>

#include "ProcessControlBlock.h"
#include "PairingHeap/PairingHeap.h"

using std::cout;
using std::unordered_map;
using std::vector;

class Processes {
private:
    bool alreadyAddedProcess(int processID);
    ProcessControlBlock *get(int processID);

    int currentMaxPriority;

protected:
    unordered_map<int, ProcessControlBlock> *processes;
    vector<ProcessControlBlock> readyQueue;

    void addToQueue(ProcessControlBlock *block);

public:

    Processes();

    ProcessControlBlock * insertProc(ProcessControlBlock *process);
    ProcessControlBlock removeHighestProc();

    ProcessControlBlock *getMax();
    ProcessControlBlock getProcess(int processID);
    int getReadyQueueSize();

    ProcessControlBlock *addProcessToReadyQueue(int processID);

    int size();
    void displayQueue();
    virtual ~Processes();

};


#endif //INC_1_PROCESSES_H
