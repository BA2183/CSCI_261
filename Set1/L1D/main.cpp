/*  CSCI 261: Lab 1D: Holy Loops Batman!
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This program will do 3 different loops of the same 11 "Na", and finishes with "Batman"
 */
#include <iostream>

using namespace std;

int main() {
    //while loop
    int x = 0;
    while ( x <= 10)
    {
        cout << "Na" << endl;
        x++;
    }
    
    cout << "Batman" << endl;

    //while do loop
    int y = 0;
    do
    {
        cout << "Na" << endl;
        y++;
    } while ( y <= 10);
    
    cout << "Batman" << endl;

    // for loop
    int z;
    for (z = 0; z <= 10; z++)
    {
        cout << "Na" << endl;
    }

    cout << "Batman" << endl;

    return 0;
}