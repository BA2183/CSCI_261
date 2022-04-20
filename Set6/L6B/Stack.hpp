#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp"
template<typename T>
class Stack {
    private:
        Node<T> *mHead;
        unsigned int mSize;
    public:
        // default
        Stack();
        ~Stack();
        Stack(const Stack<T>& OTHER);
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
Stack<T>::Stack() {
    mHead = nullptr;
    mSize = 0;
}
template<typename T>
Stack<T>::~Stack() {0
    Node<T> *pDeleteNode;
    Node<T> *pNextNode;
    pDeleteNode = mHead;
    while (pDeleteNode != nullptr) {
        pNextNode = pDeleteNode->pNext;
        delete pDeleteNode;
        pDeleteNode = pNextNode;
    }

    delete mHead;
}
template<typename T>
Stack<T>::Stack(const Stack<T>& OTHER) {
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
    }
}
// method
template<typename T>
Node<T>* Stack<T>::head() const {
    return mHead;
}
template<typename T>
unsigned int Stack<T>::size() const{
    return mSize;
}
template<typename T>
void Stack<T>::push(T VAL) {
    Node<T> *pNewNode = new Node<T>;
    Node<T> *pCurrent = mHead;
    pNewNode->value = VAL;
    pNewNode->pNext = nullptr;
    if (mSize == 0) {
        mHead = pNewNode;
    } else {
        while(pCurrent->pNext != nullptr) {
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pNext = pNewNode;
    }
    mSize++;
}
template<typename T>
T Stack<T>::peak() const {
    Node<T> *pCurrent = mHead;
    if(pCurrent != nullptr) {
        while(pCurrent->pNext != nullptr) {
            pCurrent = pCurrent->pNext;
        }
        return pCurrent->value;
    } else {
        return T();
    }
}
template<typename T>
T Stack<T>::pop() {
    Node<T> *pDeleteNode = mHead;
    if(pDeleteNode != nullptr) {
        while(pDeleteNode->pNext != nullptr) {
            pDeleteNode = pDeleteNode->pNext;
        }
        return pDeleteNode->value;
        delete pDeleteNode;
        mSize--;
    } else {
        return T();
    }
}
template<typename T>
bool Stack<T>::isEmpty() const {
    bool empty = true;
    if(mSize > 1) {
        empty = false;
    }
    return empty;
}
#endif