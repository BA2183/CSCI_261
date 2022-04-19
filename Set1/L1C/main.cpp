/*  CSCI 261: lab 1C: Random Generation & Classification
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This program will ask user to input a minimum and maximum range, then output a random value between, and then classify which quartile the value is in
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //variable
    float minValue;
    float maxValue;
    
    //input max and min
    cout << "Please enter the minimum value: ";
    cin >> minValue;
    cout << "Please enter the maximum value: ";
    cin >> maxValue; 


    //get random seed
    srand(time(0));
    //get the first "random" digit away
    rand();
    float randomValue = rand() / (double)RAND_MAX * (maxValue - minValue) + minValue;
    //get random float between max and min
    cout << "Random value is: ";
    cout << randomValue << endl;

    //get the ratio between random value and max
    float ratio = randomValue / maxValue;
    //cout << ratio;

    //check for quartile
    if (ratio <= 0.25f) {
        cout << "This is in the first quartile" << endl;
    } else if (ratio > 0.25f && ratio <= 0.50f) {
        cout << "This is in the second quartile" << endl;
    } else if (ratio > 0.50f && ratio <= 0.75f) {
        cout << "This is in the third quartile" << endl;
    } else {
        cout << "This is in the fourth quartile" << endl;
    }
    
    return 0;
}