/*  CSCI 261: Lab 4A: Array vs Linked List
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * perform the same set of operations twice. First using a dynamically allocated array and next with a dynamically allocated Linked List.
 */
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *pNext;
};

int main() {
    // using dynamic array
    int *pThreeInt = new int[3];
    int inInt;

    cout << "Enter 3 intergers\n";
    for (int i = 0; i < 3; i++) {
        cout << "Integer" << i + 1 << ": ";
        cin >> inInt;
        pThreeInt[i] = inInt;
    }

    cout << "Array in order: ";
    for (int j = 0; j < 3; j++) {
        cout << pThreeInt[j] << " ";
    }
    
    cout << "\nArry in reverse order: ";
    for (int k = 0; k < 3; k++) {
        cout << pThreeInt[2 - k] << " ";
    }
    
    delete[] pThreeInt;

    // using linked list
    cout << "\nEnter the first interers: ";
    cin >> inInt;
    Node *pHeadNode = new Node;
    pHeadNode->value = inInt;
    pHeadNode->pNext = nullptr;

    cout << "Enter the second interers: ";
    cin >> inInt;
    Node *pNextNode = new Node;
    pNextNode->value = inInt;
    pNextNode->pNext = nullptr;

    cout << "Enter the third interers: ";
    cin >> inInt;
    Node *pNextNextNode = new Node;
    pNextNextNode->value = inInt;
    pNextNextNode->pNext = nullptr;

    pHeadNode->pNext = pNextNode;
    pNextNode->pNext = pNextNextNode;
    
    cout << "Linked list in order: " << pHeadNode->value << " " << pHeadNode->pNext->value << " " << pHeadNode->pNext->pNext->value << "\n";
    cout << "Linked list in reverse order: " << pHeadNode->pNext->pNext->value << " " << pHeadNode->pNext->value << " " << pHeadNode->value << "\n";

    delete pHeadNode, pNextNode, pNextNextNode;
}