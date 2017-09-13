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
    TripleLinkedListNode * left;
    TripleLinkedListNode * child;
    TripleLinkedListNode * next;
    ProcessControlBlock * process;
    TripleLinkedListNode(TripleLinkedListNode *left = nullptr, TripleLinkedListNode *child = nullptr, TripleLinkedListNode *next = nullptr);

    TripleLinkedListNode(ProcessControlBlock *process);

    //ProcessControlBlock * assignLeft(ProcessControlBlock * process);
    virtual ProcessControlBlock * assignChild(ProcessControlBlock * process);
    virtual ProcessControlBlock * assignChild(TripleLinkedListNode * child);

    virtual ~TripleLinkedListNode();
};


#endif //INC_1_TRIPLELINKEDLISTNODE_H
