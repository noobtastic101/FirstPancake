//
// Created by stoffel on 9/11/17.
//

#include "TripleLinkedList.h"


TripleLinkedListNode *TripleLinkedList::getHighestPriority(TripleLinkedListNode *left, TripleLinkedListNode *right) {
    if(left->process->getPriority() > right->process->getPriority())
        return left;
    else
        return right;
}

Pair<TripleLinkedListNode *>
TripleLinkedList::lowestAndHighestPriority(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
    if(left->process->getPriority() > right->process->getPriority())
        return Pair<TripleLinkedListNode *>(right, left);
    else
        return Pair<TripleLinkedListNode *>(left, right);
}
