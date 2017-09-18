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

    if(this->root->child == nullptr)
    {
        oldMaxProcess = ProcessControlBlock(this->root->process);
        oldMax = this->root;

        this->root = nullptr;
        this->nodesCount = 0;
        return oldMaxProcess;
    }
//    else if(this->root->child->next == nullptr)
//    {
//        oldMax = this->root;
//        this->root = this->root->child;
//        this->root->left = nullptr;
//
//        oldMaxProcess = ProcessControlBlock(*oldMax->process);
//        return oldMaxProcess;
//    }
    else {

//        deque<TripleLinkedListNode *> nodeQueue = deque<TripleLinkedListNode *>();
//
//        TripleLinkedListNode *currentNode = this->root->child;
//        TripleLinkedListNode * orginalNext;
//        TripleLinkedListNode * prev;
//
//        //Remove the old max
//        oldMax = this->root;
//        oldMaxProcess = ProcessControlBlock(*oldMax->process);
//        this->root->child->left = nullptr;
//
//
//        int count = 1;
//        while(currentNode != nullptr)
//        {
//            prev = currentNode;
//
//            if((count % 2) == 0)
//            {
//                orginalNext = currentNode->next;
//                nodeQueue.push_back(this->meld(currentNode->left, currentNode));
//                currentNode = orginalNext;
//            }
//            else
//                currentNode = currentNode->next;
//
//            count++;
//        }
//
//        if((count % 2) != 0 && nodeQueue.back() != prev)
//            nodeQueue.push_back(prev);
//
////        cout << "Node Queue" << endl;
////        for(auto it = nodeQueue.begin(); it != nodeQueue.end(); it++)
////        {
////            (*it)->print();
////        }
////        cout << "End node queue" << endl;
//
//        auto nodeQueueIterator = nodeQueue.rbegin();
//        TripleLinkedListNode * right = *nodeQueueIterator;
//        nodeQueueIterator++;
//
//        for(TripleLinkedListNode * left; nodeQueueIterator != nodeQueue.rend(); nodeQueueIterator++)
//        {
//            left = *nodeQueueIterator;
//            right = this->meld(left, right);
//
////            cout << "Right" << endl;
////            right->print();
//        }
//
////        cout << "New root" << endl;
////        right->print();
//
//        this->root = right;
//        this->root->left = nullptr;
//        return oldMaxProcess;

        deque<TripleLinkedListNode *> nodeQueue;
        TripleLinkedListNode *currentNode = this->root->child;
        currentNode->left = nullptr;

        while(currentNode != nullptr) {
            nodeQueue.push_back(currentNode);
            currentNode = currentNode->next;
        }

        TripleLinkedListNode *left;
        TripleLinkedListNode *right;
        TripleLinkedListNode *melded;

        while(nodeQueue.size() >= 2) {
            left = nodeQueue.front();
            nodeQueue.pop_front();

            right = nodeQueue.front();
            nodeQueue.pop_front();

            melded = this->meld(left, right);
            nodeQueue.push_back(melded);
        }

        this->root = nodeQueue.front();
        this->nodesCount--;
    }
}

bool PairingHeap::isEmpty() {
    return false;
}

int PairingHeap::size() {
    return nodesCount;
}

ProcessControlBlock *PairingHeap::getMax() {

    if(this->root == nullptr) {
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
        currentNode->print();
        display(currentNode->next);
        display(currentNode->child);
    }
}

