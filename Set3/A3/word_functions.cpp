#include "word_functions.h"

/**
 * @brief Prompt the user to enter a filename.
 * 
 * @return string of file name
 */
string prompt_user_for_filename() {
    cout << "Enter the valid file's name: ";

    string filename;
    getline( cin, filename );

    return filename;
}

/**
 * @brief Open the input file stream for the corresponding filename. Check that the file opened correctly. The string filename will remain unchanged.
 * 
 * @param parameter-name The input file stream
 * @param parameter-name The string filename to open
 * @return true 
 * @return false 
 */
bool open_file(ifstream& fileIn, const string filename) {
    fileIn.open(filename);

    if (fileIn.fail()) {
        fileIn.close();
        return false;
    } else {
        return true;
    }
}

/**
 * @brief Read all the words that are in the file stream and return a vector of all the words in the order present in the file.
 * 
 * @param fileIn The input file
 * @return vector<string> vector of string hold all word in file.
 */
vector<string> read_words_from_file(ifstream& fileIn) {
    string word;
    vector <string> wordVector;
    while(!fileIn.eof()) {
        fileIn >> word;
        if (!fileIn.fail()) {
            wordVector.push_back(word);
        }
    }
    
    return wordVector;
}

/**
 * @brief For each word in the vector, remove all occurrences of all the punctuation characters denoted by the punctuation string. When complete, the input vector will now hold all the words with punctuation removed. The punctuation string will remain unchanged.
 * 
 * @param wordVector vector of word/string
 * @param stringToRemove string to remove from each word/string of vector
 */
void remove_punctuation(vector<string>& wordVector, const string stringToRemove) {
    for (unsigned int i = 0; i < wordVector.size(); i++) {
        for (unsigned int j = 0; j < stringToRemove.length(); j++) {
            for (unsigned int k = 0; k < wordVector[i].length(); k++) {
                if (wordVector[i][k] == stringToRemove[j]) {
                    wordVector[i].erase(k, 1);
                    k--;
                    // Hello!World k = 5
                    // HelloWorld k = 6
                }
            }
        } 
    }
}

/**
 * @brief For each word in the vector, convert each character to its upper case equivalent. When complete, the input vector will now hold all the words capitalized.
 * 
 * @param wordVector vector of word/string
 */
void capitalize_words(vector<string>& wordVector) {
    for (unsigned int i = 0; i < wordVector.size(); i++) {
        for (unsigned int j = 0; j < wordVector[i].length(); j++) {
            wordVector[i][j] = toupper(wordVector[i][j]);
        }
    }
}

/**
 * @brief The function will return only the unique words present in the input vector. The output vector will not contain any duplicate words.
 * 
 * @param wordVector vector of word/string
 * @return vector<string> vector of unique word/string
 */
vector<string> filter_unique_words(const vector<string> wordVector) {
    vector<string> result;
    result.push_back(wordVector[0]);
    unsigned int g, f;
    bool inVec;
    //set<string> uniqueWord;

    for (f = 0; f < wordVector.size(); f++) {
        for (g = 0; g < result.size(); g++) {
            inVec = false;
            if (result[g] == wordVector[f]) {
                inVec = true;
                break;
            }
        }

        if (!inVec) {
            result.push_back(wordVector[f]);
        } else {
            continue;
        }
    }

    return result;
}

/**
 * @brief Count the number of occurrences of each letter present in all words. Each position of the array corresponds to each letter as ordered by the English alphabet. Upon completion, the array will hold the counts of each letter and the vector of strings will remain unchanged.
 * @param letters An array of 26 unsigned integers
 * @param wordVector 
 */
