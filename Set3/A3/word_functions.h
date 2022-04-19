#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <set>

using namespace std;

#ifndef WORD_FUNCTIONS_H
#define WORD_FUNCTIONS_H
string prompt_user_for_filename();
bool open_file(ifstream&, const string);
vector<string> read_words_from_file(ifstream&);
void remove_punctuation(vector<string>&, const string);
void capitalize_words(vector<string>&);
vector<string> filter_unique_words(const vector<string>);
void count_letters(unsigned int letters[], const vector<string>);
void print_letter_counts(const unsigned int letters[]);
void print_max_min_letter(const unsigned int letters[]);
#endif //WORD_FUNCTIONS_H