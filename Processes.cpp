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
        this->addToQueue(localProcessBlock);

//    if(process->isReady())
//        this->readyProcesses->put(localProcessBlock);

}

ProcessControlBlock Processes::removeHighestProc()
{
    //ProcessControlBlock formallyHighestPriorityBlock = this->readyProcesses->removeMax();

    if(this->readyQueue.empty())
        return ProcessControlBlock(-1);


    ProcessControlBlock formallyHighestPriorityBlock = this->readyQueue.front();
    this->readyQueue.erase(this->readyQueue.begin());

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
    for(int index = 0; index < this->readyQueue.size(); index++)
        this->readyQueue[index].print();
}

Processes::~Processes() {
    //delete this->readyProcesses;
    delete this->processes;
}

ProcessControlBlock Processes::getProcess(int processID)
{
    if(!alreadyAddedProcess(processID)) {
        return ProcessControlBlock();
    }

    return (*(this->get(processID)));
}


ProcessControlBlock *Processes::addProcessToReadyQueue(int processID)
{
    ProcessControlBlock *processControlBlock = this->get(processID);

    if(processControlBlock == nullptr)
        return nullptr;

    if(processControlBlock->isReady())
        return processControlBlock;

    processControlBlock->setReady(true);

    if(processControlBlock->isRunning())
        processControlBlock->setRunning(false);

    //this->readyProcesses->put(processControlBlock);
    this->addToQueue(processControlBlock);

    return processControlBlock;
}

int Processes::getReadyQueueSize()
{
//    return
//            this->readyProcesses->size();

    return this->readyQueue.size();
}

Processes::Processes()
{
    processes = new unordered_map<int, ProcessControlBlock>();
//    readyProcesses = new PairingHeap();
}

ProcessControlBlock *Processes::get(int processID)
{
    auto item = this->processes->find(processID);

    return item == this->processes->end() ? nullptr : &(item->second);
}

ProcessControlBlock *Processes::getMax()
{
//    return
//            this->readyProcesses->getMax();

    return &(this->readyQueue.front());
}

void Processes::addToQueue(ProcessControlBlock *block)
{
    ProcessControlBlock *localBlock = new ProcessControlBlock(block);

    if(this->readyQueue.empty()) {
        this->readyQueue.push_back(*localBlock);
        return;
    }

    auto itr = this->readyQueue.begin();

    while(itr != this->readyQueue.end()) {
        if(localBlock->getPriority() > (*itr).getPriority()) {
            this->readyQueue.insert(itr, *localBlock);
            return;
        }

        itr++;
    }

    this->readyQueue.push_back(*localBlock);
}

bool Processes::changePriorityInProcesses(int processID, int newPriority)
{
    this->get(processID)->setPriority(newPriority);
}
