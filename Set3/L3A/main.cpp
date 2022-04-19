/*  CSCI 261: Lab 3A: 
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 */
#include <iostream>

using namespace std;

int main() {
    int numList[15];
    cout << "Enter up to 15 non-zero numbers. Enter zero to signal the end of the data or enter all 15 items:\n";

    // input number into array
    int i = 0;
    int userInput;
    do
    {
        cout << "Number " << i + 1 << ": ";
        cin >> userInput;

        if (userInput != 0) {
            numList[i] = userInput;
        } else {
            break;
        }
        
        i++;
    } while ((i <= 14));

    //cout << i << "\n";

    // print out numbers in array
    cout << "The numbers are: ";
    for (int j = 0; j < i; j++) {
        cout << numList[j] << " ";
    }
    cout << "\n";

    // find max and min
    int maxValue, minValue;
    maxValue = minValue = numList[0];

    for (int k = 0; k < i; k++) {
        if (numList[k] < minValue) {
            minValue = numList[k];
        } else if (numList[k] > maxValue) {
            maxValue = numList[k];
        }
    }

    cout << "The maximum value is: " << maxValue << "\n";
    cout << "The minimum value is: " << minValue << "\n";

    // ending message
    cout << "Have a nice day!";
    
    //finish
    return 0;
}
