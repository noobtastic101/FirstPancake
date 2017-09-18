/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *Processes.cpp
 *
 *Purpose: Handles the processes that are used in the process control block. This program contains a number of functions
 * for the ReadyQueue: insetProc, removeHighestProc, size, and displayQueue.
 */

#include "Processes.h"

//insertProc will insert a new process in to the process control block
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

//removeHighestProc will look for the highest priority and remove it
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

//size returns the current size of the process control block
int Processes::size() {
    return
            this->processes->size();
}

//alreadyAddedProcess will check to see if a process has already been added to the process control block
bool Processes::alreadyAddedProcess(int processID)
{
    unordered_map<int, ProcessControlBlock>::const_iterator iterator = this->processes->find(processID);

    return
            iterator != this->processes->end();

}

//displayQueue will display all of the processes in the queue
void Processes::displayQueue() {
    for(int index = 0; index < this->readyQueue.size(); index++)
        this->readyQueue[index].print();
}

Processes::~Processes() {
    //delete this->readyProcesses;
    delete this->processes;
}

//getProcess will get the process from the ID
ProcessControlBlock Processes::getProcess(int processID)
{
    if(!alreadyAddedProcess(processID)) {
        return ProcessControlBlock();
    }

    return (*(this->get(processID)));
}

//setProcessAsReady will check for the process to make sure it isn't already in the process
//control block and then get it ready to be insterted int it.
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

//getReadyQueueSize will return the size of the ready queue
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

//get will first look for the process id then return it
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

//addToQueue will add the next node to the queue as long as it isn't already in there.
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

//changePriorityInProcesses will set the current processID's priority to the new priority.
bool Processes::changePriorityInProcesses(int processID, int newPriority)
{
    this->get(processID)->setPriority(newPriority);
}
