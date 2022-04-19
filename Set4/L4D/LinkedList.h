#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
    private:
    Node *mHead;
    Node *mTail;
    unsigned int mSize;

    Node* makeNodeForValue(int nodeValue);

    public:
    LinkedList();
    ~LinkedList();
    
    void pushFront(int nodeValue);
    void pushBack(int nodeValue);
    int popFront();

    int front();
    int back();
    unsigned int size();
};

#endif //LINKEDLIST_H