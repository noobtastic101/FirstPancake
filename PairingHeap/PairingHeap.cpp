//
// Created by stoffel on 9/11/17.
//

#include "PairingHeap.h"

/*
 * Display the IDs and the priorties of the processes in the queue
 */

void PairingHeap::print()
{
    this->display(this->root);
}


ProcessControlBlock *PairingHeap::put(ProcessControlBlock *process)
{
    if(this->size() == 0) {
        this->root = new TripleLinkedListNode(process);
        this->nodesCount++;
        return process;
    } else {
        this->root = this->meld(this->root, new TripleLinkedListNode(process));
        this->nodesCount++;
        return process;
    }
}

TripleLinkedListNode *PairingHeap::meld(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
//    cout << "Melding these two" << endl;
//    left->print();
//    right->print();

    Pair<TripleLinkedListNode *> lowestAndHighest = this->lowestAndHighestPriority(left, right);
    lowestAndHighest.right->assignChild(lowestAndHighest.left);

    return lowestAndHighest.right;
}

ProcessControlBlock PairingHeap::removeMax()
{
    //first pass: go left to right. Meld every 2 nodes into a new pairing heap, and store the new heap in a
    //queue

    TripleLinkedListNode *oldMax;
    ProcessControlBlock oldMaxProcess;
    this->nodesCount--;

    if(this->root->child != nullptr && this->root->child->next == nullptr)
    {
        oldMax = this->root;
        this->root = this->root->child;

        oldMaxProcess = ProcessControlBlock(*oldMax->process);
        delete oldMax;

        return oldMaxProcess;
    }

    deque<TripleLinkedListNode *> nodeQueue = deque<TripleLinkedListNode *>();
    TripleLinkedListNode * currentNode = this->root->child;

    int count = 1;
    while(currentNode != nullptr)
    {
        if((count % 2) == 0)
            nodeQueue.push_back(this->meld(currentNode->left, currentNode));

        currentNode = currentNode->next;
        count++;
    }

    if((count % 2) != 0)
        nodeQueue.push_back(currentNode);

    TripleLinkedListNode * right = this->pop_n_get_back(nodeQueue);
    TripleLinkedListNode * left;

    //second pass: go right to left
    for(unsigned long index = nodeQueue.size() - 2; index > -1; index--)
    {
        left = this->pop_n_get_back(nodeQueue);
        right = this->meld(left, right);
    }

    //check this
    oldMax = this->root;
    oldMaxProcess = ProcessControlBlock(*oldMax->process);

    this->root = right;

    return oldMaxProcess;
}

bool PairingHeap::isEmpty() {
    return false;
}

int PairingHeap::size() {
    return nodesCount;
}

ProcessControlBlock *PairingHeap::getMax() {

    if(this->root == nullptr) {
        cout << "GAH WHY NO ROOT" << endl;
        return nullptr;
    }
    
    return this->root->process;
}

TripleLinkedListNode *PairingHeap::pop_n_get_back(deque<TripleLinkedListNode *> &dq)
{
    TripleLinkedListNode * backNode = dq.back();
    dq.pop_back();

    return backNode;
}

void PairingHeap::display(TripleLinkedListNode *currentNode)
{
    if(currentNode != nullptr)
    {
        display(currentNode->left);
        display(currentNode->next);
        currentNode->print();
    }
}

