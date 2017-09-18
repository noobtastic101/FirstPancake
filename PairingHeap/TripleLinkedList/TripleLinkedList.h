/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *TripleLinkedList.h
 *
 *Purpose: Implement and create the triple linked list
 */

#ifndef INC_1_TRIPLELINKEDLIST_H
#define INC_1_TRIPLELINKEDLIST_H


#include "TripleLinkedListNode.h"
#include "../../Utils/Pair.h"

class TripleLinkedList
{
protected:
    TripleLinkedListNode * root = nullptr;

    void del(TripleLinkedListNode *currentNode);
public:
    TripleLinkedListNode * getHighestPriority(TripleLinkedListNode * left, TripleLinkedListNode * right);
    Pair<TripleLinkedListNode *> lowestAndHighestPriority(TripleLinkedListNode * left, TripleLinkedListNode * right);

    virtual ~TripleLinkedList();

};


#endif //INC_1_TRIPLELINKEDLIST_H
