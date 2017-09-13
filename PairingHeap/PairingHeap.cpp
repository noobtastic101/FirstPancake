//
// Created by stoffel on 9/11/17.
//

#include "PairingHeap.h"

/*
 * Display the IDs and the priorties of the processes in the queue
 */

void PairingHeap::print() {

}

ProcessControlBlock *PairingHeap::put(ProcessControlBlock *process)
{
    this->root = this->meld(this->root, new TripleLinkedListNode(process));
}

TripleLinkedListNode *PairingHeap::meld(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
    Pair<TripleLinkedListNode *> lowestAndHighest = this->lowestAndHighestPriority(left, right);
    lowestAndHighest.right->assignChild(lowestAndHighest.left);

    return lowestAndHighest.right;
}

ProcessControlBlock *PairingHeap::removeMax() {
    return nullptr;
}

bool PairingHeap::isEmpty() {
    return false;
}

int PairingHeap::size() {
    return 0;
}

ProcessControlBlock *PairingHeap::getMax() {
    return this->root->process;
}

