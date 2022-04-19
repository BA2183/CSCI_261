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
    LinkedList(const LinkedList& OTHER);
    LinkedList& operator=(const LinkedList& OTHER);
    
    void pushFront(int nodeValue);
    void pushBack(int nodeValue);
    int popFront();

    int front();
    int back();
    unsigned int size() const;
    Node* getHead() const;
    Node* getTail() const;
    int at(const int mPosition);


};

#endif //LINKEDLIST_H