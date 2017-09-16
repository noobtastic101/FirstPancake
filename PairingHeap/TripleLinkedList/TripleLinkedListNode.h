//
// Created by stoffel on 9/11/17.
//

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

    //ProcessControlBlock * assignLeft(ProcessControlBlock * process);
    virtual ProcessControlBlock * assignChild(ProcessControlBlock * process);
    virtual ProcessControlBlock * assignChild(TripleLinkedListNode * child);

    virtual ~TripleLinkedListNode();
};


#endif //INC_1_TRIPLELINKEDLISTNODE_H
