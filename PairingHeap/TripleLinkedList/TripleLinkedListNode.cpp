
/*
 *Created by Kyle Gullicksen and Benjamin Siegel
 *Date written: 9/4/2017
 *CS433 Assignment #1
 *
 *
 *TripleLinkedListNode.cpp
 *
 *Purpose: Assign the nodes to the link list, being: left, child, and next.
 * This file creates the tree used in TripleLinkedList.cpp
 */

#include "TripleLinkedListNode.h"

TripleLinkedListNode::TripleLinkedListNode(TripleLinkedListNode *left, TripleLinkedListNode *child,
                                           TripleLinkedListNode *next) : left(left), child(child), next(next)
{

}

TripleLinkedListNode::~TripleLinkedListNode() {
    delete this->left;
    delete this->next;
    delete this->child;
    delete this->process;
}

ProcessControlBlock *TripleLinkedListNode::assignChild(ProcessControlBlock *process)
{
    return
        this->assignChild(new TripleLinkedListNode(process));
}

TripleLinkedListNode::TripleLinkedListNode(ProcessControlBlock *process) : process(process) {}

ProcessControlBlock *TripleLinkedListNode::assignChild(TripleLinkedListNode *newChild)
{
    TripleLinkedListNode * oldChild = this->child;
    this->child = newChild;

    this->child->next = oldChild;
    this->child->left = this;

    if(oldChild != nullptr)
        oldChild->left = this->child;
}

/*
 * Display the IDs and the priorties of the processes in the queue
 */


void TripleLinkedListNode::print()
{
    this->process->print();

//    if(this->next == nullptr)
//        cout << "Next is null" << endl;
//    else {
//        cout << "Next is: " << endl;
//        this->next->print();
//    }
//
//    if(this->left == nullptr)
//        cout << "left is null" << endl;
//    else {
//        cout << "left is: " << endl;
//        this->left->print();
//    }
//
//
//    if(this->child == nullptr)
//        cout << "child is null" << endl;
//    else {
//        cout << "child is: " << endl;
//        this->child->print();
//    }
//
//    cout << "" << endl;
//    cout << "" << endl;
//    cout << "" << endl;

}

TripleLinkedListNode::TripleLinkedListNode()
= default;
