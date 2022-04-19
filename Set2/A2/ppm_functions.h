#include <iostream>
#include <fstream>

using namespace std;

#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H
void print_file_options();
void print_operartion_options();
int get_user_input(const int, const int);
bool open_file(ifstream&, ofstream&, int&, int&);
bool read_header_infomation(ifstream&, int&, int&, int&);
void write_header_infomation(ofstream&, int&, int&, int&);
void read_and_write_modified_pixels(ifstream&, ofstream&, int&, int&, int&, int&);
#endif //PPM_FUNCTIONS_H