#ifndef MULTI_FUNCTIONS_H
#define MULTI_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Queue.hpp"
#include "Stack.hpp"
#include "Position.hpp"
#include "DoublyLinkedList.hpp"
using namespace std;
bool open_file(ifstream&, string);
void print(DoublyLinkedList<DoublyLinkedList<char>*>&);
void findStartUsingBFS(const DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>, Queue<Position>, Position&);
void findStartUsingDFS(const DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>, Stack<Position>,Position&);
void findEndUsingBFS(DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>&, Queue<Position>,Position&);
void findEndUsingDFS(DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>&, Stack<Position>,Position&);
int operation_input(int, int);
#endif