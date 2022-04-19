#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

#include "ppm_functions.h"

/**
 * @brief Prints the options menu for which file to open.
 */
void print_file_options() {
    cout << "Which image to load?" << endl;
    cout << "  1. Brick" << endl;
    cout << "  2. Wallpaper" << endl;
    cout << "  3. Private" << endl;
    cout << "Enter 1, 2, or 3: ";
}

/**
 * @brief Prints the options menu for which file processing to perform.

 */
void print_operartion_options() {
    cout << "Which process to apply?" << endl;
    cout << "  1. Grayscale" << endl;
    cout << "  2. Inversion" << endl;
    cout << "Enter 1 or 2: ";
}

/**
 * @brief Prompts the user to enter a value. Validates the entered value is an integer and within the inclusive minimum-maximum range.
 * 
 * @param minValue minimum allowable integer value
 * @param maxValue maximum allowable integer value
 * @return int integer value chosen
 */
int get_user_input(int minValue, int maxValue) {
    int userInput;

    do {
        if (maxValue == 3) {
            print_file_options();
            cout << "Enter " << minValue << ", 2, or " << maxValue << ": ";
        } else {
            print_operartion_options();
            cout << "Enter " << minValue << " or " << maxValue << ": ";
        }
        
        cin >> userInput;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid input." << endl;
        } else if ((userInput < 1) || (userInput > 3)) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid input." << endl;
        }
    }  while ((userInput < minValue) || (userInput > maxValue));

    return userInput;
}

/**
 * @brief Opens the corresponding files for reading and writing based on the file and operation chosen. Verifies that both files successfully opened.
 * 
 * @param fileIn ifstream object to open
 * @param fileOut ofstream object to open
 * @param fileChoice integer corresponding to the file to open
 * @param operChoice integer corresponding to the operation to perform
 * @return true if both files successfully opened
 * @return false if otherwise
 */
bool open_file(ifstream& fileIn, ofstream& fileOut, int& fileChoice, int& operChoice) {

    if (fileChoice == 1) {
        fileIn.open("brick.ppm");
        cout << "Opening brick.ppm file.\n";
        if (operChoice == 1) {
            fileOut.open("brick_grayscale.ppm", ios::app);
            cout << "Writing brick_grayscale.ppm file.\n";
        } else {
            fileOut.open("brick_inverted.ppm", ios::app);
            cout << "Writing brick_inverted.ppm file.\n";
        }
    } else if (fileChoice == 2) {
        fileIn.open("wallpaper.ppm");
        cout << "Opening wallpaper.ppm file.\n";
        if (operChoice == 1) {
            fileOut.open("wallpaper_grayscale.ppm", ios::app);
            cout << "Writing wallpaper_grayscale.ppm file.\n";
        } else {
            fileOut.open("wallpaper_inverted.ppm", ios::app);
            cout << "Writing wallpaper_inverted.ppm file.\n";
        }
    } else {
        fileIn.open("private.ppm");
        cout << "Opening private.ppm file.\n";
        if (operChoice == 1) {
            fileOut.open("private_grayscale.ppm", ios::app);
            cout << "Writing private_grayscale.ppm file.\n";
        } else {
            fileOut.open("private_inverted.ppm", ios::app);
            cout << "Writing private_inverted.ppm file.\n";
        }
    }

    if (fileIn.fail() || fileOut.fail()) {
        fileIn.close();
        fileOut.close();
        return false;
    } else {
        return true;
    }
}

/**
 * @brief Reads the header block of the file
 * 
 * @param fileIn ifstream object to read from
 * @param ppmWidth integers corresponding to the width
 * @param ppmHeight integers corresponding to the height
 * @param ppmMaxValue integers corresponding to the max color value
 * @return true if the PPM type is P3
 * @return false otherwise
 */
bool read_header_infomation(ifstream& fileIn, int& ppmWidth, int& ppmHeight, int& ppmMaxValue) {
    string fileType;
    fileIn >> fileType;

    if (fileType != "P3") {
        return false;
    } else {
        fileIn >> ppmWidth;
        fileIn >> ppmHeight;
        fileIn >> ppmMaxValue;
        return true;
    }
}

/**
 * @brief Writes the header block of the file
 * 
 * @param fileOut ofstream object to write to
 * @param ppmWidth integers corresponding to the width
 * @param ppmHeight integers corresponding to the height
 * @param ppmMaxValue integers corresponding to the max color value
 */
void write_header_infomation(ofstream& fileOut, int& ppmWidth, int& ppmHeight, int& ppmMaxValue) {
    fileOut << "P3\n";
    fileOut << ppmWidth << " ";
    fileOut << ppmHeight << "\n";
    fileOut << ppmMaxValue << "\n";
}

/**
 * @brief Reads all the pixel data from the input file. For each pixel read, writes to the output file the modified pixel value based on the selected operation.
 * 
 * @param fileIn ifstream object to read from
 * @param fileOut ofstream object to write to
 * @param operChoice integers corresponding to the operation to perform
 * @param ppmWidth integers corresponding to the width
 * @param ppmHeight integers corresponding to the height
 * @param ppmMaxValue integers corresponding to the max color value
 */
void  read_and_write_modified_pixels(ifstream &fileIn, ofstream &fileOut, int &operChoice, int &ppmWidth, int &ppmHeight, int &ppmMaxValue) {
    // for each interger that represent a color value
    int colorValue;

    // total number of bits for entire picture
    int numPixel;
    numPixel = ppmWidth * ppmHeight;
    
    // red, blue, and green
    int redValue;
    int greValue;
    int bluValue;


    if (operChoice == 1) {
        int grayValue;
        // for each pixel, it will check for its 3 values
        for(int i = 0; i < numPixel; i++) {
            fileIn >> redValue;
            fileIn >> bluValue;
            fileIn >> greValue;

            // calculating gray value
            grayValue = 0.2989*redValue + 0.5870*greValue + 0.1140*bluValue;

            // write
            for(int j = 0; j < 3; j++) {
                fileOut << grayValue << "\n";
            }
            
        } 
    } else {
        // for each pixel, it will check for its 3 values
        for(int i = 0; i < numPixel; i++) {
            fileIn >> redValue;
            fileIn >> bluValue;
            fileIn >> greValue;

            // inverse values of pixel
            redValue = ppmMaxValue - redValue;
            bluValue = ppmMaxValue - bluValue;
            greValue = ppmMaxValue - greValue;

            // write
            fileOut << redValue << "\n";
            fileOut << bluValue << "\n";
            fileOut << greValue << "\n";
        } 
    }
       
}