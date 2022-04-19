#include "multi_functions.h"
/**
 * @brief Open the input file stream for the corresponding filename. Check that the file opened correctly. 
 * 
 * @param fileIn the ifstream object keeping the the input file
 * @param fileName the input file name
 * @return true file opened successfully
 * @return false file failed to open
 */
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
void print(LinkedList<LinkedList<int>>*& lGrid) {
    Node<LinkedList<int>>* pCurrent = lGrid->head();
    Node<int>* pSecondCurrent;
    while(pCurrent != nullptr) {
        pSecondCurrent = (pCurrent->value).head();
        while(pSecondCurrent != nullptr) {
            cout << pSecondCurrent->value << " ";
            pSecondCurrent = pSecondCurrent->pNext;
        }
        cout << "\n";
        pCurrent = pCurrent->pNext;
    }
}
int max(LinkedList<LinkedList<int>>*& lGrid) {
    int tempMax = (((lGrid->head())->value).head())->value;
    Node<LinkedList<int>>* pCurrent = lGrid->head();
    Node<int>* pSecondCurrent;
    while(pCurrent != nullptr) {
        pSecondCurrent = (pCurrent->value).head();
        while(pSecondCurrent != nullptr) {
            if(pSecondCurrent->value > tempMax) {
                tempMax = pSecondCurrent->value;
            }
            pSecondCurrent = pSecondCurrent->pNext;
        }
        pCurrent = pCurrent->pNext;
    }

    return tempMax;
}
int min(LinkedList<LinkedList<int>>*& lGrid) {
    int tempMin = (((lGrid->head())->value).head())->value;
    Node<LinkedList<int>>* pCurrent = lGrid->head();
    Node<int>* pSecondCurrent;
    while(pCurrent != nullptr) {
        pSecondCurrent = (pCurrent->value).head();
        while(pSecondCurrent != nullptr) {
            if(pSecondCurrent->value < tempMin) {
                tempMin = pSecondCurrent->value;
            }
            pSecondCurrent = pSecondCurrent->pNext;
        }
        pCurrent = pCurrent->pNext;
    }

    return tempMin;
}