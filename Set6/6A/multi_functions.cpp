#include "multi_functions.h"
bool open_file(ifstream& fileIn, const string fileName) {
    // open file
    fileIn.open(fileName);
    cout << "Opening file \"" << fileName << "\"\n";

    // check if file open
    if (fileIn.fail()) {
        fileIn.close();
        return false;
    } else {
        return true;
    }
}
void print(DoublyLinkedList<DoublyLinkedList<char>*>& lGrid) {
    DoublyNode<DoublyLinkedList<char>*>* pCurrent = lGrid.head();
    DoublyNode<char>* pSecondCurrent;
    while(pCurrent != nullptr) {
        pSecondCurrent = (pCurrent->value)->head();
        while(pSecondCurrent != nullptr) {
            cout << pSecondCurrent->value << " ";
            pSecondCurrent = pSecondCurrent->pNext;
        }
        cout << "\n";
        pCurrent = pCurrent->pNext;
    }
}
Position findStartUsingBFS(const DoublyLinkedList<DoublyLinkedList<char>*>& lGrid, DoublyLinkedList<DoublyLinkedList<bool>*> checkTable, Queue<Position> posList) {
    Position curPos;
    DoublyNode<DoublyLinkedList<bool>*>* curNode;
    while(!posList.isEmpty()) {
        curPos = posList.pop();
        if(lGrid.get(curPos.rowNum)->get(curPos.colNum) == 'S') {
            return curPos;
            break;
        } else {
            curNode = checkTable.head();
            for(int z = 0; z < (checkTable.size() - 1); z++) {
                curNode = curNode->pNext;
            }
            curNode->value->set(curPos.colNum, true);
            // get neighbor node
            if((curPos.rowNum + 1) < lGrid.size() && checkTable.get(curPos.rowNum + 1)->get(curPos.colNum) == false) {
                posList.push(Position(curPos.rowNum + 1, curPos.colNum));
            }
            if((curPos.colNum + 1) < lGrid.get(curPos.rowNum)->size() && checkTable.get(curPos.rowNum)->get(curPos.colNum + 1) == false) {
                posList.push(Position(curPos.rowNum, curPos.colNum + 1));
            }
            if((curPos.rowNum - 1) >= 0 && checkTable.get(curPos.rowNum - 1)->get(curPos.colNum) == false) {
                posList.push(Position(curPos.rowNum - 1, curPos.colNum));
            } 
            if((curPos.colNum - 1) >= 0 && checkTable.get(curPos.rowNum)->get(curPos.colNum - 1) == false) {
                posList.push(Position(curPos.rowNum, curPos.colNum - 1));
            }
        }
    }
}
void findStartUsingDFS(const DoublyLinkedList<DoublyLinkedList<char>*>& lGrid, DoublyLinkedList<DoublyLinkedList<bool>*> checkTable, Stack<Position> posList, Position& startPos);
void findEndUsingBFS(DoublyLinkedList<DoublyLinkedList<char>*>& lGrid, DoublyLinkedList<DoublyLinkedList<bool>*>& checkTable, Queue<Position> posList, Position& startPos) {
    Position curPos;
    DoublyNode<DoublyLinkedList<bool>*>* curNodeOne;
    DoublyNode<DoublyLinkedList<char>*>* curNodeTwo;
    while(!posList.isEmpty()) {
        curPos = posList.pop();
        if(lGrid.get(curPos.rowNum)->get(curPos.colNum) == 'E') {
            break;
        } else {
            curNodeOne = checkTable.head();
            curNodeTwo = lGrid.head();
            for(int z = 0; z < (checkTable.size() - 1); z++) {
                curNodeOne = curNodeOne->pNext;
                curNodeTwo = curNodeTwo->pNext;
            }
            curNodeOne->value->set(curPos.colNum, true);
            curNodeTwo->value->set(curPos.colNum, '@');
            
            // get neighbor node
            if((curPos.rowNum + 1) < lGrid.size() && checkTable.get(curPos.rowNum + 1)->get(curPos.colNum) == false && lGrid.get(curPos.rowNum + 1)->get(curPos.colNum) != '#') {
                posList.push(Position(curPos.rowNum + 1, curPos.colNum));
            }
            if((curPos.colNum + 1) < lGrid.get(curPos.rowNum)->size() && checkTable.get(curPos.rowNum)->get(curPos.colNum + 1) == false && lGrid.get(curPos.rowNum)->get(curPos.colNum + 1) != '#') {
                posList.push(Position(curPos.rowNum, curPos.colNum + 1));
            }
            if((curPos.rowNum - 1) >= 0 && checkTable.get(curPos.rowNum - 1)->get(curPos.colNum) == false && lGrid.get(curPos.rowNum - 1)->get(curPos.colNum) != '#') {
                posList.push(Position(curPos.rowNum - 1, curPos.colNum));
            } 
            if((curPos.colNum - 1) >= 0 && checkTable.get(curPos.rowNum)->get(curPos.colNum - 1) == false && lGrid.get(curPos.rowNum)->get(curPos.colNum - 1) != '#') {
                posList.push(Position(curPos.rowNum, curPos.colNum - 1));
            }
        }
    }
}
void findEndUsingDFS(DoublyLinkedList<DoublyLinkedList<char>*>& lGrid, DoublyLinkedList<DoublyLinkedList<bool>*>& checkTable, Stack<Position> posList, Position& startPos);
int operation_input(int minValue, int maxValue) {
    int userInput;
    do {
        // get input
        cout << "Enter 1 to search via BFS\nEnter 2 to search via DFS\nChoice: ";
        cin >> userInput;

        // check for valid input
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid input." << endl;
        } else if ((userInput < minValue) || (userInput > maxValue)) {
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cerr << "Invalid input." << endl;
        }
    } while ((userInput < minValue) || (userInput > maxValue));
    
    // return input value
    return userInput;
}