/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *TripleLinkedList.cpp
 *
 *Purpose: The purpose of TripleLinkedList.cpp is to implement the triple linked list into our program.
 * This link list contains all the values of the Process control block.
 * A triple linked list has three components, left, right, and parent. Left and right are children on the parent
 * above it. This link list will be organized from the pairing heap.
 */
#include "TripleLinkedList.h"


//getHighestPriority will check to see if the node on the left or right is larger, and return the larger value.
TripleLinkedListNode *TripleLinkedList::getHighestPriority(TripleLinkedListNode *left, TripleLinkedListNode *right) {
    if(left->process->getPriority() > right->process->getPriority())
        return left;
    else
        return right;
}

Pair<TripleLinkedListNode *>

//lowestAndHigestPriority will return the respective lower and higher priority of two nodes
TripleLinkedList::lowestAndHighestPriority(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
    if(left->process->getPriority() > right->process->getPriority())
        return Pair<TripleLinkedListNode *>(right, left);
    else
        return Pair<TripleLinkedListNode *>(left, right);
}

//destructor for our triple linked list
TripleLinkedList::~TripleLinkedList()
{
    del(this->root);
}

//function to delete the nodes of the linked list
void TripleLinkedList::del(TripleLinkedListNode *currentNode)
{
    if(currentNode != nullptr) {
        del(currentNode->left);
        del(currentNode->next);
        del(currentNode->child);

        delete currentNode;
    }
}

