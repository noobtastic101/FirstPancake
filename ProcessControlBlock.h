//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_PROCESS_H
#define INC_1_PROCESS_H

#include <iostream>

using std::cout;
using std::endl;


class ProcessControlBlock {
private:
    bool newState = false;
    bool ready = false;
    bool running = false;
    bool waiting = false;
    bool terminated = false;

    static int counter = 1;
    static int maxPriority = 50;

protected:
    int id;
    int priority; //Priority 1 is the MAX, and priority 50 is the least.
public:

    ProcessControlBlock();

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
