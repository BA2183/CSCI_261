#ifndef OBJ_FUNCTIONS_H
#define OBJ_FUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include "LinkedList.hpp"
#include "Vertex.hpp"
#include "Face.hpp"

using namespace std;

int operation_input(int minvalue, int maxValue);
bool open_file(ifstream&, const string);
void read_file(ifstream&, LinkedList<string>&, LinkedList<Vertex>&, LinkedList<Face>&);
bool valid_face(const LinkedList<Vertex>&, const LinkedList<Face>&);
int print_output(const int, const LinkedList<string>&, const LinkedList<Vertex>&, const LinkedList<Face>&);
#endif //OBJ_FUNCTIONS_H