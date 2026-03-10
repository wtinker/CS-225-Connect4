#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "bot.h"
#include "board.h"
#include "instructions.h"
using namespace std;

int main() {
	srand(time(NULL));
	string ifPlay;
	string playerName;
	bool playerFirst = false;

	// rules/instruction
	printInstructions();

	// ask player if they want to play
	cout << "Would you like to play (yes or no)? ";
	cin >> ifPlay;

	if(ifPlay == "yes") {
		while(ifPlay == "yes") {
			// ask play name
			cout << "What is your name? ";
			cin >> playerName;

			// coin flip who goes first
			cout << "Flipping coin to decide who goes first..." << endl;
			int coinFace = rand() % 2 + 1;
			if (coinFace == 1) {
				playerFirst = false;
			} else {
				playerFirst = true;
			}

			// Game play first move to win/loss/tie
			// I think this should be a header file to not over croud main

			// write to a file with all game details
			

			// display win vs loss vs tie message (0 = loss, 1 = win, 2 = tie)
			if(playerWin == 0) {
				cout << "You have lost. You'll get it next time." << endl;
			} else if(playerWin == 1) { 
				cout << "You have WON!! Congratulations!" << endl;
			} else {
				cout << "You and the computer have tied. Good game." << endl;
			}

			// ask player if they want to play again or quit
			cout << "Would you like to play again (yes or no)? ";
			cin >> ifPlay;
		}
	} else {
		cout << "Sounds good! I'll be here if you change your mind!" << endl;
	}

	return 0;
}