/*  CSCI 261: Lab 5A: Double The Fun
 *
 * Author: Duan Nguyen
 * Reference: class slide, Amy Hong helped a lot with debugging
 * 
 * This will be used to test all of the methods of the DoublyLinkedList class.
 */
#include "DoublyLinkedList.hpp"

int main() {
    // step 01: Create a doubly linked list of integers
    DoublyLinkedList<int>* doublyList = new DoublyLinkedList<int>;
    // step 02: Add the value 6 at pos 0
    (*doublyList).insert(0, 6);
    // step 03: Add the value 5 at pos 0
    (*doublyList).insert(0, 5);
    // step 04: Add the value 7 at pos 5
    (*doublyList).insert(5, 7);
    // step 05: Add the value 1 at pos -3
    (*doublyList).insert(-3, 1);
    // step 06: Add the value 2 at pos 1
    (*doublyList).insert(1, 2);
    // step 07: Add the value 9 at pos 2
    (*doublyList).insert(2, 9);
    // step 08: Add the value 3 at pos 2
    (*doublyList).insert(2, 3);
    // step 09: Print the list forwards
    cout << "The list printed forwards: ";
    (*doublyList).print();
    // step 10: Print the list backwards
    cout << "The list printed backwards: ";
    (*doublyList).printReverse();
    // step 11: Set pos 3 to be 4
    (*doublyList).set(3, 4);
    // step 12: Print the list forwards
    cout << "The list printed forwards: ";
    (*doublyList).print();
    // step 13: Remove pos -2
    (*doublyList).remove(-2);
    // step 14: Remove pos 9
    (*doublyList).remove(9);
    // step 15: Remove pos 2
    (*doublyList).remove(2);
    // step 16: Get and print pos 2
    cout << "The value at position 2: " << (*doublyList).get(2) << "\n";
    // step 17: Print the size
    cout << "The size of the list: " << (*doublyList).size() << "\n";
    // step 18: Print the list forwards
    cout << "The list printed forwards: ";
    (*doublyList).print();
    // step 19: Delete the doubly linked list
    delete doublyList;

    return 0;
}