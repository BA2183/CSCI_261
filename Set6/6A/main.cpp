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
    int row, col;
    char inChar;
    fileIn >> row;
    fileIn >> col;
    DoublyLinkedList<DoublyLinkedList<char>*> lGrid;
    for(int i = 0; i < row; i++) {
        DoublyLinkedList<char>* lList = new DoublyLinkedList<char>;
        for(int j = 0; j < col; j++) {
            fileIn >> inChar;
            lList->insert(col, inChar);
        }
        lGrid.insert(row, lList);
    }

    // boolean table
    DoublyLinkedList<DoublyLinkedList<bool>*> checkTable;
    for(int x = 0; x < row; x++) {
        DoublyLinkedList<bool>* checkList = new DoublyLinkedList<bool>;
        for(int y = 0; y < col; y++) {
            checkList->insert(col, false);
        }
        checkTable.insert(row, checkList);
    }
    // ask for option
    int userInput = operation_input(1, 2);
    Position startPos;
    // get start
        // BFS
    if(userInput == 1) {
        Queue<Position> posList;
        posList.push(startPos);
        startPos = findStartUsingBFS(lGrid, checkTable, posList);
        cout << startPos.rowNum << "x" << startPos.colNum;
        //findEndUsingBFS(lGrid, checkTable, posList, startPos);
        // DFS
    } else {
        Stack<Position> posList;
        posList.push(startPos);
    }
    // print
    print(lGrid);
    return 0;
}