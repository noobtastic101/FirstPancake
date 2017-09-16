//
// Created by stoffel on 9/11/17.
//

#include "TripleLinkedList.h"


TripleLinkedListNode *TripleLinkedList::getHighestPriority(TripleLinkedListNode *left, TripleLinkedListNode *right) {
    if(left->process->getPriority() > right->process->getPriority())
        return left;
    else
        return right;
}

Pair<TripleLinkedListNode *>
TripleLinkedList::lowestAndHighestPriority(TripleLinkedListNode *left, TripleLinkedListNode *right)
{
    if(left->process->getPriority() > right->process->getPriority())
        return Pair<TripleLinkedListNode *>(right, left);
    else
        return Pair<TripleLinkedListNode *>(left, right);
}

TripleLinkedList::~TripleLinkedList()
{
    TripleLinkedListNode * currentNode = this->root;
    TripleLinkedListNode * next;

    while(currentNode != nullptr)
    {
        if(currentNode->child != nullptr)
        {
            currentNode = currentNode->child;
            continue;
        }

        next = currentNode->next;
        delete currentNode;
        currentNode = currentNode->next;
    }
}

void TripleLinkedList::display(TripleLinkedListNode *currentNode)
{
    if(currentNode == nullptr)
        return;

    currentNode = currentNode->child;

    this->display(currentNode);



    currentNode = currentNode->next;

    this->display(currentNode);



    while(currentNode != this->root)
    {
        currentNode->print();
        currentNode = currentNode->left;


    }
}

