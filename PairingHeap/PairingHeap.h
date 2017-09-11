//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_PAIRINGHEAP_H
#define INC_1_PAIRINGHEAP_H

#include <algorithm>
#include "TripleLinkedList/TripleLinkedList.h"

using std::max;

class PairingHeap
{

protected:
    TripleLinkedList nodes;
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
