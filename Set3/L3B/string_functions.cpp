#include "string_functions.h"

int string_length(const string STR)  {
    int result = -1;
    result = STR.length();  // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    // TODO 01: set result to the character of a string at a given index
    result = STR.at(IDX);
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    // TODO 02: set result to the concatenation of strings LEFT and RIGHT
    result += RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    // TODO 03: set result to the result of inserting a string into another
    result.insert(IDX, TO_INSERT);
    return result;
}

int string_find(const string STR, const char C)  {
    int result = -1;
    // TODO 04: set result to the index of the first occurrence of the character
    result = STR.find_first_of(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    // TODO 05: set result to be a substring starting at index of given length
    result = result.substr(IDX, LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;
    // TODO 06: set result to be the string with the given text replaced
    int IDX = result.find(TEXT_TO_REPLACE);
    if (IDX < result.length()) {
        result.replace(IDX, TEXT_TO_REPLACE.length(), REPLACE_WITH);
    }
    return result;
}

string string_first_word(const string STR)  {
    string result = STR;
    // TODO 07: set result to the first word from the string
    char space = ' ';
    int firstSpace = result.find_first_of(space);
    result = result.substr(0, firstSpace);
    return result;
}

string string_remove_first_word(const string STR)  {
    string result = STR;
    // TODO 08: set result to be the string with the first word removed
    char space = ' ';
    int firstSpace = result.find_first_of(space);
    if (firstSpace < 0) {
        result.erase(0, result.length());
    } else {
        int seconSpace = result.find_first_of(space, firstSpace + 1);
        result.erase(0, firstSpace + 1);
    }
    return result;
}

string string_second_word(const string STR)  {
    string result = STR;
    // TODO 09: set result to be the second word from the string
    char space = ' ';
    int firstSpace = result.find_first_of(space);
    if (firstSpace < 0) {
        result.erase(0, result.length());
    } else {
        int seconSpace = result.find_first_of(space, firstSpace + 1);
        result = result.substr(firstSpace + 1, seconSpace - firstSpace - 1);
    }
    return result;
}

string string_third_word(const string STR)  {
    string result = STR;
    // TODO 10: set result to be the third word from the string
    char space = ' ';
    int firstSpace = result.find_first_of(space);
    if (firstSpace < 0) {
        result.erase(0, result.length());
    } else {
        int seconSpace = result.find_first_of(space, firstSpace + 1);
        if ( seconSpace < 0) {
            result.erase(0, result.length());
        } else {
            int thirdSpace = result.find_first_of(space, seconSpace + 1);
            result = result.substr(seconSpace + 1, thirdSpace - seconSpace - 1);
        }
    }
    return result;
}

string string_nth_word(const string STR, const int N)  {
    string result = STR;
    // TODO 11: set result to be the nth word from the string
    string word;
    vector <string> wordVector;
    for(auto character : result){
        if (character != ' ') {
            word += character;
        } else {
            wordVector.push_back(word);
            word = "";
        }
    }
    wordVector.push_back(word);
    
    if (N > wordVector.size()) {
        result = "";
    } else {
        result = wordVector.at(N - 1);
    }
    
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = STR;
    // TODO 12: set result to be the string with all instances of TARGET replaced
    for (int i = 0; i < result.length(); i++) {
        if (result[i] == TARGET) {
            result[i] = REPLACEMENT;
        }
    }
    
    return result;
}

string string_to_lower(const string STR) {
    string result = STR;
    // TODO 13: convert all characters to lower case
    for (int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

string string_to_upper(const string STR) {
    string result = STR;
    // TODO 14: convert all characters to upper case
    for (int i = 0; i < result.length(); i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result = 0;
    // TODO 15: compare LHS and RHS
    if ( LHS < RHS) {
        result = -1;
    } else if ( LHS > RHS) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}