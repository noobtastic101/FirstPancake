//
// Created by stoffel on 9/11/17.
//

#include "Processes.h"

ProcessControlBlock *Processes::insertProc(ProcessControlBlock *process) {

    if(process == nullptr)
        return nullptr;

    cout << "Here 1" << endl;

    if(this->alreadyAddedProcess(process->getId()))
        return process;

    cout << "Here 3" << endl;

    (*(this->processes))[process->getId()] = new ProcessControlBlock(process);

    ProcessControlBlock *addedProcess = this->get(process->getId());

    cout << "Addin to the ready queue" << endl;

    if(process->isReady())
        this->readyProcesses->put(process);

    cout << "Done Addin to the ready queue" << endl;
}

ProcessControlBlock Processes::removeHighestProc()
{
    ProcessControlBlock block = this->readyProcesses->removeMax();

    //The process is no longer ready, it is now running
//    ProcessControlBlock storedProcess = this->processes->at((unsigned long) (block.getId()));

    ProcessControlBlock *storedProcess = this->get(block.getId());

    storedProcess->setReady(false);
    storedProcess->setRunning(true);

    return *storedProcess;
}

int Processes::size() {
    return
        this->readyProcesses->size();
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

ProcessControlBlock *Processes::setReady(ProcessControlBlock *process)
{
    if(process == nullptr)
        return nullptr;

    if(!alreadyAddedProcess(process->getId()))
        return process;

    process->setReady(true);

    ProcessControlBlock *processControlBlock = this->get(process->getId());

    if(processControlBlock->isReady())
        return process;

    processControlBlock->setReady(true);

    this->readyProcesses->put(processControlBlock);

    return process;
}

ProcessControlBlock *Processes::setReady(int processID)
{
    cout << "processID: " << processID << ", Processes size: " << this->processes->size() << endl;

    ProcessControlBlock *processControlBlock = this->get(processID);

    if(processControlBlock == nullptr)
        return nullptr;

    cout << "Getting here?" << endl;

    return
            this->setReady(processControlBlock);
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
    std::unordered_map<int, ProcessControlBlock>::iterator item = this->processes->find(processID);

    return item == this->processes->end() ? nullptr : &(item->second);
}
