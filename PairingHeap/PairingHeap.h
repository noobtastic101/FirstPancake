//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_PAIRINGHEAP_H
#define INC_1_PAIRINGHEAP_H

#include <algorithm>
#include <deque>
#include <stack>
#include <vector>

#include "TripleLinkedList/TripleLinkedList.h"

using std::max;
using std::deque;


class PairingHeap : public TripleLinkedList
{
private:
    TripleLinkedListNode * pop_n_get_back(deque & dq);

    void display(TripleLinkedListNode *currentNode);

protected:
    //TripleLinkedList nodes;
    int nodesCount = 0;

public:
    ProcessControlBlock * put(ProcessControlBlock * process);
    ProcessControlBlock * removeMax();
    bool isEmpty();
    int size();
    ProcessControlBlock * getMax();
    void print();
    TripleLinkedListNode * meld(TripleLinkedListNode * left, TripleLinkedListNode * right);
};


#endif //INC_1_PAIRINGHEAP_H
