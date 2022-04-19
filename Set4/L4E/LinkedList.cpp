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
 * @brief Perform a deep copy of the passed object. The newly constructed list will have the same size and ordered values as the passed list.
 * 
 * @param OTHER A LinkedList object
 */
LinkedList::LinkedList(const LinkedList& OTHER) {
    mSize = OTHER.size();
    mHead = OTHER.getHead();
    Node *pCurrentNode = new Node;
    Node *pOtherCurrent = new Node;
    pCurrentNode = mHead;
    pOtherCurrent = OTHER.getHead();
    while(pCurrentNode != nullptr) {
        Node *pNewNode = new Node;
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
 * @return LinkedList& Reference to a LinkedList object
 */
LinkedList& LinkedList::operator=(const LinkedList& OTHER) {
    mSize = OTHER.size();
    mHead = OTHER.getHead();
    Node *pCurrentNode = new Node;
    Node *pOtherCurrent = new Node;
    pCurrentNode = mHead;
    pOtherCurrent = OTHER.getHead();
    while(pCurrentNode != nullptr) {
        Node *pNewNode = new Node;
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
unsigned int LinkedList::size() const{
    return mSize;
}

/**
 * @brief allow other function to get access to the head pointer of the linked list
 * 
 * @return Node* pointer of the head
 */
Node* LinkedList::getHead() const{
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
Node* LinkedList::getTail() const{
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
 * @return int the value at that position
 */
int LinkedList::at(const int mPosition) {
    Node *pCurrentNode;
    int count = 0;

    if (mPosition < 0 || mPosition >= mSize) {
        return -1;
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
