/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *TripleLinkedListNode.h
 *
 *Purpose: Implement and create the triple linked list node
 */

#ifndef INC_1_TRIPLELINKEDLISTNODE_H
#define INC_1_TRIPLELINKEDLISTNODE_H


#include "../../ProcessControlBlock.h"

class TripleLinkedListNode
{
protected:


public:
    TripleLinkedListNode * left = nullptr;
    TripleLinkedListNode * child = nullptr;
    TripleLinkedListNode * next = nullptr;
    TripleLinkedListNode * parent = nullptr;
    ProcessControlBlock * process = nullptr;

    explicit TripleLinkedListNode(TripleLinkedListNode *left = nullptr, TripleLinkedListNode *child = nullptr, TripleLinkedListNode *next = nullptr);
    explicit TripleLinkedListNode(ProcessControlBlock *process);
    TripleLinkedListNode();

    void print();

    virtual ProcessControlBlock * assignChild(ProcessControlBlock * process);

    virtual ProcessControlBlock *assignChild(TripleLinkedListNode *newChild);

    virtual ~TripleLinkedListNode();
};


#endif //INC_1_TRIPLELINKEDLISTNODE_H
