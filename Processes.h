//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_PROCESSES_H
#define INC_1_PROCESSES_H

#include <unordered_map>
#include <iostream>

#include "ProcessControlBlock.h"
#include "PairingHeap/PairingHeap.h"

using std::cout;
using std::unordered_map;

class Processes {
private:
    bool alreadyAddedProcess(int processID);

    ProcessControlBlock *get(int processID);

protected:
    unordered_map<int, ProcessControlBlock> *processes;
    PairingHeap * readyProcesses;

public:
    Processes();

    ProcessControlBlock * insertProc(ProcessControlBlock *process);

    virtual ProcessControlBlock *setReady(ProcessControlBlock *process);

    ProcessControlBlock removeHighestProc();

    ProcessControlBlock getProcess(int processID);

    int getReadyQueueSize();

    virtual ProcessControlBlock *setReady(int processID);

    int size();
    void displayQueue();
    virtual ~Processes();

};


#endif //INC_1_PROCESSES_H
