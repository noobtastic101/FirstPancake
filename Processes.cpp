//
// Created by stoffel on 9/11/17.
//

#include "Processes.h"

ProcessControlBlock *Processes::insertProc(ProcessControlBlock *process) {

    if(process == nullptr)
        return nullptr;

    if(this->alreadyAddedProcess(process->getId()))
        return process;

    this->addedProcessIDs->insert(process->getId());
    this->processes->push_back(*process);

    if(process->isReady())
        this->readyProcesses->put(process);
}

ProcessControlBlock *Processes::removeHighestProc(ProcessControlBlock *process)
{
    if(process == nullptr || !alreadyAddedProcess(process->getId()))
        return nullptr;

    this->readyProcesses->removeMax();
}

int Processes::size() {
    return
        this->readyProcesses->size();
}

bool Processes::alreadyAddedProcess(int processID)
{
    unordered_set<int>::const_iterator iterator = this->addedProcessIDs->find(processID);

    return
            iterator != this->addedProcessIDs->end();

}

void Processes::displayQueue() {
    this->readyProcesses->print();
}

Processes::~Processes() {

}