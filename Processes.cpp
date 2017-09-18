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

    cout << "Successfully added process: " << this->get(process->getId())->getId() << endl;

    if(process->isReady())
        this->readyProcesses->put(localProcessBlock);
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
    ProcessControlBlock *processControlBlock = this->get(processID);

    if(processControlBlock == nullptr) {
        cout << "GAH WHY NO FIND: " << processID << endl;
        return nullptr;
    }

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


