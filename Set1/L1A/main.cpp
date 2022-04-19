/*  CSCI 261: Lab 1A: Math Equation Solver
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This program will do 2 equations: Vector magnitude, line 14 to 28, and Average acceleration, from line 30 to 56.
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //calculation Vector Magnitude sqrt of x^2 + y^2
    //variables
    float xVector; 
    float yVector;
    
    //get inputs
    cout << "Enter The Numerical Value of The x Component of The Vector: ";
    cin >> xVector;
    cout << "Enter The Numerical Value of The y Component of The Vector: ";
    cin >> yVector;

    //calculate
    float vectorMag = sqrt(pow(xVector, 2) + pow(yVector, 2)); 
    cout << "The Distance of The Vector Is: "; 
    cout << vectorMag << endl; 

    //calculation of Average Acceleration by a = (x - xo) / (t - to)^2
    //varibles 
    float startDistance; 
    float endDistance;
    float startTime;
    float endTime;

    //input and calculate distance
    cout << "Enter The Numerical Value of The Start Distance: ";
    cin >> startDistance;
    cout << "Enter The Numerical Value of The End Distance: ";
    cin >> endDistance;
    float distanceDifference = endDistance - startDistance;

    //input and calculate time
    cout << "Enter The Numerical Value of The Start Time: ";
    cin >> startTime;
    cout << "Enter The Numerical Value of The End Distance: ";
    cin >> endTime;
    float timeDifference = endTime - startTime;
    float timeSquare = pow(timeDifference, 2);

    //calculate average acceleration
    float averageAcceleration = distanceDifference / timeSquare;
    cout << "The Average Acceleration is ";
    cout << averageAcceleration << endl;
    return 0;
}