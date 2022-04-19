/*  CSCI 261: Lab 2C: Coordinate Converter
 *
 * Author: Duan Nguyen
 * Reference: class slide, cmath glossary
 * 
 * This program will convert polar coordinate to cartesian, and vice versa
 * Start with asking user for choosing the conversion direction
 * based on the choice, the program will ask for radius and angle, or x and y
 * in return for x and y, or radius and angle
 * or else, an error will occur
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// prototype function
void polar_to_cartesian(const double radius, const double angle, double& yCoord, double& xCoord);
void cartesina_to_polar(const double yCoord, const double xCoord, double& radius, double& angle);

int main() {
    // variable
    double radius, angle, yCoord, xCoord;
    char userChoice;

    // user input for choosing conversion
    cout << "Choose direction of the conversion: (P/C)\n(P)olar to Cartesian\n(C)artesian to Polar" << endl;
    cin >> userChoice;

    // P or p will ask for input of radius and angle 
    if (userChoice == 'P' || userChoice == 'p') {
        cout << "Enter value for radius: " << endl;
        cin >> radius;
        cout << "Enter value for angle in degree: " << endl;
        cin >> angle;

        // convert
        polar_to_cartesian(radius, angle, yCoord, xCoord);
        cout << "Cartesian coordinate is (" << fixed << setprecision(3) << yCoord << "," << xCoord << ") from Polar coordinate (" << radius << "," << angle << ")" << endl;

    // C or c will ask for input of x and y 
    } else if(userChoice == 'C' || userChoice == 'c') {
        cout << "Enter value for x coordinate: " << endl;
        cin >> xCoord;
        cout << "Enter value for y coordinate: " << endl;
        cin >> yCoord;

        // convert
        cartesina_to_polar(yCoord, xCoord, radius, angle);
        cout << "Polar coordinate is (" << fixed << setprecision(3) << radius << "," << angle << ") from Cartesian coordinate (" << xCoord << "," << yCoord << ")" << endl;

    // wrong input will result in error and break out
    } else {
        cerr << "Error: wrong input";
        return -1;
    }

}

/*
 * @brief converter inputed radius and angle to x and y coordinate
 * @param radius mutliply with cos of angle or sin of angle
 * @param angle in cos or sin
 * @param yCoord output y coordinate
 * @param xCoord output x coordinate
 * @return product of radius and cos of angle or sin of angle to x or y
 */
void polar_to_cartesian(const double radius, const double angle, double& yCoord, double& xCoord) {
    double pi(3.14159265);
    yCoord = radius * sin( angle * pi / 180);
    xCoord = radius * cos( angle * pi / 180);
}

/*
 * @brief converter inputed x and y coordinate to radius and angle in degree
 * @param yCoord input y coordinate, in square root of sum of y square and x square, and in arc tan of quotient of y and x
 * @param xCoord input x coordinate, in square root of sum of y square and x square, and in arc tan of quotient of y and x
 * @param radius output radius
 * @param angle output angle in degree
 * @return radius from square root of sum of y square and x square, and angle from arc tan of quotient of y and x
 */
void cartesina_to_polar(const double yCoord, const double xCoord, double& radius, double& angle) {
    double pi(3.14159265);
    radius = sqrt(yCoord*yCoord + xCoord*xCoord);
    angle = atan(yCoord/xCoord) * 180 / pi;
}