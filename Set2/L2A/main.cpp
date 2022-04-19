/*  CSCI 261: Lab 2A: The Secret Moosage
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This program will open both input and output file, then check if any error occour from 14 to 21. 
 * Then declare a variable to hold one character at line 26.
 * Then it will get indiviual character from the input file to check if it's a new line character to add a new line, change "~" to space, offset everything else by 1, and at the same time, write C in output file from line 28 to 38
 * Then it will close both file at line 42 and 43
 * Then return 0 to finish the program
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // open the file
    ifstream fileInput("secretMessage.txt");
    ofstream fileOutput("dechiperdMessage.txt");

    // check for error
    if (fileInput.fail() || fileOutput.fail()) {
        cerr << "Error Opening Files";
        return -1;
    }

    // declare character variable
    char c;
    
    while(fileInput.get(c)) {
        if ( c == '~') {
            c = ' ';
            fileOutput << c; // write space back into file
        } else if (c == '\n'){
            c = '\n';
            fileOutput << c; // add new line
        } else {
            fileOutput << (char)( c + 1); // write character with 1 offset to file
        }
    }

    // close files
    fileInput.close();
    fileOutput.close();
    // return to end program
    return 0;
}