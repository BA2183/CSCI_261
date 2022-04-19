#include "merge_functions.h"

void merge_sort(LinkedList<int>*& pList) {
    // base case
    if(pList->size() <= 1) {
        return;
    } else {
        // divide & split
        LinkedList<int> *pLeft = new LinkedList<int>;
        LinkedList<int> *pRight = new LinkedList<int>;
            // split distance
        int halfSize = (pList->size()) / 2; int fullSize = pList->size();
        int countOne = 0, countTwo = halfSize;
            // left half
        while(countOne < halfSize) {
            pLeft->pushback(pList->at(0));
            pList->remove(0);
            countOne++;
        }
        // cout << "left list: "; pLeft->print(); cout << "\n";
            // right half
        while(countTwo < fullSize) {
            pRight->pushback(pList->at(0));
            pList->remove(0);
            countTwo++;
        }
        // cout << "right list: "; pRight->print(); cout << "\n";

        // recurse
        merge_sort(pLeft);
        merge_sort(pRight);
        // merge
        int leftSize = pLeft->size(); int rightSize = pRight->size();
        while(leftSize > 0 && rightSize > 0) {
            if(pLeft->at(0) > pRight->at(0)) {
                pList->pushback(pRight->at(0));
                pRight->remove(0);
                rightSize--;
            } else if(pLeft->at(0) < pRight->at(0)) {
                pList->pushback(pLeft->at(0));
                pLeft->remove(0);
                leftSize--;
            } else { //equal case
                pList->pushback(pRight->at(0));
                pRight->remove(0);
                pList->pushback(pLeft->at(0));
                pLeft->remove(0);
                rightSize--;
                leftSize--;
            }
        }

        while(leftSize > 0 || rightSize > 0) {
            if(leftSize > 0 && rightSize == 0) {
                pList->pushback(pLeft->at(0));
                pLeft->remove(0);
                leftSize--;
            } else if(leftSize == 0 && rightSize > 0) {
                pList->pushback(pRight->at(0));
                pRight->remove(0);
                rightSize--;
            }
        }

        // delete pLeft;
        // delete pRight;
    }
}