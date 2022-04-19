#include "lcr_functions.h"
/**
 * @brief check if there are still at least 2 players still playing
 * 
 * @param pList the pointer of the list need to check
 * @return true if the game is still going
 * @return false if not
 */
bool stillPlay(const CircularLinkedList<Player>*& pList) {
    int listCount, playerCount;
    listCount = playerCount = 0;
    DoublyNode<Player>* pCurrent = pList->head();
    while(listCount < pList->size() && pCurrent != nullptr) {
        if((pCurrent->value).getChip() > 0) {
            playerCount++;
        }
        listCount++;
        pCurrent = pCurrent->pNext;
    }

    if(playerCount >= 2) {
        return true;
    } else {
        return false;
    }
}

void run() {
    // cout << "among us\n";
    // get number of players
    cout << "Enter number of players: ";
    int numPlay;
    cin >> numPlay;

    // make list of player
    Player *tempPlay = new Player; tempPlay->setChip(3);
    CircularLinkedList<Player> *playerList = new CircularLinkedList<Player>;
    for(int i = 0; i < numPlay; i++) {
        tempPlay->setNum(i);
        playerList->add(*tempPlay);
    }
    // make dice
    srand(time(0)); rand();
    int rollNum;

    // start the game
    DoublyNode<Player> *currentTurn = playerList->head();
    int currentChip, currentDirection, centerChip, skipNum, turnNum;
    turnNum = centerChip = 0;
    currentDirection = 1; // 1 for clockwise, -1 for counter clockwise
    while(stillPlay(playerList) == true) {
        currentChip = (currentTurn->value).getChip();
        cout << "Player #" << (currentTurn->value).getNum() << " has " << currentChip << " chips left\n=========================\nRolling " << currentChip << "dice\n";
        skipNum = 0;
        for(int j = 0; j < currentChip; j++) {
            rollNum = rand() % 6;
            switch (rollNum) {
            case 3:
                cout << "Rolled a 3 - give left - ";
                (currentTurn->value).giveChip(currentTurn->pLast->value);
                cout << "Player #" << (currentTurn->pLast->value).getNum() << " has " << (currentTurn->pLast->value).getChip() << " chips"
                  << " - Player #" << (currentTurn->value).getNum() << " has " << (currentTurn->value).getChip() << "chips\n";
                break;
            case 4:
                cout << "Rolled a 4 - give right - ";
                (currentTurn->value).giveChip(currentTurn->pNext->value);
                cout << "Player #" << (currentTurn->pNext->value).getNum() << " has " << (currentTurn->pNext->value).getChip() << " chips"
                  << " - Player #" << (currentTurn->value).getNum() << " has " << (currentTurn->value).getChip() << "chips\n";
                break;
            case 5:
                cout << "Rolled a 5 - give center - ";
                centerChip++;
                (currentTurn->value).giveChip();
                cout << "Center has " << centerChip << " chips - " << " - Player #" << (currentTurn->value).getNum() << " has " << (currentTurn->value).getChip() << "chips\n";
                break;
            case 6:
                cout << "Rolled a 6 - reverse!";
                currentDirection = currentDirection * -1;
                break;
            case 7:
                skipNum++;
                cout << "Rolled a 7 - skip! skipping " << skipNum << "players\n";
                break;
            default:
                cout << "Rolled a " << rollNum << " - keep!\n";
                break;
            }
        }
        
        if(currentDirection == 1) {
            if(skipNum == 0) {
                currentTurn = currentTurn->pNext;
            } else {
                for(int x = 0; x < skipNum; x++) {
                    currentTurn = currentTurn->pNext;
                }
            }
        } else if(currentDirection == -1) {
            if(skipNum == 0) {
                currentTurn = currentTurn->pLast;
            } else {
                for(int x = 0; x < skipNum; x++) {
                    currentTurn = currentTurn->pLast;
                }
            }
        }
        turnNum++;
    }

    int tempMax = ((playerList->head())->value).getChip();
    Player tempMaxPlayer = (playerList->head())->value;
    DoublyNode<Player>* currentCount = playerList->head();
    int k = 0;
    while(k < numPlay) {
        if((currentCount->value).getChip() > tempMax) {
            tempMax = (currentCount->value).getChip();
            tempMaxPlayer = currentCount->value;
        }
        k++;
    }

    cout << "Player #" << tempMaxPlayer.getNum() << " wins with " << tempMaxPlayer.getChip() << " chips left after " << turnNum << "turns";
    delete playerList;
    delete tempPlay;
}