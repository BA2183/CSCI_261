/*  CSCI 261: Lab 3C: Pointers
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 */

#include <iostream>
using namespace std;

int main() {
    int iNum = 9;
    double dNum = 14.25;

    int *pINum1 = &iNum;
    cout << "address of iNum using &: " << &iNum << endl;
    cout << "address of iNum using pINum1: " << pINum1 << endl;
    cout << "value of iNum using pINum1: " << *pINum1 << endl;

    /* int *pINum2 = &dNum;
     * main.cpp:19:20: error: cannot convert 'double*' to 'int*' in initialization
     *     int *pINum2 = &dNum;
     *                    ^~~~
     * makefile:21: recipe for target 'main.o' failed
     * mingw32-make: *** [main.o] Error 1
     */

    double *pDNum = &dNum;
    cout << "address of dNum using pDNum: " << pDNum << endl;
    cout << "value of dNum using pDNum: " << *pDNum << endl;

    iNum = 7;
    cout << "value of iNum using pINum1: " << *pINum1 << endl;
    int *pINum2 = pINum1;
    cout << "address of iNum using pINum2: " << pINum2 << endl;
    cout << "value of iNum using pINum2: " << *pINum2 << endl;

    return 0;
}