/*  CSCI 261: Lab 2B: Procedural Programming with Functions
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This program will ask for user input of range of minimum and maximum value in the main function.
 * Then program will loop 10 times, using the min and max for the functions that was deined above as generate_random_interger, to generate a random interger, and generate_random_float, to generate a random float.
 * Then it will print the value of each 10 times.
 * Then it will retun 0 to finish.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
// random interger
int generate_random_interger( int &max, int &min) {
    rand(); // throw away first digit

    int randInt = rand() % (max - min + 1) + min;
    return randInt;
}

// random float
float generate_random_float( int &max, int &min) {
    rand();

    float randFloat = rand() / (double)RAND_MAX * (max - min) + min ;
    return randFloat;
}

// main function
int main() {
    srand(time(0)); // seed by time

    //variable
    int minValue;
    int maxValue;
    
    //input min and max
    cout << "Please enter the minimum value:" << endl;
    cin >> minValue;
    cout << "Please enter the maximum value:" << endl;
    cin >> maxValue;

    //print random intergr x 10
    cout << "10 random intergers:" << endl;
    int x;
    for (x = 1; x <= 10; x++) {
        int genInt = generate_random_interger(maxValue, minValue);
        cout << genInt << endl;
    }

    //print random float x 10
    cout << "10 random floats:" << endl;
    int y;
    for (y = 1; y <= 10; y++) {
        float genFloat = generate_random_float(maxValue, minValue);
        cout << fixed << setprecision(3) <<genFloat << endl;
    }
    
    //progrom complete
    return 0;
}