#include "LinkedList.h"
/**
 * @brief Construct a new Linked List object, head and tail pointer to be null and size be 0
 * 
 */
LinkedList::LinkedList() {
    mHead = nullptr;
    mTail = nullptr;
    mSize = 0;
}

/**
 * @brief Destroy the Linked List object, delete all nodes, update pointers and size accordingly
 * 
 */
LinkedList::~LinkedList() {
    Node *pNodeToDelete;
    Node *pNextNode;
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
 * @brief Returns the current value of the head node. If list is empty, returns -1 by default.
 * 
 * @return int value of the head node
 * @return -1 if empty by default
 */
int LinkedList::front() {
    if(mHead != nullptr) {
        return mHead->value;
    } else {
        return -1;
    }
}

/**
 * @brief Returns the current value of the back node. If list is empty, returns -1 by default.
 * 
 * @return int value of the back node
 * @return -1 if empty by default
 */
int LinkedList::back() {
    if(mTail != nullptr) {
        return mTail->value;
    } else {
        return -1;
    }
}

/**
 * @brief Return the size of the called linked list object
 * 
 * @return unsigned int the size of the linked list
 */
unsigned int LinkedList::size() {
    return mSize;
}

/**
 * @brief Returns a node pointer to a newly made node whose value is set to the parameter passed in and the next pointer is set to be null.
 * 
 * @param nodeValue node value
 * @return Node* the pointer of the node
 */
Node* LinkedList::makeNodeForValue(int nodeValue) {
    Node *pNewNode = new Node;
    pNewNode->value = nodeValue;
    pNewNode->pNext = nullptr;
    return pNewNode;
}

/**
 * @brief Adds a node to the head of the list with the provided parameter value. Updates the head & tail pointers and size as appropriate.
 * 
 * @param nodeValue the value of a new node to put at the front of the linked list
 */
void LinkedList::pushFront(int nodeValue) {
    Node *pNewNode = new Node;
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
void LinkedList::pushBack(int nodeValue) {
    Node *pNewNode = new Node;
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
 * @return int the value of the front node that is removed
 * @return -1 if empty by default
 */
int LinkedList::popFront() {
    if(mHead != nullptr) {
        Node *pNodeToDelete = new Node;
        pNodeToDelete = mHead;
        mHead = mHead->pNext;
        return pNodeToDelete->value;
        delete pNodeToDelete;

        mSize--;
    } else {
        return -1;
    }
}
