/* CSCI 261: Assignment 2: A2 - PPM Image Editor
 *
 * Author: Duan Nguyen
 * Reference: class slide, C++ glossery, Vincent at Tutor hoursm, and lecturor, Amy Hong, for help finding the error at ppm_function.h file
 * 
 * This program will allow user to choose 1 of 3 ppm files to read and modified it to either gray scale or inverted.
 * All of the fnctions are in ppm_function.ppm and link together by ppm_function.h
 * The program will start with asking user for choosing the file to modify, then choosing the modifier.
 * This will also check for valid input, if not, an error will occur and ask user to input again.
 * Then the program will open and start according files.
 * If the file open successfully, the program will check for valid file type.
 * Then it will modified each pixel of the file, and put all of the result in the according ppm file.
 * If any error occurs in this state, The program will alert the user and close the files.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

#include "ppm_functions.h"

using namespace std;

int main() {
   // get file input
   int minValue, maxvalue, fileChoice, operChoice;
   minValue = 1;
   maxvalue = 3;
   fileChoice = get_user_input(minValue, maxvalue);

   // get file input
   minValue = 1;
   maxvalue = 2;
   operChoice = get_user_input(minValue, maxvalue);
   
   // open file
   bool fileOpen, validHeader;
   ifstream fileIn;
   ofstream fileOut;
   fileOpen = open_file(fileIn, fileOut, fileChoice, operChoice);

   if (fileOpen) {
      // check header
      int ppmWidth, ppmHeight, ppmMaxValue;
      validHeader = read_header_infomation(fileIn, ppmWidth, ppmHeight, ppmMaxValue);

      if (validHeader) {
         write_header_infomation(fileOut, ppmWidth, ppmHeight, ppmMaxValue);
         // modified pixel
         read_and_write_modified_pixels(fileIn, fileOut, operChoice, ppmWidth, ppmHeight, ppmHeight);
         
      } else {
         // close upon invalid file type or wrong header
         cerr << "Invalid Image Type / File Header.";
         return -1;
      }
   } else {
      // file failed to open
      cerr << "Error Opening Files.";
      return -1;
   }

   // return 0 for finishing
   return 0;
}

