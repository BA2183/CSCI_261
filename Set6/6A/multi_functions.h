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
Position findStartUsingBFS(const DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>, Queue<Position>);
Position findStartUsingDFS(const DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>, Stack<Position>);
void findEndUsingBFS(DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>&, Queue<Position>);
void findEndUsingDFS(DoublyLinkedList<DoublyLinkedList<char>*>&, DoublyLinkedList<DoublyLinkedList<bool>*>&, Stack<Position>);
int operation_input(int, int);
#endif