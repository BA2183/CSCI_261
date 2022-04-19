/*  CSCI 261: Lab 5B - Sorting I: Sorting a List
 *
 * Author: Duan Nguyen
 * Reference: class slide, Amy Hong helped a lot with debugging
 * 
 * This program will create a list, and then will sort it using bubble sort
 */
#include "LinkedList.hpp"

int main() {
    // create list
    LinkedList<int>* linkedList = new LinkedList<int>;
    linkedList->pushback(6);
    linkedList->pushback(2);
    linkedList->pushback(7);
    linkedList->pushback(9);
    linkedList->pushback(5);
    linkedList->pushback(1);
    linkedList->pushback(8);
    linkedList->pushback(3);
    linkedList->pushback(4);
    // print list forward
    cout << "The list printed forwards: ";
    linkedList->print(); cout << "\n";
    
    // sort the list
    if (linkedList->all_sort() == true){
        cout << "List is already sorted\n";
    } else {
        cout << "sorting...\n";
        while (linkedList->all_sort() != true) {
            linkedList->bubble_sort();
            //(*linkedList).print(); cout << "\n";
        }
    }
    
    // print sorted list
    cout << "The list sorted: ";
    linkedList->print();
    
    // delete and clean up
    delete linkedList;
    return 0;
}