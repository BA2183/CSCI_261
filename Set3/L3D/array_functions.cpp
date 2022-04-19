#include "array_functions.h"

void array_allocate(int*& pArray, const int INIT_SIZE) {
    pArray = new int[INIT_SIZE];
}

int array_get_element_at(const int* pArray, const int SIZE, const int POS) {
    int elementAt;
    if (POS > SIZE || POS < 0) {
        return 0;
    } else {
        elementAt = pArray[POS];
    }

    return elementAt;
}

void array_set_element_at(int* &pArray, const int SIZE, const int POS, const int VALUE) {
    if (POS < SIZE || POS > 0) {
        pArray[POS] = VALUE;
    }
}

void array_deallocate(int* &pArray, int &SIZE) {
    delete[] pArray;

    pArray = nullptr;
    SIZE = 0;
}

void array_insert_at_position(int*& pArray, int &size, const int POS, int VALUE) {
    size += 1;
    int *pNewArray = new int[size];

    if (POS >= (size - 1)) {
        for (int i = 0; i < size - 1; i++) {
            pNewArray[i] = pArray[i];
        }

        pNewArray[size - 1] = VALUE;
    } else if (POS <= 0) {
        pNewArray[0] = VALUE;

        for (int j = 1; j < size; j++) {
            pNewArray[j] = pArray[j - 1];
        }
    } else {
        for (int k = 0; k < POS; k++) {
            pNewArray[k] = pArray[k];
        }

        pNewArray[POS] = VALUE;

        for (int l = (POS + 1); l < size; l++) {
            pNewArray[l] = pArray[l - 1];
        }
    }

    delete[] pArray;
    pArray = pNewArray;
}

int array_min(const int* pArray, const int SIZE) {
    if (SIZE == 0 || !pArray) {
        return 0;
    } else {
        int tempMin = pArray[0];
        for (int a = 0; a < SIZE; a++) {
            if (pArray[a] < tempMin) {
                tempMin = pArray[a];
            }
        }

        return tempMin;
    }
}

int array_max(const int* pArray, const int SIZE) {
    if (SIZE == 0 || !pArray) {
        return 0;
    } else {
        int tempMax = pArray[0];
        for (int a = 0; a < SIZE; a++) {
            if (pArray[a] > tempMax) {
                tempMax = pArray[a];
            }
        }

        return tempMax;
    }
    
}

int array_find(const int* pArray, const int SIZE, const int TARGET) {
    int foundAt;
    for (int a = 0; a < SIZE; a++) {
        if (pArray[a] == TARGET) {
            foundAt = a;
            break;
        } else {
            foundAt = -1;
        }
    }

    return foundAt;
}

void array_remove_from_position(int* &pArray, int &size, const int POS) {
    if (size > 0) { 
        size -= 1;
    int *pNewArray = new int[size];

    if (POS >= (size + 1)) {
        for (int x = 0; x < size; x++) {
            pNewArray[x] = pArray[x];
        }
    } else if (POS <= 0) {
        for (int y = 0; y < size; y++) {
            pNewArray[y] = pArray[y + 1];
        }
    } else {
        for (int z = 0; z < POS; z++) {
            pNewArray[z] = pArray[z];
        }

        for (int w = POS; w < size; w++) {
            pNewArray[w] = pArray[w + 1];
        }
    }

    delete[] pArray;
    pArray = pNewArray;
    }
}