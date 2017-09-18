/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *PairingHeap.cpp
 *
 *Purpose: Pairing heap is the algorithm we chose to implement our triple link list.
 *
 */

#include "PairingHeap.h"

/*
 * Display the IDs and the priorties of the processes in the queue
 */

//Print is our main print function that gets called from main to display the ID and Priorities.
void PairingHeap::print()
{
    this->display(this->root);
}

//Put will either create a new node or meld a preexisting node with a new node.
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

//Meld is the main reasoning behind a pairing heap; this function checks the values of two nodes and compares them
//against one another. The larger value becomes the parent of the smaller values.
TripleLinkedListNode *PairingHeap::meld(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
//    cout << "Melding these two" << endl;
//    left->print();
//    right->print();

    Pair<TripleLinkedListNode *> lowestAndHighest = this->lowestAndHighestPriority(left, right);
    lowestAndHighest.right->assignChild(lowestAndHighest.left);

    return lowestAndHighest.right;
}

//Remove max function will find the largest node by melding every 2 nodes into a new pairing heap. Once the largest
//node is found, it will be removed from the tree.
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

//isEmpty will return false if the pairing heap is empty
bool PairingHeap::isEmpty() {
    return false;
}

//size will return the nodescount which is the number of nodes currently in the tree
int PairingHeap::size() {
    return nodesCount;
}

//getMax will return the largest node in the tree
ProcessControlBlock *PairingHeap::getMax() {

    if(this->root == nullptr) {
        cout << "GAH WHY NO ROOT" << endl;
        return nullptr;
    }
    
    return this->root->process;
}

//pop_n_get_back will pop the top node from the deque
TripleLinkedListNode *PairingHeap::pop_n_get_back(deque<TripleLinkedListNode *> &dq)
{
    TripleLinkedListNode * backNode = dq.back();
    dq.pop_back();

    return backNode;
}

//display is our function for displaying all values in the tree
void PairingHeap::display(TripleLinkedListNode *currentNode)
{
    if(currentNode != nullptr)
    {
        display(currentNode->left);
        display(currentNode->next);
        currentNode->print();
    }
}

