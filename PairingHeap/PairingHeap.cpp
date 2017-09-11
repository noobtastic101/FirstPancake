//
// Created by stoffel on 9/11/17.
//

#include "PairingHeap.h"
#include "TripleLinkedList.h"

/*
 * Display the IDs and the priorties of the processes in the queue
 */

void PairingHeap::print() {

}

ProcessControlBlock *PairingHeap::put(ProcessControlBlock *process)
{

}

TripleLinkedListNode *PairingHeap::meld(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
    Pair<TripleLinkedListNode *> lowestAndHighest = this->nodes.lowestAndHighestPriority(left, right);
    lowestAndHighest.right->assignChild(lowestAndHighest.left);
}

