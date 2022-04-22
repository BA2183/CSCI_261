#ifndef MULTI_FUNCTIONS_H
#define MULTI_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.hpp"
using namespace std;
bool open_file(ifstream&, string);
void print(LinkedList<LinkedList<int>*>&);
int max(LinkedList<LinkedList<int>*>&);
int min(LinkedList<LinkedList<int>*>&);
#endif