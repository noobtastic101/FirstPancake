/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *Processes.h
 *
 *Purpose: Implement and create the functions used processes where the process get their ID's and get manipulated.
 */

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
    ProcessControlBlock removeHighestProc();

    ProcessControlBlock *getMax();
    ProcessControlBlock getProcess(int processID);
    int getReadyQueueSize();

    ProcessControlBlock *setProcessAsReady(int processID);

    int size();
    void displayQueue();
    virtual ~Processes();

};


#endif //INC_1_PROCESSES_H
