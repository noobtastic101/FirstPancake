//
// Created by stoffel on 9/11/17.
//

#ifndef INC_1_TRIPLELINKEDLISTNODE_H
#define INC_1_TRIPLELINKEDLISTNODE_H


class TripleLinkedListNode
{
protected:
    TripleLinkedListNode * left;
    TripleLinkedListNode * child;
    TripleLinkedListNode * next;
public:
    TripleLinkedListNode(TripleLinkedListNode *left = nullptr, TripleLinkedListNode *child = nullptr, TripleLinkedListNode *next = nullptr);
};


#endif //INC_1_TRIPLELINKEDLISTNODE_H
