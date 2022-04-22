/*  CSCI 261: Lab 6A - Multidimensional Data
 *
 * Author: Duan Nguyen
 * Reference: old code and class slides
 * 
 */
#include "multi_functions.h"
// code snipet at A3
int main(int argc, char* argv[]) {
    // get file name
    string fileName;
    ifstream fileIn;
    if(argc == 1) {
        cout << "Enter the name of the file to open: ";
        cin >> fileName;
    } else if(argc == 2) {
        fileName = argv[1];
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    
    // opening file
    bool fileOpen = open_file(fileIn, fileName);
    if (!fileOpen) {
        cerr << "Could not open file, shutting down. . .\n";
        return -1;
    } else {
        cout << "File successfully opened!\n\n";
    }

    // read file
    int n, m;
    fileIn >> n;
    LinkedList<LinkedList<int>*> lGrid;
    for(int i = 0; i < n; i++) {
        LinkedList<int>* lList = new LinkedList<int>;
        for(int j = 0; j < n; j++) {
            fileIn >> m;
            lList->pushBack(m);
        }
        lGrid.pushBack(lList);
    }

    // print
    cout << "the table is:\n";
    print(lGrid);
    // find min max
    int maxValue, minValue;
    maxValue = max(lGrid);
    minValue = min(lGrid);
    cout << "The min is: " << minValue << "\nThe max is: " << maxValue;
    // clean up
    // delete lGrid;
    return 0;
}