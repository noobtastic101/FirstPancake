#include <iostream>
#include <vector>
#include <deque>

#include "Processes.h"

using namespace std;



void runTestOne()
{
    Processes * processes = new Processes();

    //Add 20 processes, with a READY state

    ProcessControlBlock * currentBlock;

    for(int count = 1; count < 21; count++)
    {
        currentBlock = new ProcessControlBlock();
        currentBlock->setReady(true);

        processes->insertProc(currentBlock);
    }


    delete processes;
}

int main() {
    deque<int> example;

    example.push_back(5);
    example.push_back(6);
    example.push_back(7);

    cout << "Front: " << example.front() << endl;
}


/*
 *
(a) add processes 5, 1, 8, 11 to q1. Display the content of q1
(b) remove the process with the highest priority from q1 and display q1.
(c) remove the process with the highest priority from q1 and display q1
(d) Insert processes 3, 7, 2, 12, 9 to q1
(e) One by one remove the process with the highest priority from the queue q1 and display it after each removal.
 */


