#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Bot.h"
#include "Board.h"
#include "instructions.h"
#include "Board_Test.h"
#include "File_Log.h"
using namespace std;

int run_game(bool, int&);

int main() {
	srand(time(NULL));
	string ifPlay;
	string playerName;
	bool playerFirst = false;
	int playerWin = 0;
	string winner;

	// START TEST CODE 
	//full_board_test();
	int num_moves = 37;
	int board_final[ROWS][COLUMNS] = { {0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0},
						{0,0,0,0,0,0,1},
						{1,2,0,0,0,0,1},
						{1,2,0,2,2,1,1},
						{1,1,2,2,2,1,1} };

	// END TEST CODE

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
			playerWin = run_game(playerFirst, num_moves);


			// write to a file with all game details
			if (playerFirst == 1) { winner = playerName; } else { winner = "Computer"; }
			gameLog(playerName, winner, num_moves, board_final); // add other two once game play portion finished

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

int Run_Game(bool playerFirst, int& moveCount) {
	Board mainBoard;
	Bot bot;
	bool gameOver = false;
	int result = 0;
	int playerMove = 0;

	//clear moveCount
	moveCount = 0;

	//bot first move if thats needed
	if (!playerFirst) {
		mainBoard.drop_piece(bot.first_move(), 2);
	}

	//main game loop
	do {
		//display board
		cout << "Current board state: " << endl << mainBoard;
		//get player move
		cout << "Enter column number (0-" << COLUMNS << "): ";
		cin >> playerMove;
		moveCount++;
		try {
			mainBoard.drop_piece(playerMove, 1);
		}
		catch (std::out_of_range& e) {
			cout << "Column is full. Please choose another column." << endl;
			continue;
		}
		//check win/loss/tie
		if (mainBoard.check_player_win()) {
			result = 1;
			gameOver = true;
			continue;

		}
		else if (mainBoard.check_full()) {
			result = 2;
			gameOver = true;
			continue;
		}
		//get bot move
		mainBoard.drop_piece(bot.get_move(mainBoard), 2);
		//check win/loss/tie
		if (mainBoard.check_bot_win()) {
			result = 0;
			gameOver = true;
			continue;
		}
		else if (mainBoard.check_full()) {
			result = 2;
			gameOver = true;
			continue;
		}

	} while (!gameOver);

	return result;
}