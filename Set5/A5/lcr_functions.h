#ifndef LCR_FUNCTIONS_H
#define LCR_FUNCTIONS_H
#include "CircularLinkedList.hpp"
#include "Player.hpp"
#include <cstdlib>
#include <ctime>
void run();
bool stillPlay(const CircularLinkedList<Player>*);
#endif