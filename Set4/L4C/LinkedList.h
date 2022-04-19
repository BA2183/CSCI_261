#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
    public:
    Node *mHead;
    Node *mTail;
    unsigned int mSize;

    Node* makeNodeForValue(int nodeValue);
    void pushFront(int nodeValue);
    void pushBack(int nodeValue);
    int popFront();
};

#endif //LINKEDLIST_H