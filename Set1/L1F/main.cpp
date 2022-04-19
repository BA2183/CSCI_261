/* CSCI 261: Errors
 *
 * Author: Duan Nguyen
 *
 *    This program illustrates a variety of common errors.
 *    Fix the errors in each section.

Copyright 2022 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */
// include <cmath> for power function
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to Loop World" << endl;

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = changing "ci" to "cin" at line 54, changing "<" in "i < numIter" to "<=" at line 56
// TESTS: in1: 5 - out1: 15; in2: 7 - out2: 28; in3: 37 - out3: 703; in4: 1 - out4: 1

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int sum;      // Accumulates the total
    int i;        // Used as loop control variable
    int numIter;  // The number of times to iterate
    cout << "Enter a number greater than 1 to sum up to: ";
    // syntax error, mispelled
    cin >> numIter;
    // logic erros, the for loop stop at the inclusive point
    for (i = 1; i <= numIter; ++i) {
         sum += i;
     }
    cout << "The sum of the numbers from 1 to " << numIter << " (inclusive) is: " << sum << endl;

// SECTION II: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = changing "cou" to "cout" at line 69, remove "total = 0;" at line 83, changing ">>" to "<<" at line 87
// TESTS: in1: 2, 17.50, 12.50 - out1: 12.50; in2: 2, 12.50, 17.50 - out2: 17.50; in3: 2, 17.50, 12.50 - out1: 30

    cout << endl;
    cout << "******************" << endl;
    // syntax error, mispelled 
    cout << "Section II" << endl;
    cout << "******************" << endl;

    double total;     // Accumulates total
    double price;     // Gets next price from user
    int numItems;     // Number of items
    int counter = 1;  // Loop control counter

    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    while (counter <= numItems) {
        // logic error, the total keep reassign in every loop and reset the total value
        //total = 0;
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        // syntax error, ">>" instead of "<<" for cout
        cout << endl;
        // logic error, the totel is the last item price instead
        total += price;
        counter++;
    }
    cout << "The total price of all items is: " << total << endl;

// SECTION III: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = assige "counter2" to 1 at line 106 and "sum2" to 0 at line 103, add ";" to the end of line 111, add increament for counter2 at line 116, change "sum2" to "numIter2" at line 119
// TESTS: in1: 5 - out1: 15; in2: 7 - out2: 28; in3: 15 - out3: 15; in4: 1 - out4: 1

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;
    // compiler error, sum2 was not assigned
    int sum2 = 0;
    // compiler error, counter2 was not assigned
    int counter2 = 1;
    int numIter2;

    cout << "What number do you wish me to sum from 1 to?" << endl;
    // syntax errors, missing ";"
    cin >> numIter2;

    do {
        sum2 += counter2;
        // logic error, no increament for counter2, the loop continue infinitely
        counter2++;
        cout << "Sum so far: " << sum2 << endl;
        // logic error, sum2 will alway increase higher than counter2 without increament, infinite loop
    } while (counter2 <= numIter2);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << numIter2 << " (inclusive) as " << sum2 << endl;


// SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly
// FIX = assign i3 to 1 instead of numIter3 at line 146, change "i3 < 0" to  "i3 <= numIter3" as ending value
// TESTS: in1: 5 - out1: 55, in2:7 - out2:140; in3: 10 - out3: 385; in4: 1 - out4: 1

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum of 1 squared to ? squared (inclusive)" << endl;
    
    int numIter3;
    cin >> numIter3;

    int sum3 = 0;
    // logic error, i3 is assign to input value instead of starting to sum from squared 1
    // logic error, i3 is set to be great than 0 instead of an ending value, result in infinite loop
    for (int i3 = 1; i3 <= numIter3; i3++) {
    // logic error, sum is added with i3 is powered by i3 instead of 2
        sum3 += i3*i3;
    }

    cout << "The sum of squares from 1 to " << numIter3 << " is: " << sum3 << endl;

// SECTION V: update comment below on how you fixed this section's code, and tests run
// that show loop is working properly (syntax error, "/" instead of "//" for comment)
// FIX = change "/" to "//" at line 154, defined and assign counter4 and sum4 at line 168 to 169, change 10 to numIter4 at line 171, remove "counter4++;" at line 177
// TESTS: in1: 5 - out1: 225, in2:7 - out2: 784; in3: 10 - out3: 3025; in4: 1 - out4: 1

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "I will now calculate ";
    cout << "the sum from 1 cubed to ? cubed (inclusive)" << endl;

    int numIter4;
    cin >> numIter4;
    // logic error, counter4 and sum4 was not assigned or defined
    int counter4 = 1;
    int sum4 = 0;
    // logic error, stop the loop before 10 instead of input number
    while (counter4 <= numIter4) {
        sum4 += counter4 * counter4 * counter4;
        counter4++;
    }
    // logic error, increament of counter is outside the loop
    //counter4++;

    cout << "The sum of cubes from 1 to " << numIter4 << " is: " << sum4 << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
} 
