/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 */

#include <iostream>

#include "Processes.h"

using namespace std;

void setAsReadyOrComplain(Processes *processes, int processID)
{
    ProcessControlBlock *block = processes->setProcessAsReady(processID);

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

    cout << "Highest priority process: " << processes->getMax()->getId() << endl;
    setAsReadyOrComplain(processes, 1);

    cout << "Highest priority process: " << processes->getMax()->getId() << endl;

    setAsReadyOrComplain(processes, 8);

    cout << "Highest priority process: " << processes->getMax()->getId() << endl;

    setAsReadyOrComplain(processes, 11);

    cout << "Highest priority process: " << processes->getMax()->getId() << endl;

    cout << "Done setting first ready states" << endl;

    cout << "Displaying queue" << endl;
    processes->displayQueue();
    cout << "Done displaying the queue" << endl;

    cout << "Setting the second ready state" << endl;

    //Add processes 3, 7, 2, 12 and 9 to the ready queue
    processes->setProcessAsReady(3);
    processes->setProcessAsReady(7);
    processes->setProcessAsReady(2);
    processes->setProcessAsReady(12);
    processes->setProcessAsReady(9);

    cout << "Done setting the second ready state" << endl;

    ProcessControlBlock process;

    cout << "Iteratively removing the highest element" << endl;

    while(processes->getReadyQueueSize() != 0) {
        process = processes->removeHighestProc();
        process.print();
    }

    cout << "Done iteratively removing the highest element" << endl;

    delete processes;
}

int main() {
    runTestOne();
}


/*
 *
(a) add processes 5, 1, 8, 11 to q1. Display the content of q1
(b) remove the process with the highest priority from q1 and display q1.
(c) remove the process with the highest priority from q1 and display q1
(d) Insert processes 3, 7, 2, 12, 9 to q1
(e) One by one remove the process with the highest priority from the queue q1 and display it after each removal.
 */


