/*  CSCI 261: Lab 5D - Sorting II & Recursion II: Merge Sort via the Call Stack
 *
 * Author: Duan Nguyen
 * Reference: class slide, Eddie from Section B for explaining that a while-loop would be better, tutor hours, Amy Hong helped a lot with debugging
 * 
 * makes list and uses merge sort
 */
#include "merge_functions.h"

int main() {
    // create list
    LinkedList<int>* aList = new LinkedList<int>;
    aList->pushback(4);
    aList->pushback(3);
    aList->pushback(8);
    aList->pushback(1);
    aList->pushback(5);
    aList->pushback(9);
    aList->pushback(7);
    aList->pushback(2);
    aList->pushback(6);
    // print list forward
    cout << "The list printed forwards: ";
    aList->print(); cout << "\n";
    // sort
    merge_sort(aList);
    // print list forward
    cout << "The list printed forwards: ";
    aList->print(); cout << "\n";
    // clean up and finish
    delete aList;
    return 0;
}