#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"
template<typename T>
class Queue {
    private:
        Node<T> *mHead;
        Node<T> *mTail;
        unsigned int mSize;
    public:
        // default
        Queue();
        ~Queue();
        Queue(const Queue<T>& OTHER);
        // method
        Node<T>* head() const;
        unsigned int size() const;
        void push(T VAL);
        T peak() const;
        T pop();
        bool isEmpty() const;
};

// default
template<typename T>
Queue<T>::Queue() {
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}
template<typename T>
Queue<T>::~Queue() {
    Node<T> *pDeleteNode;
    Node<T> *pNextNode;
    pDeleteNode = mHead;
    while (pDeleteNode != nullptr) {
        pNextNode = pDeleteNode->pNext;
        delete pDeleteNode;
        pDeleteNode = pNextNode;
    }
    mSize = 0;
    delete mHead;
}
template<typename T>
Queue<T>::Queue(const Queue<T>& OTHER) {
    mHead = OTHER.head();
    mSize = OTHER.size();
    Node<T> *pThisNode = mHead;
    Node<T> *pOtherNode = OTHER.head();
    while(pThisNode != nullptr) {
        Node<T> *pNewNode = new Node<T>;
        pNewNode->value = pThisNode->value;
        pNewNode->pNext = pThisNode->pNext;
        pOtherNode = pOtherNode->pNext;
        pThisNode = pOtherNode;

        if(pNewNode->pNext == nullptr) {
            mTail = pNewNode;
        }
    }
}
// method
template<typename T>
Node<T>* Queue<T>::head() const {
    if(mHead != nullptr) {
        return mHead;
    } else {
        return nullptr;
    }
}
template<typename T>
unsigned int Queue<T>::size() const {
    return mSize;
}
template<typename T>
void Queue<T>::push(T VAL) {
    Node<T> *pNewNode = new Node<T>;
    pNewNode->value = VAL;
    pNewNode->pNext = nullptr;
    if(mSize == 0) {
        mTail = pNewNode;
        mHead = pNewNode;
    } else {
        mTail->pNext = pNewNode;
        mTail = pNewNode;
    }
    mSize++;
}
template<typename T>
T Queue<T>::peak() const {
     if(mHead != nullptr) {
        return mHead->value;
    } else {
        return T();
    }
}
template<typename T>
T Queue<T>::pop() {
    if(mHead != nullptr) {
        Node<T> *pDeleteNode = mHead;
        mHead = mHead->pNext;
        T VAL = pDeleteNode->value;
        delete pDeleteNode;
        mSize--;
        return VAL;
    } else {
        return T();
    }
}
template<typename T>
bool Queue<T>::isEmpty() const {
    bool empty = true;
    if(mSize > 0) {
        empty = false;
    }
    return empty;
}
#endif