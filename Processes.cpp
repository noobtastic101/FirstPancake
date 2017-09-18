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
        this->readyProcesses->put(localProcessBlock);
}

//removeHighestProc will look for the highest priority and remove it
ProcessControlBlock Processes::removeHighestProc()
{
    ProcessControlBlock formallyHighestPriorityBlock = this->readyProcesses->removeMax();

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
    cout << "!!!!!!!!!!!!!!!!!" << endl;
    this->readyProcesses->print();
    cout << "?????????????????" << endl;
}

Processes::~Processes() {
    delete this->readyProcesses;
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

//getReadyQueueSize will return the size of the ready queue
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

//get will first look for the process id then return it
ProcessControlBlock *Processes::get(int processID)
{
    auto item = this->processes->find(processID);

    return item == this->processes->end() ? nullptr : &(item->second);
}

//getMax will return the max priority
ProcessControlBlock *Processes::getMax()
{
    return
            this->readyProcesses->getMax();
}


