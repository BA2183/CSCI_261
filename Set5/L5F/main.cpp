/*  CSCI 261: Lab 5F - A Needle in the Haystack
 *
 * Author: Duan Nguyen
 * Reference: class slide, tutor hour, Amy Hong helped a lot with debugging
 * 
 * make list of n random integer, n is how much integer the user want
 * put all intergers into list then print
 * bubble sort the list then print
 * then will ask how many interger too look for for and what interger to look for
 */
#include <cstdlib>
#include <ctime>
#include "LinkedList.hpp"

int main() {
    // step 1: Ask the user how many integers to enter
    cout << "Enter Number of Integer: "; int n; cin >> n; cout << "\n";

    // step 2: Create a list of n integers
    LinkedList<int> *aList = new LinkedList<int>;

    // step 3: Assign each element a random value
    srand(time(0));
    rand();
    for(int m = 0; m < n; m++) {
        aList->pushback(rand());
    }

    // step 4: Print the list forwards
    cout << "The list printed forwards: "; aList->print(); cout << "\n";

    // step 5: Sort the list ascending
    if (aList->all_sort() == true){
        cout << "List is already sorted\n";
    } else {
        cout << "sorting...\n";
        while (aList->all_sort() != true) {
            aList->bubble_sort();
        }
    }

    // step 6: Print the list forwards
    cout << "The list printed forwards: "; aList->print(); cout << "\n";

    // step 7: Ask the user how many target values they wish to search for
    cout << "Enter Number of Integers to Look for: "; int o, p, foundAt; cin >> o;

    // step 8: For each target value entered by the user, perform an iterative binary search to find the target.
    for(int q = 0; q < o; q++) {
        cout << "Enter Ingeger to Look for: "; cin >> p;
        // do binary search here with p as target value
        foundAt = aList->find(p);
        if(foundAt < 0) {
            cout << "That Integer Does Not Exist in This List.\n";
            q--; // retry
        } else {
            cout << "The Integer is At Index: " << foundAt << "\n";
        }
    }

    delete aList;
    return 0;
}