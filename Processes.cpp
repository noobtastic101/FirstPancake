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

    cout << "Here two" << endl;

    this->addedProcessIDs->insert(process->getId());

    cout << "Here 3" << endl;
    
    this->processes->push_back(*process);

    cout << "Here 4" << endl;

    cout << "Addin to the ready queue" << endl;

    if(process->isReady())
        this->readyProcesses->put(process);

    cout << "Done Addin to the ready queue" << endl;
}

ProcessControlBlock Processes::removeHighestProc()
{
    ProcessControlBlock block = this->readyProcesses->removeMax();

    //The process is no longer ready, it is now running
    ProcessControlBlock storedProcess = this->processes->at((unsigned long) (block.getId()));
    storedProcess.setReady(false);
    storedProcess.setRunning(true);

    return storedProcess;
}

int Processes::size() {
    return
        this->readyProcesses->size();
}

bool Processes::alreadyAddedProcess(int processID)
{
    unordered_set<int>::const_iterator iterator = this->addedProcessIDs->find(processID);

    cout << "Iterator: " << iterator << endl;

    return
            iterator != this->addedProcessIDs->end();

}

void Processes::displayQueue() {
    this->readyProcesses->print();
}

Processes::~Processes() {

}

ProcessControlBlock Processes::getProcess(int processID)
{
    if(!alreadyAddedProcess(processID)) {
        return ProcessControlBlock();
    }

    return this->processes->at((unsigned long) (processID - 1));
}

ProcessControlBlock *Processes::setReady(ProcessControlBlock *process)
{
    if(!alreadyAddedProcess(process->getId()))
        return process;

    process->setReady(true);

    ProcessControlBlock processControlBlock = this->processes->at((unsigned long) process->getId() - 1);

    if(processControlBlock.isReady())
        return process;

    processControlBlock.setReady(true);
    this->readyProcesses->put(&processControlBlock);

    return process;
}

ProcessControlBlock *Processes::setReady(int processID)
{
    ProcessControlBlock processControlBlock = this->processes->at((unsigned long) processID - 1);

    return
            this->setReady(&processControlBlock);
}

int Processes::getReadyQueueSize()
{
    return
            this->readyProcesses->size();
}
