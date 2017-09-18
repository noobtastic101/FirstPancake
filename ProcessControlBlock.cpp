/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *ProcessControlBlock.cpp
 *
 *Purpose: Implementation and structure for the process control block, the data structure representing a process in
 * the system.
 */

#include "ProcessControlBlock.h"

int ProcessControlBlock::counter = 1;
int ProcessControlBlock::maxPriority = 50;

bool ProcessControlBlock::isReady() const {
    return ready;
}

bool ProcessControlBlock::isRunning() const {
    return running;
}

bool ProcessControlBlock::isWaiting() const {
    return waiting;
}

bool ProcessControlBlock::isTerminated() const {
    return terminated;
}

int ProcessControlBlock::getId() const {
    return id;
}

void ProcessControlBlock::setReady(bool ready) {
    ProcessControlBlock::ready = ready;
}

void ProcessControlBlock::setRunning(bool running) {
    ProcessControlBlock::running = running;
}

void ProcessControlBlock::setWaiting(bool waiting) {
    ProcessControlBlock::waiting = waiting;
}

void ProcessControlBlock::setTerminated(bool terminated) {
    ProcessControlBlock::terminated = terminated;
}

void ProcessControlBlock::setNew(bool newState) {
    ProcessControlBlock::newState = newState;
}

bool ProcessControlBlock::isNew() const {
    return newState;
}

void ProcessControlBlock::setId(int id) {
    ProcessControlBlock::id = id;
}

ProcessControlBlock::ProcessControlBlock()
{
    this->id = this->priority = counter;
    counter++;
}

int ProcessControlBlock::getPriority() const {
    return priority;
}

void ProcessControlBlock::setPriority(int priority) {
    ProcessControlBlock::priority = priority;
}

//Display the IDs and the priorties of the processes in the queue

void ProcessControlBlock::print()
{
    cout << "ID: " << this->getId() << ", Priority: " << this->getPriority() << endl;
}

ProcessControlBlock::ProcessControlBlock(ProcessControlBlock *block)
{
    this->newState = block->newState;
    this->ready = block->ready;
    this->running = block->running;
    this->waiting = block->waiting;
    this->terminated = block->terminated;
    this->id = block->id;
    this->priority = block->priority;
}

ProcessControlBlock::ProcessControlBlock(int priority)
{
    this->id = this->priority = priority;
}
