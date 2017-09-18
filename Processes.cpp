//
// Created by stoffel on 9/11/17.
//

#include "Processes.h"

ProcessControlBlock *Processes::insertProc(ProcessControlBlock *process) {

    if(process == nullptr)
        return nullptr;

    if(this->alreadyAddedProcess(process->getId()))
        return process;

    ProcessControlBlock *localProcessBlock = new ProcessControlBlock(process);

    (*(this->processes))[process->getId()] = localProcessBlock;

    if(process->isReady())
        this->readyProcesses->put(localProcessBlock);
}

ProcessControlBlock Processes::removeHighestProc()
{
    ProcessControlBlock formallyHighestPriorityBlock = this->readyProcesses->removeMax();

    ProcessControlBlock *storedProcess = this->get(formallyHighestPriorityBlock.getId());
    storedProcess->setReady(false);
    storedProcess->setRunning(true);

    return *storedProcess;
}

int Processes::size() {
    return
            this->processes->size();
}

bool Processes::alreadyAddedProcess(int processID)
{
    unordered_map<int, ProcessControlBlock>::const_iterator iterator = this->processes->find(processID);

    return
            iterator != this->processes->end();

}

void Processes::displayQueue() {
    this->readyProcesses->print();
}

Processes::~Processes() {
    delete this->readyProcesses;
    delete this->processes;
}

ProcessControlBlock Processes::getProcess(int processID)
{
    if(!alreadyAddedProcess(processID)) {
        return ProcessControlBlock();
    }

    return (*(this->get(processID)));
}


ProcessControlBlock *Processes::setProcessAsReady(int processID)
{
    ProcessControlBlock *processControlBlock = this->get(processID);

    if(processControlBlock == nullptr)
        return nullptr;

    if(processControlBlock->isReady())
        return processControlBlock;

    processControlBlock->setReady(true);
    this->readyProcesses->put(processControlBlock);

    return processControlBlock;
}

int Processes::getReadyQueueSize()
{
    return
            this->readyProcesses->size();
}

Processes::Processes()
{
    processes = new unordered_map<int, ProcessControlBlock>();
    readyProcesses = new PairingHeap();
}

ProcessControlBlock *Processes::get(int processID)
{
    auto item = this->processes->find(processID);

    return item == this->processes->end() ? nullptr : &(item->second);
}

ProcessControlBlock *Processes::getMax()
{
    return
            this->readyProcesses->getMax();
}


