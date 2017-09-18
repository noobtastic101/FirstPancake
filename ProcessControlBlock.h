/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *ProcessControlBlock.h
 *
 *Purpose: Implement and create the functions used in our data structure of the process control block
 */

#ifndef INC_1_PROCESS_H
#define INC_1_PROCESS_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ProcessControlBlock {
private:
    bool newState = false;
    bool ready = false;
    bool running = false;
    bool waiting = false;
    bool terminated = false;

    static int counter;
    static int maxPriority;

protected:
    int id;
    int priority; //Priority 1 is the MAX, and priority 50 is the least.
public:

    ProcessControlBlock();

    ProcessControlBlock(int priority);

    ProcessControlBlock(ProcessControlBlock *block);

    bool isNew() const;
    bool isReady() const;
    bool isRunning() const;
    bool isWaiting() const;
    bool isTerminated() const;
    int getId() const;
    int getPriority() const;

    void setReady(bool ready);
    void setRunning(bool running);
    void setWaiting(bool waiting);
    void setTerminated(bool terminated);
    void setNew(bool newState);
    void setId(int id);
    void setPriority(int priority);

    void print();
};


#endif //INC_1_PROCESS_H
