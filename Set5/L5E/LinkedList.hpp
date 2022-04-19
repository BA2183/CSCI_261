#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.hpp"
#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
    private:
    Node<T> *mHead;
    Node<T> *mTail;
    unsigned int mSize;

    Node<T>* makeNodeForValue(T nodeValue);

    public:
    LinkedList();

    ~LinkedList();
    LinkedList(const LinkedList<T>& OTHER);
    LinkedList<T>& operator=(const LinkedList<T>& OTHER);
    
    void pushback(T nodeValue);
    void print() const;
    
    unsigned int size() const;
    Node<T>* head() const;
    Node<T>* tail() const;
    T at(const int mPosition) const;

    bool all_sort();
    bool all_invert();
    void bubble_sort();
    void bubble_invert();
};

// Methods
/**
 * @brief Construct a new Linked List object, head and tail pointer to be null and size be 0
 * 
 */
template<typename T>
LinkedList<T>::LinkedList() {
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}

/**
 * @brief Destroy the Linked List object, delete all nodes, update pointers and size accordingly
 * 
 */
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

/**
 * @brief Perform a deep copy of the passed object. The newly constructed list will have the same size and ordered values as the passed list.
 * 
 * @param OTHER A LinkedList object
 */
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

/**
 * @brief Deallocate the current list. Perform a deep copy of the passed object. The new list will have the same size and ordered values as the passed list.
 * 
 * @param OTHER A LinkedList object
 * @return LinkedList<T>& Reference to a LinkedList object
 */
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& OTHER) {
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

/**
 * @brief Return the size of the called linked list object
 * 
 * @return unsigned int the size of the linked list
 */
template<typename T>
unsigned int LinkedList<T>::size() const{
    return mSize;
}

/**
 * @brief allow other function to get access to the head pointer of the linked list
 * 
 * @return Node* pointer of the head
 */
template<typename T>
Node<T>* LinkedList<T>::head() const{
    if (mHead != nullptr) {
        return mHead;
    } else {
        return nullptr;
    }
    
}

/**
 * @brief allow other function to get access to the tail pointer of the linked list
 * 
 * @return Node* pointer of the tail
 */
template<typename T>
Node<T>* LinkedList<T>::tail() const{
    if (mTail != nullptr) {
        return mTail;
    } else {
        return nullptr;
    }
}

/**
 * @brief get the value at the provided position. -1 if out of range.
 * 
 * @param mPosition position on the linked list list, start from 0
 * @return T the value at that position
 */
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

/**
 * @brief Returns a node pointer to a newly made node whose value is set to the parameter passed in and the next pointer is set to be null.
 * 
 * @param nodeValue node value
 * @return Node* the pointer of the node
 */
template<typename T>
Node<T>* LinkedList<T>::makeNodeForValue(T nodeValue) {
    Node<T> *pNewNode = new Node<T>;
    pNewNode->value = nodeValue;
    pNewNode->pNext = nullptr;
    return pNewNode;
}

/**
 * @brief Adds a node to the tail of the list with the provided parameter value. Updates the head & tail pointers and size as appropriate.
 * 
 * @param nodeValue the value of a new node to put at the back of the linked list
 */
template<typename T>
void LinkedList<T>::pushback(T nodeValue) {
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

/**
 * @brief print valve hold inside each node of the list
 * 
 * @tparam T 
 */
template<typename T>
void LinkedList<T>::print() const {
    Node<T> *pCurrentNode;
    pCurrentNode = mHead;
    cout << "{ ";
    while (pCurrentNode != nullptr) {
        cout << pCurrentNode->value << " ";
        pCurrentNode = pCurrentNode->pNext;
    }
    cout << "}";
}

/**
 * @brief check if the linked list is sorted or not
 * 
 * @tparam T 
 * @return true sorted
 * @return false not sorted
 */
template<typename T>
bool LinkedList<T>::all_sort() {
    bool allSorted = true;
    Node<T> *pCurrentNode;
    pCurrentNode = mHead;
    while (pCurrentNode != nullptr && pCurrentNode->pNext != nullptr) {
        if (pCurrentNode->value > pCurrentNode->pNext->value) {
            allSorted = false;
            break;
        } else {
            pCurrentNode = pCurrentNode->pNext;
        }
    }
    return allSorted;
}

template<typename T>
bool LinkedList<T>::all_invert() {
    bool allSorted = true;
    Node<T> *pCurrentNode;
    pCurrentNode = mHead;
    while (pCurrentNode != nullptr && pCurrentNode->pNext != nullptr) {
        if (pCurrentNode->value < pCurrentNode->pNext->value) {
            allSorted = false;
            break;
        } else {
            pCurrentNode = pCurrentNode->pNext;
        }
    }
    return allSorted;
}

/**
 * @brief bubble sort the list once
 * 
 * @tparam T 
 */
template<typename T>
void LinkedList<T>::bubble_sort() {
    Node<T> *pCurrentNode;
    pCurrentNode = mHead;
    T tempValue;
    while (pCurrentNode != nullptr && pCurrentNode->pNext != nullptr) {
        if (pCurrentNode->value > pCurrentNode->pNext->value) {
            tempValue = pCurrentNode->value;
            pCurrentNode->value = pCurrentNode->pNext->value;
            pCurrentNode->pNext->value = tempValue;
        }
        
        pCurrentNode = pCurrentNode->pNext;
    }
}

template<typename T>
void LinkedList<T>::bubble_invert() {
    Node<T> *pCurrentNode;
    pCurrentNode = mHead;
    T tempValue;
    while (pCurrentNode != nullptr && pCurrentNode->pNext != nullptr) {
        if (pCurrentNode->value < pCurrentNode->pNext->value) {
            tempValue = pCurrentNode->value;
            pCurrentNode->value = pCurrentNode->pNext->value;
            pCurrentNode->pNext->value = tempValue;
        }
        
        pCurrentNode = pCurrentNode->pNext;
    }
}
#endif //LINKEDLIST_H