void count_letters(unsigned int letters[], const vector<string> wordVector) {
    for (unsigned int x = 0; x < wordVector.size(); x++) {
        for (unsigned int y = 0; y < wordVector[x].length(); y++) {
            switch (wordVector[x][y]) {
                case 'A':
                case 'a':
                    letters[0] += 1;
                    break;
                case 'B':
                case 'b':
                    letters[1] += 1;
                    break;
                case 'C':
                case 'c':
                    letters[2] += 1;
                    break;
                case 'D':
                case 'd':
                    letters[3] += 1;
                    break;
                case 'E':
                case 'e':
                    letters[4] += 1;
                    break;
                case 'F':    
                case 'f':
                    letters[5] += 1;
                    break;
                case 'G':
                case 'g':
                    letters[6] += 1;
                    break;
                case 'H':
                case 'h':
                    letters[7] += 1;
                    break;
                case 'I':
                case 'i':
                    letters[8] += 1;
                    break;
                case 'J':
                case 'j':
                    letters[9] += 1;
                    break;
                case 'K':
                case 'k':
                    letters[10] += 1;
                    break;
                case 'L':
                case 'l':
                    letters[11] += 1;
                    break;
                case 'M':
                case 'm':
                    letters[12] += 1;
                    break;
                case 'N':
                case 'n':
                    letters[13] += 1;
                    break;
                case 'O':
                case 'o':
                    letters[14] += 1;
                    break;
                case 'P':
                case 'p':
                    letters[15] += 1;
                    break;
                case 'Q':
                case 'q':
                    letters[16] += 1;
                    break;
                case 'R':
                case 'r':
                    letters[17] += 1;
                    break;
                case 'S':
                case 's':
                    letters[18] += 1;
                    break;
                case 'T':
                case 't':
                    letters[19] += 1;
                    break;
                case 'U':
                case 'u':
                    letters[20] += 1;
                    break;
                case 'V':
                case 'v':
                    letters[21] += 1;
                    break;
                case 'W':
                case 'w':
                    letters[22] += 1;
                    break;
                case 'X':
                case 'x':
                    letters[23] += 1;
                    break;
                case 'Y':
                case 'y':
                    letters[24] += 1;
                    break;
                case 'Z':
                case 'z':
                    letters[25] += 1;
                    break;
                
            }
        }
    }
}

/**
 * @brief For each letter, print out the letter and its corresponding count.
 * 
 * @param letters An array of 26 unsigned integers
 */
void print_letter_counts(const unsigned int letters[]) {
    string englishAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int maxiCount;
    maxiCount = letters[0];
    for (unsigned int d = 0; d < 26; d++) {
        if (letters[d] > maxiCount) {
            maxiCount = letters[d];
        }
    }

    unsigned int width;
    width = to_string(maxiCount).length();

    for (unsigned int a = 0; a < englishAlphabet.length(); a++) {
        cout << englishAlphabet[a] << " ";
        cout << setw(width) << letters[a] << "\n";
    }
}

/**
 * @brief Print out the two letters that occur least often and most often. If there is more than one letter that occurs the same number of times, print the one that comes first alphabetically. Upon completion, the input array will remain unchanged.
 * 
 * @param letters An array of 26 unsigned integers
 */
void print_max_min_letter(const unsigned int letters[]) {
    string englishAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    double sum;

    for (unsigned int b = 0; b < 26; b++) {
        (double) (sum += letters[b]);
    
    }
    //cout << "sum: " << sum << endl;

    double hundred = 100.00;
    double miniValue, maxiValue;
    char miniChar, maxiChar;
    miniChar = maxiChar = '\0';
    int miniCount, maxiCount;
    miniCount = maxiCount = letters[0];

    for (unsigned int d = 0; d < 26; d++) {
        if (letters[d] < miniCount) {
            miniCount = letters[d];
            miniChar = englishAlphabet[d];
        } else if (letters[d] > maxiCount) {
            maxiCount = letters[d];
            maxiChar = englishAlphabet[d];
        }
    }

    miniValue = miniCount * hundred / sum;
    maxiValue = maxiCount * hundred / sum;
    //cout << "min: " << miniCount << "\nmax: " << maxiCount * hundred / sum << endl;

    unsigned int width;
    width = to_string(maxiCount).length();

    cout << "Least Freguent Letter: " << miniChar << " ";
    cout << setw(width) << miniCount;
    cout << " (";
    cout << setw(7) << fixed << setprecision(3) << miniValue;
    cout << "%)\n";

    cout << " Most Freguent Letter: " << maxiChar << " ";
    cout << setw(width) << maxiCount;
    cout << " (";
    cout << setw(7) << fixed << setprecision(3) << maxiValue;
    cout << "%)\n";
}