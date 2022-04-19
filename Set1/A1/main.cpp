/*  CSCI 261: Assignment 1: A1 - Rock Paper Sciccor Throw Down!
 *
 * Author: Duan Nguyen
 * Reference: class slide
 * 
 * This program will play a simple text-based rock-paper-scissor with a computer that is using a randomizer that have its seed change overtime.
 * The game will runs infinitely while keeping track of the score, and the game will stop till the player decide to stop.
 * After stoping, the program will print out the final score of the player
 */

//used library
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // called varible for score outside loop
    int playWins = 0;
    int compWins = 0;
    int tieScore = 0;

    // create infinite loop
    while (true) {
        // greet
        cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl;
        cout << "Player: ";

        //player choice
        string playChoice;
        cin >> playChoice;
        cout << endl;
        int numbChoice; // interger form of the player choice, defined for easier win conditioning
        // display player choice
        if (playChoice == "R" || playChoice == "r") {
            cout << "Player choosse Rock" << endl;
            numbChoice = 0;
        } else if (playChoice == "P" || playChoice == "p") {
            cout << "Player choose Paper" << endl;
            numbChoice = 1;
        } else if (playChoice == "S" || playChoice == "s") {
            cout << "Player choose Scissors" << endl;
            numbChoice = 2;
        }

        //randomly generate computer choice
        // throw away first few digits
        srand(time(0));
        rand();
        rand();
        int compChoice = rand() % (2 - 0 + 1) + 0;
        if (compChoice == 0) {
            cout << "Computer choose Rock" << endl;
        } else if (compChoice == 1) {
            cout << "Computer choose Paper" << endl;
        } else {
            cout << "Computer choose Scissors" << endl;
        }

        // decide on wining 
        cout << endl;

        //senerio 1: rock and scissor, need both side to choose one of each
        if ((numbChoice == 0 && compChoice == 2) || (numbChoice == 2 && compChoice == 0)) { 
            cout << "Rock beats Scissor. ";
            //check for who chose rock
            if (numbChoice == 0) {
                cout << "Player wins!"<< endl;
                //add point
                playWins++;
            } else {
                cout << "Computer wins!"<< endl;
                compWins++;
            }
        
        //senerio 2: scissor and paper, need both side to choose one of each    
        } else if ((numbChoice == 2 && compChoice == 1) || (numbChoice == 1 && compChoice == 2)) {
            cout << "Scissors beat Paper. ";
            //check for who chose scissors
            if (numbChoice == 2) {
                cout << "Player wins!"<< endl;
                playWins++;
            } else {
                cout << "Computer wins!"<< endl;
                compWins++;
            }

        //senerio 3: paper and rock, need both side to choose one of each
        } else if ((numbChoice == 1 && compChoice == 0) || (numbChoice == 0 && compChoice == 1)) {
            cout << "Paper beats Rock. ";
            //check for who chose paper
            if (numbChoice == 1) {
                cout << "Player wins!"<< endl;
                playWins++;
            } else {
                cout << "Computer wins!"<< endl;
                compWins++;
            }

        //senerio 4: tied, need both side to choose same option
        } else if (numbChoice == compChoice) {
            cout << "Ties!";
            //add tally to ties
            tieScore++;
        }

        //ask for stopping
        cout << endl;
        cout << "Do you want to play again? (Y/N) ";
        string playAgain;
        cin >> playAgain;
        cout << endl;
        if (playAgain == "N" || playAgain == "n") {
            break;
        } 
    }     

    // player stop playing
    cout << "Thanks for playing!" << endl;
    cout << "You won " << playWins << "game(s), lost " << compWins << "game(s), and tied " << tieScore << "game(s)." << endl;

    // return none
    return 0;
}