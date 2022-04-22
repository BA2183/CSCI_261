#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp"
template<typename T>
class Stack {
    private:
        Node<T> *mHead;
        Node<T> *mTail;
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
    mTail = nullptr;
    mSize = 0;
}
template<typename T>
Stack<T>::~Stack() {
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
        mTail = pNewNode;
    } else {
        mTail->pNext = pNewNode;
        mTail = pNewNode;
    }
    mSize++;
}
template<typename T>
T Stack<T>::peak() const {
    if(mTail != nullptr) {
        return mTail->value;
    } else {
        return T();
    }
}
template<typename T>
T Stack<T>::pop() {
    Node<T> *pBeforeTail = mHead;
    if(pBeforeTail != nullptr && mSize != 1) {
        while(pBeforeTail->pNext != mTail) {
            pBeforeTail = pBeforeTail->pNext;
        }
    }
    if(mTail != nullptr) {
        Node<T> *pDeleteNode = mTail;
        T VAL = pDeleteNode->value;
        delete pDeleteNode;
        if(mSize != 1) {
            mTail = pBeforeTail;
        }
        mSize--;
        return VAL;
    } else {
        return T();
    }
}
template<typename T>
bool Stack<T>::isEmpty() const {
    bool empty = true;
    if(mSize > 0) {
        empty = false;
    }
    return empty;
}
#endif