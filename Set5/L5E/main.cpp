/*  CSCI 261: Lab 5E - Procedural and Object-Oriented
 *
 * Author: Duan Nguyen
 * Reference: class slide, tutor hours, Amy Hong helped a lot with debugging
 * 
 * makes list of Rectangle object, prints in term of base times height, sorts by comparing base then height then prints, and finally sorts in reversed order then prints.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.hpp"
#include "Rectangle.hpp"

using namespace std;

int main() {
    // ask for number of rectangles
    int recNum;
    cout << "Enter the Number of Rectangle to Make: ";
    cin >> recNum;
    // make list for n number of rectangles
    LinkedList<Rectangle> *rList = new LinkedList<Rectangle>;
    // assign random base and height
    srand(time(0));
    rand(); float constFloat = 17.25;
    Rectangle *tempRec = new Rectangle;

    for(int i = 0; i < recNum; i++) {
        tempRec->setHeight(rand() / constFloat);
        tempRec->setBase(rand() / constFloat);
        // cout << tempRec->getBase() << "x" << tempRec->getHeight() << "\n";
        rList->pushback(*tempRec);
    }

    // print the list
    cout << "The list printed forwards: " << "{ ";
    for(int j = 0; j < recNum; j++) {
        cout << ((rList->at(j)).getBase()) * ((rList->at(j)).getHeight()) << " ";
    }
    cout << "}\n";
    
    // sort the list
    if (rList->all_sort() == true){
        cout << "List is already sorted\n";
    } else {
        cout << "sorting...\n";
        while (rList->all_sort() != true) {
            rList->bubble_sort();
        }
    }
    
    // print sorted list
    cout << "The list printed forwards: " << "{ ";
    for(int j = 0; j < recNum; j++) {
        cout << ((rList->at(j)).getBase()) * ((rList->at(j)).getHeight()) << " ";
    }
    cout << "}\n";

    // sort the list (invert order)
    if (rList->all_invert() == true){
        cout << "List is already sorted\n";
    } else {
        cout << "sorting...\n";
        while (rList->all_invert() != true) {
            rList->bubble_invert();
        }
    }

    // print sorted list
    cout << "The list printed forwards: " << "{ ";
    for(int j = 0; j < recNum; j++) {
        cout << ((rList->at(j)).getBase()) * ((rList->at(j)).getHeight()) << " ";
    }
    cout << "}\n";
    // delete and clean up
    delete rList;
    delete tempRec;
    return 0;
}