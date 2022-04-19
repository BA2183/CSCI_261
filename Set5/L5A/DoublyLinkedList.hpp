#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "DoublyNode.hpp"
#include <iostream>

using namespace std;

template<typename T>
class DoublyLinkedList {
    private:
    DoublyNode<T> *mHead;
    DoublyNode<T> *mTail;
    unsigned int mSize;

    public:
    DoublyLinkedList();

    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& OTHER);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& OTHER);

    T get(const int POS) const;
    void set(const int POS, const T VAL);
    void insert(const int POS, const T VAL);
    void remove(const int POS);

    int size() const;
    DoublyNode<T>* head() const;
    DoublyNode<T>* tail() const;
    void print() const;
    void printReverse() const;
};

// methods
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DoublyNode<T> *pNodeToDelete;
    DoublyNode<T> *pNextNode;
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
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& OTHER) {
    mSize = OTHER.size();
    mHead = OTHER.head();
    DoublyNode<T> *pCurrentNode;
    pCurrentNode = OTHER.head();

    while(pCurrentNode != nullptr) {
        DoublyNode<T> *pNewNode = new DoublyNode<T>;
        pNewNode->value = pCurrentNode->value;
        pNewNode->pNext = pCurrentNode->pNext;
        pNewNode->pLast = pCurrentNode->pLast;

        pCurrentNode = pCurrentNode->pNext;

        if (pNewNode->pNext = nullptr) {
            mTail = pNewNode;
        }
    }
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& OTHER) {
    mSize = OTHER.size();
    mHead = OTHER.head();
    DoublyNode<T> *pCurrentNode;
    pCurrentNode = OTHER.head();

    while(pCurrentNode != nullptr) {
        DoublyNode<T> *pNewNode = new DoublyNode<T>;
        pNewNode->value = pCurrentNode->value;
        pNewNode->pNext = pCurrentNode->pNext;
        pNewNode->pLast = pCurrentNode->pLast;

        pCurrentNode = pCurrentNode->pNext;

        if (pNewNode->pNext = nullptr) {
            mTail = pNewNode;
        }
    }
}

template<typename T>
T DoublyLinkedList<T>::get(const int POS) const {
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

template<typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL) {
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
template<typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL) {
    DoublyNode<T> *pNewNode = new DoublyNode<T>;
    DoublyNode<T> *pCurrentNode;
    pNewNode->value = VAL;

    if (POS <= 0) {
        pNewNode->pNext = mHead;
        pNewNode->pLast = nullptr;
        if (mSize == 0) {
            mHead = pNewNode;
            mTail = pNewNode;
        } else {
            mHead->pLast = pNewNode;
            mHead = pNewNode;
        }
    } else if (POS >= mSize) {
        pNewNode->pNext = nullptr;
        if (mSize == 0) {
            mTail = pNewNode;
            mHead = pNewNode;
        } else {
            mTail->pNext = pNewNode;
            pNewNode->pLast = mTail;
            mTail = pNewNode;
        }
    } else {
        int count = 1;
        pCurrentNode = mHead;

        while (pCurrentNode != nullptr && count < POS) {
            pCurrentNode = pCurrentNode->pNext;
            count++;
        }

        pNewNode->pLast = pCurrentNode;
        pCurrentNode->pNext->pLast = pNewNode;
        pNewNode->pNext = pCurrentNode->pNext;
        pCurrentNode->pNext = pNewNode;
    }   

    mSize++;
}

template<typename T>
void DoublyLinkedList<T>::remove(const int POS) {
    if (POS <= 0) {
        if (mHead != nullptr) {
            DoublyNode<T> *pNodeToDelete;
            pNodeToDelete = mHead;
            mHead = mHead->pNext;
            mHead->pLast = nullptr;
            delete pNodeToDelete;
        }
    } else if (POS >= mSize) {
        if (mTail != nullptr) {
            DoublyNode<T> *pNodeToDelete;
            pNodeToDelete = mTail;
            mTail = mTail->pLast;
            mTail->pNext = nullptr;
            delete pNodeToDelete;
        }
    } else {
        int count = 0;
        DoublyNode<T> *pNodeToDelete;
        DoublyNode<T> *pCurrentNode;

        pCurrentNode = mHead;
        while (pCurrentNode != nullptr && count < POS) {
            pCurrentNode = pCurrentNode->pNext;
            count++;
        }

        pNodeToDelete = pCurrentNode;
        pCurrentNode->pLast->pNext = pCurrentNode->pNext;
        pCurrentNode->pNext->pLast = pCurrentNode->pLast;
        delete pCurrentNode;
    }

    mSize--;
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return mSize;
}

template<typename T>
DoublyNode<T>* DoublyLinkedList<T>::head() const {
    if (mHead != nullptr) {
        return mHead;
    } else {
        return nullptr;
    }
}

template<typename T>
DoublyNode<T>* DoublyLinkedList<T>::tail() const {
    if (mHead != nullptr) {
        return mTail;
    } else {
        return nullptr;
    }
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    DoublyNode<T> *pCurrentNode;
    pCurrentNode = mHead;
    while (pCurrentNode != nullptr) {
        cout << pCurrentNode->value << " ";
        pCurrentNode = pCurrentNode->pNext;
    }
    cout << "\n";
}

template<typename T>
void DoublyLinkedList<T>::printReverse() const {
    DoublyNode<T> *pCurrentNode;
    pCurrentNode = mTail;
    while (pCurrentNode != nullptr) {
        cout << pCurrentNode->value << " ";
        pCurrentNode = pCurrentNode->pLast;
    }
    cout << "\n";
}
#endif