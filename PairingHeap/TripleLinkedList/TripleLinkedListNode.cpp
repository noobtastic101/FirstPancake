//
// Created by stoffel on 9/11/17.
//

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

ProcessControlBlock *TripleLinkedListNode::assignChild(TripleLinkedListNode *child) {
    TripleLinkedListNode * oldChild = this->child;
    //this->child = new TripleLinkedListNode(process);
    this->child = child;

    this->child->next = oldChild;
    this->child->left = this;
    oldChild->left = this->child;
}

/*
 * Display the IDs and the priorties of the processes in the queue
 */


void TripleLinkedListNode::print()
{
    this->process->print();
}

TripleLinkedListNode::TripleLinkedListNode()
{

}

ProcessControlBlock *TripleLinkedListNode::assignLeft(ProcessControlBlock *process) {

}
