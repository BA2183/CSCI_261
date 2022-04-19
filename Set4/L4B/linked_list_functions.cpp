#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {
    // TODO #1
    Node *pNode = new Node;
    pNode->value = VALUE;
    pNode->pNext = nullptr;

    return pNode;
}

int linked_list_get_size(Node* pHead) {
    // TODO #2
    Node *pCurrentNode = new Node;
    pCurrentNode = pHead;
    int count = 0;

    while(pCurrentNode != nullptr) {
        count++;
        pCurrentNode = pCurrentNode->pNext;
    }

    return count;
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {
    // TODO #3
    Node *pNewNode = new Node;
    pNewNode->value = VALUE;
    pNewNode->pNext = pHead;

    pHead = pNewNode;
    return pHead;
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
    // TODO #4
    Node *pCurrentNode = new Node;
    int count = 0;
    int countTwo = 0;
    int listValue;
    pCurrentNode = pHead;

    while(pCurrentNode != nullptr) {
        count++;
        pCurrentNode = pCurrentNode->pNext;
    }

    if(POS >= count) {
        listValue = -1;
    } else if(POS < 0) {
        listValue = -1;
    } else {
        pCurrentNode = pHead;
        while(pCurrentNode != nullptr && countTwo <= POS) {
            countTwo++;
            listValue = pCurrentNode->value;
            pCurrentNode = pCurrentNode->pNext;
        }
    }
    
    return listValue;
}

int linked_list_min(Node* pHead) {
    // TODO #5
    Node *pCurrentNode = new Node;
    pCurrentNode = pHead;
    int minValue;
    if(pCurrentNode == nullptr) {
        minValue = -1;
    } else {
        minValue = pCurrentNode->value;
        while(pCurrentNode != nullptr) {
            if(minValue > pCurrentNode->value) {
                minValue = pCurrentNode->value;
            }
            pCurrentNode = pCurrentNode->pNext;
        }
    }
    
    return minValue;
}

int linked_list_max(Node* pHead) {
    // TODO #6
    Node *pCurrentNode = new Node;
    pCurrentNode = pHead;
    int maxValue;
    if(pCurrentNode == nullptr){
        maxValue = -1;
    } else {
        maxValue = pCurrentNode->value;
        while(pCurrentNode != nullptr) {
            if (maxValue < pCurrentNode->value) {
            maxValue = pCurrentNode->value;
            }
            pCurrentNode = pCurrentNode->pNext;
        }
    }

    return maxValue;
}

int linked_list_find(Node* pHead, const int TARGET) {
    // TODO #7
    Node *pCurrentNode = new Node;
    pCurrentNode = pHead;
    int count = 0;
    int foundAt = -1;

    if(pCurrentNode == nullptr) {
        foundAt = -1;
    } else {
        while(pCurrentNode != nullptr) {
            if(pCurrentNode->value == TARGET) {
                foundAt = count;
                break;
            } else {
                count++;
                pCurrentNode = pCurrentNode->pNext;
            }   
        }
    }
    
    return foundAt;
}

Node* linked_list_remove_node_from_front(Node* pHead) {
    // TODO #8
    if(pHead != nullptr) {
        Node *pNodeToDelete = new Node;
        pNodeToDelete = pHead;
        pHead = pHead->pNext;
        delete pNodeToDelete;
        return pHead;
    } else {
        return nullptr;
    }
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    // TODO #9
    Node *pCurrentNode = new Node;
    int count = 0;
    int countTwo = 0;
    pCurrentNode = pHead;

    while(pCurrentNode != nullptr) {
        count++;
        pCurrentNode = pCurrentNode->pNext;
    }

    if(POS < count) {
        pCurrentNode = pHead;
        while(pCurrentNode != nullptr) {
            if(countTwo == POS) {
                pCurrentNode->value = VALUE;
                break;
            } else {
                countTwo++;
                pCurrentNode = pCurrentNode->pNext;
            } 
        }
    } else if (POS < 0) {
        pCurrentNode = pHead;
        pCurrentNode->value = VALUE;
    }

    return pHead;
}