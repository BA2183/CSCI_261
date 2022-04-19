/*  CSCI 261: Lab 4E: A Linked List Class Part III: Test, Copy, Print
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This will be used to test all of the methods of the LinkedList class.
 */
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    // step 1: Create a LinkedList object using the default constructor
    LinkedList* listZeroOne = new LinkedList;

    // step 2: Print out its initial size (should be zero)
    cout << "LIST 01 TEST\nlist 01 size: " << (*listZeroOne).size() << endl;

    // step 3: Add the following values to the list in order: front 1, back 2, front 3, back 4, front 5, back 6.
    (*listZeroOne).pushFront(1);
    (*listZeroOne).pushBack(2);
    (*listZeroOne).pushFront(3);
    (*listZeroOne).pushBack(4);
    (*listZeroOne).pushFront(5);
    (*listZeroOne).pushBack(6);

    // step 4: Print out the new size
    cout << "list 01 new size: " << (*listZeroOne).size() << endl;

    // step 5: Print out the contents of the list
    cout << "list 01 content: ";
    for (int i = 0; i < (*listZeroOne).size(); i++) {
        cout << (*listZeroOne).at(i) << " ";
    }
    cout << "\n";

    // step 6: Create a second LinkedList object using the default constructor
    LinkedList* listZeroTwo = new LinkedList;

    // step 7: Print out its initial size
    cout << "\nLIST 01 & 02 TEST\nlist 02 size: " << (*listZeroTwo).size() << "\n";

    // step 8: Assign the first LinkedList to the second LinkedList
    *listZeroTwo = *listZeroOne;

    // step 9: Print out both their sizes
    cout << "list 01 size: " << (*listZeroOne).size() << "\nlist 02 new size: " << (*listZeroTwo).size() << "\n";

    // step 10: Add the following values to the first list in order: front 7, back 8.
    (*listZeroOne).pushFront(7);
    (*listZeroOne).pushBack(8);

    // step 11: Print out both their sizes and contents
    cout << "\nlist 01 size new: " << (*listZeroOne).size() << "\nlist 01 content: ";
    for (int j = 0; j < (*listZeroOne).size(); j++) {
        cout << (*listZeroOne).at(j) << " ";
    }

    cout << "\nlist 02 size: " << (*listZeroTwo).size() << "\nlist 02 content: ";
    for (int k = 0; k < (*listZeroTwo).size(); k++) {
        cout << (*listZeroTwo).at(k) << " ";
    }
    cout << "\n";

    // step 12: Create a third LinkedList using the copy constructor and providing the first LinkedList as an argument
    LinkedList (*listZeroThree) = new LinkedList((*listZeroOne));

    // step 13: Print out all three sizes
    cout << "\nLIST 01, 02 & 03 TEST\nlist 01 size: " << (*listZeroOne).size() << "\nlist 02 size: " << (*listZeroTwo).size() << "\nlist 03 size: " << (*listZeroThree).size() << "\n";

    // step 14: Add the following values to the first list in order: front 9, back 10
    (*listZeroOne).pushFront(9);
    (*listZeroOne).pushBack(10);

    // step 15: Print out all three sizes
    cout << "\nlist 01 size new: " << (*listZeroOne).size() << "\nlist 02 size: " << (*listZeroTwo).size() << "\nlist 03 size: " << (*listZeroThree).size() << "\n";

    // step 16: Print out the contents of all three lists
    cout << "\nlist 01 content: ";
    for (int x = 0; x < (*listZeroOne).size(); x++) {
        cout << (*listZeroOne).at(x) << " ";
    }
    cout << "\n";

    cout << "list 02 content: ";
    for (int y = 0; y < (*listZeroTwo).size(); y++) {
        cout << (*listZeroTwo).at(y) << " ";
    }
    cout << "\n";

    cout << "list 03 content: ";
    for (int z = 0; z < (*listZeroThree).size(); z++) {
        cout << (*listZeroThree).at(z) << " ";
    }
    cout << "\n";

    // step 17: Delete all three lists to clean up all memory
    cout << "deleting list 01, 02, and 03 . . . ";
    delete listZeroOne;
    delete listZeroTwo;
    delete listZeroThree;
    cout << "delete sucess!";
    
    return 0;
}