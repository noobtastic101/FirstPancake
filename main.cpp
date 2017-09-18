#include <iostream>

#include "Processes.h"

using namespace std;

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


