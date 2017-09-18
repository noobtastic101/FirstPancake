/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *main.cpp
 *
 *Purpose: Implement the tests used to test our heap. The two tests are:
 *
 * Test 1 will do the following:
 *      Add processes to q1
 *      Remove the process with the highest priority and display q1
 *      Inset processes into q1
 *      One by one remove the highest priority process and display q1 after each removal
 *
 * Test 2 will do the following:
 *      This tet will evaluate the performance of our implementation.
 *      After selecting 10 random processes, it will run the following 1,000,000 times.
 *
 *      There will be a rng element that will select on of two tests, the first:
 *          The process with the highest priority will be removed.
 *          OR
 *          A process that currently isn't in q1 will be added.
 *
 *        This test will measure the total time it takes to make 1,000,000 iterations and output the final results.
 */

#include <iostream>

#include "Processes.h"

using namespace std;

//implementation for test two
void runTestTwo(Processes * processes)
{
//    int randomNumber = rand() % 12 + 1;

    //First, select 10 processes at random
    vector<int> randomProcesssIDs;
    for(int count = 0; count < 10; count++)
        randomProcesssIDs.push_back((rand() % 20) + 1);

    vector<int> randomNewPriorties;
    srand(time(NULL));

    for(int count = 0; count < randomProcesssIDs.size(); count++)
        randomNewPriorties.push_back((rand() % 50) + 1);

    for(int index = 0; index < randomProcesssIDs.size(); index++)
    {
        processes->changePriorityInProcesses(randomProcesssIDs[index], randomNewPriorties[index]);
    }

    //50/50 for the selection of processes
    int coinToss = 0;

    milliseconds start = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );

    for(int count = 0; count < 1000000; count++)
    {
        coinToss = (rand() % 2);

        //remove process
        if(coinToss == 0)
        {
            processes->removeHighestProc();
        }
        else //add process
        {
            processes->addProcessToReadyQueue(rand() % 20);
        }
    }

    milliseconds end = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );
    
    milliseconds elapsed = end - start;

    cout << "Elapsed: " << elapsed.count() << "ms" << endl;
    processes->displayQueue();
}

//implementation of test one
void runTestOne(Processes * processes)
{
    cout << "Starting off" << endl;

    cout << "Created processes" << endl;

    //Add 20 processes, with a READY state

    ProcessControlBlock * currentBlock;

    for(int count = 1; count < 21; count++)
    {
        currentBlock = new ProcessControlBlock(count);
        processes->insertProc(currentBlock);
    }

    processes->addProcessToReadyQueue(5);
    processes->addProcessToReadyQueue(1);
    processes->addProcessToReadyQueue(8);
    processes->addProcessToReadyQueue(11);


    cout << "Displaying queue" << endl;
    processes->displayQueue();
    cout << "Done displaying the queue" << endl;

    //Add processes 3, 7, 2, 12 and 9 to the ready queue
    processes->addProcessToReadyQueue(3);
    processes->addProcessToReadyQueue(7);
    processes->addProcessToReadyQueue(2);
    processes->addProcessToReadyQueue(12);
    processes->addProcessToReadyQueue(9);

    ProcessControlBlock process;

    cout << "Iteratively removing the highest element" << endl;

    while(processes->getReadyQueueSize() != 0) {
        process = processes->removeHighestProc();
    }

    cout << "Done iteratively removing the highest element" << endl;
}

int main() {

    Processes *processes = new Processes();

    runTestOne(processes);
    runTestTwo(processes);

    delete processes;


}

/*
 *
(a) add processes 5, 1, 8, 11 to q1. Display the content of q1
(b) remove the process with the highest priority from q1 and display q1.
(c) remove the process with the highest priority from q1 and display q1
(d) Insert processes 3, 7, 2, 12, 9 to q1
(e) One by one remove the process with the highest priority from the queue q1 and display it after each removal.
 */


