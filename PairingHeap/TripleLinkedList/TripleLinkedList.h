//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_TRIPLELINKEDLIST_H
#define INC_1_TRIPLELINKEDLIST_H


#include "TripleLinkedListNode.h"
#include "../../Utils/Pair.h"

class TripleLinkedList
{
protected:
    TripleLinkedListNode * root = nullptr;
public:
    TripleLinkedListNode * getHighestPriority(TripleLinkedListNode * left, TripleLinkedListNode * right);
    Pair<TripleLinkedListNode *> lowestAndHighestPriority(TripleLinkedListNode * left, TripleLinkedListNode * right);

};


#endif //INC_1_TRIPLELINKEDLIST_H
