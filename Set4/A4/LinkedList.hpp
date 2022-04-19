#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.hpp"
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
    
    void pushFront(T nodeValue);
    void pushBack(T nodeValue);
    T popFront();

    T front() const;
    T back() const;
    unsigned int size() const;
    Node<T>* getHead() const;
    Node<T>* getTail() const;
    T at(const int mPosition) const;


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
    mHead = OTHER.getHead();
    Node<T> *pCurrentNode = new Node<T>;
    Node<T> *pOtherCurrent = new Node<T>;
    pCurrentNode = mHead;
    pOtherCurrent = OTHER.getHead();
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
    mHead = OTHER.getHead();
    Node<T> *pCurrentNode = new Node<T>;
    Node<T> *pOtherCurrent = new Node<T>;
    pCurrentNode = mHead;
    pOtherCurrent = OTHER.getHead();
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
 * @brief Returns the current value of the head node. If list is empty, returns -1 by default.
 * 
 * @return T value of the head node
 * @return T() if empty by default
 */
template<typename T>
T LinkedList<T>::front() const {
    if(mHead != nullptr) {
        return mHead->value;
    } else {
        return T();
    }
}

/**
 * @brief Returns the current value of the back node. If list is empty, returns -1 by default.
 * 
 * @return T value of the back node
 * @return -T() if empty by default
 */
template<typename T>
T LinkedList<T>::back() const {
    if(mTail != nullptr) {
        return mTail->value;
    } else {
        return T();
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
Node<T>* LinkedList<T>::getHead() const{
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
Node<T>* LinkedList<T>::getTail() const{
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
 * @brief Adds a node to the head of the list with the provided parameter value. Updates the head & tail pointers and size as appropriate.
 * 
 * @param nodeValue the value of a new node to put at the front of the linked list
 */
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

/**
 * @brief Adds a node to the tail of the list with the provided parameter value. Updates the head & tail pointers and size as appropriate.
 * 
 * @param nodeValue the value of a new node to put at the back of the linked list
 */
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

/**
 * @brief Deletes the node at the head of the list and returns its value. Updates the head & tail pointers and size as appropriate. If list is empty, returns -1 by default.
 * 
 * @return T the value of the front node that is removed
 * @return T() if empty by default
 */
template<typename T>
T LinkedList<T>::popFront() {
    if(mHead != nullptr) {
        Node<T> *pNodeToDelete = new Node<T>;
        pNodeToDelete = mHead;
        mHead = mHead->pNext;
        return pNodeToDelete->value;
        delete pNodeToDelete;

        mSize--;
    } else {
        return T();
    }
}

#endif //LINKEDLIST_H