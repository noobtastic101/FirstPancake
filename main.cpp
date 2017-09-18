#include <iostream>

#include "Processes.h"

using namespace std;

void setAsReadyOrComplain(Processes *processes, int processID)
{
    ProcessControlBlock *block = processes->addProcessToReadyQueue(processID);

    if(block == nullptr)
        cout << "HEY MAN WHAT THE SHIT WHY NO WORK " << processID << endl;
}



void runTestOne()
{
    cout << "Starting off" << endl;

    Processes * processes = new Processes();

    cout << "Created processes" << endl;

    //Add 20 processes, with a READY state

    ProcessControlBlock * currentBlock;

    for(int count = 1; count < 21; count++)
    {
        currentBlock = new ProcessControlBlock(count);
        processes->insertProc(currentBlock);
    }

    cout << "Added processes" << endl;

    cout << "Displaying the processes added" << endl;


    cout << "Setting first ready states" << endl;

    //Add processes 5, 1, 8, and 11 to the ready queue
    setAsReadyOrComplain(processes, 5);

    //cout << "Highest priority process: " << processes->getMax()->getId() << endl;
    setAsReadyOrComplain(processes, 1);

    //cout << "Highest priority process: " << processes->getMax()->getId() << endl;

    setAsReadyOrComplain(processes, 8);

    //cout << "Highest priority process: " << processes->getMax()->getId() << endl;

    setAsReadyOrComplain(processes, 11);

    //cout << "Highest priority process: " << processes->getMax()->getId() << endl;

    cout << "Done setting first ready states" << endl;


    cout << "Displaying queue" << endl;
    processes->displayQueue();
    cout << "Done displaying the queue" << endl;

    cout << "Setting the second ready state" << endl;

    //Add processes 3, 7, 2, 12 and 9 to the ready queue
    processes->addProcessToReadyQueue(3);
    processes->addProcessToReadyQueue(7);
    processes->addProcessToReadyQueue(2);
    processes->addProcessToReadyQueue(12);
    processes->addProcessToReadyQueue(9);

    cout << "Done setting the second ready state" << endl;

    ProcessControlBlock process;

    cout << "Iteratively removing the highest element" << endl;

    while(processes->getReadyQueueSize() != 0) {
        process = processes->removeHighestProc();
    }

    cout << "Done iteratively removing the highest element" << endl;

    delete processes;
}

int main() {
//    runTestOne();


    Processes *processes = new Processes();

    ProcessControlBlock *currentBlock = new ProcessControlBlock(8);
    currentBlock->setReady(true);

    processes->insertProc(currentBlock);

    currentBlock = new ProcessControlBlock(9);
    currentBlock->setReady(true);
    processes->insertProc(currentBlock);

    currentBlock = new ProcessControlBlock(3);
    currentBlock->setReady(true);
    processes->insertProc(currentBlock);

    currentBlock = new ProcessControlBlock(4);
    currentBlock->setReady(true);
    processes->insertProc(currentBlock);

    processes->displayQueue();

    cout << "\n\n\n" << endl;

    processes->removeHighestProc().print();
    processes->removeHighestProc().print();
    processes->removeHighestProc().print();
    processes->removeHighestProc().print();


//    Processes * processes = new Processes();
//
//    ProcessControlBlock * currentBlock = new ProcessControlBlock(40);
//    currentBlock->setReady(true);
//
//    processes->insertProc(currentBlock);
//
//    for(int count = 1; count < 19; count++)
//    {
//        currentBlock = new ProcessControlBlock(count);
//        currentBlock->setReady(true);
//        processes->insertProc(currentBlock);
//    }
//
//    currentBlock = new ProcessControlBlock(100);
//    currentBlock->setReady(true);
//
//    processes->insertProc(currentBlock);
//
//    for(int count = 50; count < 60; count++)
//    {
//        currentBlock = new ProcessControlBlock(count);
//        currentBlock->setReady(true);
//        processes->insertProc(currentBlock);
//    }
//
//    cout << "First display" << endl;
//    processes->displayQueue();
//    cout << "end first display" << endl;
//
//    ProcessControlBlock formerMax;
//
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();
//    processes->removeHighestProc().print();

}


/*
 *
(a) add processes 5, 1, 8, 11 to q1. Display the content of q1
(b) remove the process with the highest priority from q1 and display q1.
(c) remove the process with the highest priority from q1 and display q1
(d) Insert processes 3, 7, 2, 12, 9 to q1
(e) One by one remove the process with the highest priority from the queue q1 and display it after each removal.
 */


