#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.hpp"
template<typename T>
class LinkedList {
    private:
    Node<T> *mHead;
    Node<T> *mTail;
    unsigned int mSize;

    public:
    // default methods
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>& OTHER);
    
    // add to list
    void pushFront(T nodeValue);
    void pushBack(T nodeValue);

    // access data member
    unsigned int size() const;
    Node<T>* head() const;
    Node<T>* tail() const;
    T at(const int mPosition) const;


};

// DEFAULT
template<typename T>
LinkedList<T>::LinkedList() {
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}
template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *pNodeToDelete;
    Node<T> *pNextNode;
    pNodeToDelete = mHead;
    while (pNodeToDelete != nullptr) {
        pNextNode = pNodeToDelete->pNext;
        delete pNodeToDelete;
        pNodeToDelete = pNextNode;
    }
    delete mHead;
    delete mTail;
    mSize = 0;
}
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& OTHER) {
    mSize = OTHER.size();
    mHead = OTHER.head();
    Node<T> *pCurrentNode = new Node<T>;
    Node<T> *pOtherCurrent = new Node<T>;
    pCurrentNode = mHead;
    pOtherCurrent = OTHER.head();
    while(pCurrentNode != nullptr) {
        Node<T> *pNewNode = new Node<T>;
        pNewNode->value = pCurrentNode->value;
        pNewNode->pNext = pCurrentNode->pNext;
        pOtherCurrent = pOtherCurrent->pNext;
        pCurrentNode = pOtherCurrent;
        if (pNewNode->pNext == nullptr) {
            mTail = pNewNode;
        }
    }
}

// ADD TO LIST
template<typename T>
void LinkedList<T>::pushFront(T nodeValue) {
    Node<T> *pNewNode = new Node<T>;
    pNewNode->value = nodeValue;
    pNewNode->pNext = mHead;
    if (mSize == 0) {
        mHead = pNewNode;
        mTail = pNewNode;
    } else {
        mHead = pNewNode;
    }
    mSize++;
}
template<typename T>
void LinkedList<T>::pushBack(T nodeValue) {
    Node<T> *pNewNode = new Node<T>;
    pNewNode->value = nodeValue;
    pNewNode->pNext = nullptr;
    if (mSize  == 0) {
        mTail = pNewNode;
        mHead = pNewNode;
    } else {
        mTail->pNext = pNewNode;
        mTail = pNewNode;
    }
    mSize++;
}

// ACCESS TO DATA MEMBER
template<typename T>
unsigned int LinkedList<T>::size() const{
    return mSize;
}
template<typename T>
Node<T>* LinkedList<T>::head() const{
    if (mHead != nullptr) {
        return mHead;
    } else {
        return nullptr;
    }
    
}
template<typename T>
Node<T>* LinkedList<T>::tail() const{
    if (mTail != nullptr) {
        return mTail;
    } else {
        return nullptr;
    }
}
template<typename T>
T LinkedList<T>::at(const int mPosition) const {
    Node<T> *pCurrentNode;
    int count = 0;
    if (mPosition < 0 || mPosition >= mSize) {
        return T();
    } else {
        pCurrentNode = mHead;
        while (pCurrentNode != nullptr && count < mPosition) {
            pCurrentNode = pCurrentNode->pNext;
            count++;
        }
        return pCurrentNode->value;
    }
}
#endif //LINKEDLIST_H