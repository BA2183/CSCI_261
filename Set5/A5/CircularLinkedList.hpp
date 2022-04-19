#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP
#include <iostream>
#include "DoublyNode.hpp"

using namespace std;

template<typename T>
class CircularLinkedList {
    private:
        DoublyNode<T> *mHead;
        unsigned int mSize;
    public:
        // default
        CircularLinkedList();
        ~CircularLinkedList();
        CircularLinkedList(const CircularLinkedList<T>& OTHER);

        // add and remove
        T get(const int POS);
        void set(const int POS, const T VAL);
        void add(const T VAL);
        void remove();

        // get value
        int size() const;
        DoublyNode<T>* head() const;

};

// DEFAULT
template<typename T>
CircularLinkedList<T>::CircularLinkedList() {
    mHead = nullptr; mSize = 0;
}
template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    DoublyNode<T> *pNodeToDelete;
    DoublyNode<T> *pNextNode;
    pNodeToDelete = mHead;
    while (pNodeToDelete != nullptr) {
        pNextNode = pNodeToDelete->pNext;
        delete pNodeToDelete;
        pNodeToDelete = pNextNode;
    }

    mSize = 0;
}
template<typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& OTHER) {
    mHead = OTHER.head();
    mSize = OTHER.size();
    int count = 0;
    DoublyNode<T> *pCurrentNode = mHead;
    while(count < mSize) {
        DoublyNode<T> *pNewNode = new DoublyNode<T>;
        pNewNode->value = pCurrentNode->value;
        pNewNode->pNext = pCurrentNode->pNext;
        pNewNode->pLast = pCurrentNode->pLast;

        pCurrentNode = pCurrentNode->pNext;
        count++;
    }
}
// ADD REMOVE
/**
 * @brief get value at POS postion of the list
 * 
 * @param POS postion index
 * @return T value at POS 
 */
template<typename T>
T CircularLinkedList<T>::get(const int POS) {
    DoublyNode<T> *pCurrentNode;
    int count = 0;

    if (POS < 0 || POS >= mSize) {
        return T();
    } else {
        pCurrentNode = mHead;
        while (pCurrentNode != nullptr && count < POS) {
            pCurrentNode = pCurrentNode->pNext;
            count++;
        }

        return pCurrentNode->value;
    }
}
/**
 * @brief set type T VAL value at POS postion of the list
 * 
 * @param POS position index
 * @param VAL value to set at POS
 */
template<typename T>
void CircularLinkedList<T>::set(const int POS, const T VAL) { 
    DoublyNode<T> *pCurrentNode;
    int count = 0;

    if (POS >= 0 || POS < mSize) {
        pCurrentNode = mHead;
        while (pCurrentNode != nullptr && count < POS) {
            pCurrentNode = pCurrentNode->pNext;
            count++;
        }

        pCurrentNode->value = VAL;
    }
}
/**
 * @brief add a new node in front/back of the list (it's circular)
 * 
 * @param VAL value of the new node
 */
template<typename T>
void CircularLinkedList<T>::add(const T VAL) {
    DoublyNode<T> *pNewNode = new DoublyNode<T>;
    pNewNode->value = VAL;
    pNewNode->pNext = nullptr;
    pNewNode->pLast = nullptr;
    if(mSize  == 0) {
        mHead = pNewNode;
    } else if(mSize == 1) {
        mHead->pLast = pNewNode;
        mHead->pNext = pNewNode;
        pNewNode->pLast = mHead;
        pNewNode->pNext = mHead;
    } else if(mSize >= 2) {
        mHead->pLast->pNext = pNewNode;
        pNewNode->pLast = mHead->pLast;
        mHead->pLast = pNewNode;
        pNewNode->pNext = mHead;
    }
    
    mSize++;
}
/**
 * @brief remove a value at the back/in front of the list
 */
template<typename T>
void CircularLinkedList<T>::remove() {
    if(mHead != nullptr && mHead->pLast != nullptr) {
        DoublyNode<T> *pDeleteNode;
        pDeleteNode = mHead->pLast;
        pDeleteNode->pLast->pNext = mHead;
        mHead->pLast = pDeleteNode->pLast;

        pDeleteNode->pLast = nullptr;
        pDeleteNode->pNext = nullptr;
        delete pDeleteNode;
    }
}

// GET VALUE
/**
 * @brief get size of the list
 * 
 * @return int size of the list
 */
template<typename T>
int CircularLinkedList<T>::size() const {
    return mSize;
}
/**
 * @brief return pointer at the start of the list
 * 
 * @return DoublyNode<T>*  pointer at the start of the list
 */
template<typename T>
DoublyNode<T>* CircularLinkedList<T>::head() const {
    return mHead;
}
#endif