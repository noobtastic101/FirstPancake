//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_PROCESSES_H
#define INC_1_PROCESSES_H

#include <unordered_set>
#include <vector>
#include <iostream>

#include "ProcessControlBlock.h"
#include "PairingHeap/PairingHeap.h"

using std::unordered_set;
using std::vector;
using std::cout;

class Processes {
private:
    bool alreadyAddedProcess(int processID);

protected:
    unordered_set<int> * addedProcessIDs;
    vector<ProcessControlBlock> * processes;
    PairingHeap * readyProcesses;

public:
    ProcessControlBlock * insertProc(ProcessControlBlock *process);
    ProcessControlBlock * removeHighestProc(ProcessControlBlock *process);
    int size();
    void displayQueue();
    virtual ~Processes();

};


#endif //INC_1_PROCESSES_H
