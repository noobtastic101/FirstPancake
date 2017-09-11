//
// Created by stoffel on 9/11/17.
//

#include "TripleLinkedListNode.h"

TripleLinkedListNode::TripleLinkedListNode(TripleLinkedListNode *left, TripleLinkedListNode *child,
                                           TripleLinkedListNode *next) : left(left), child(child), next(next)
{

}

TripleLinkedListNode::~TripleLinkedListNode() {
    //TODO: Write me!
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

ProcessControlBlock *TripleLinkedListNode::assignLeft(ProcessControlBlock *process) {
    if()
}
