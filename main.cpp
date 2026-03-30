#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Bot.h"
#include "Board.h"
#include "instructions.h"
#include "Board_Test.h"
#include "Bot_Tester.h"
#include "File_Log.h"
using namespace std;

int runGame(bool, int&, Board&);

int main() {
	srand(time(NULL));
	string ifPlay;
	string playerName;
	bool playerFirst = false;
	int playerWin = 0;
	int numMoves = 0;
	Board boardFinal;
	string winner;

	bool inTesting = false;

	// rules/instruction
	printInstructions();

	// ask mplayer if they want to play
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
				cout << "The computer will be going first!" << endl;
				playerFirst = false;
			} else {
				cout << "You will be going first!" << endl;
				playerFirst = true;
			}

			// Game play first move to win/loss/tie
			// I think this should be a header file to not over croud main
			playerWin = runGame(playerFirst, numMoves, boardFinal);


			// write to a file with all game details
			if (playerFirst == 1) { winner = playerName; } else { winner = "Computer"; }
			gameLog(playerName, winner, numMoves, boardFinal); // add other two once game play portion finished

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
	} else if (inTesting) {
		Board_Tester boardTester;
		boardTester.full_board_test();

		Bot_Tester botTester;
		botTester.test_first_move();

		int testBoard[ROWS][COLUMNS] = {
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 2, 0, 0, 0},
			{0, 0, 0, 1, 1, 0, 0} };
		botTester.load_board(testBoard);
		botTester.disp_board();

		//botTester.random_board(3);
		//botTester.disp_board();
		botTester.test_calculate_weights();
		botTester.disp_board();
		botTester.test_get_move();
	}
	else {
		cout << "Sounds good! I'll be here if you change your mind!" << endl;
	}

	return 0;
}

int runGame(bool playerFirst, int& moveCount, Board& final) {
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
		cout << "Enter column number (1-" << COLUMNS << "): ";
		cin >> playerMove;
		playerMove--;
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
			final = mainBoard;
			continue;
		}
		else if (mainBoard.check_full()) {
			result = 2;
			gameOver = true;
			final = mainBoard;
			continue;
		}
		//get bot move
		mainBoard.drop_piece(bot.get_move(mainBoard), 2);
		//check win/loss/tie
		if (mainBoard.check_bot_win()) {
			result = 0;
			gameOver = true;
			final = mainBoard;
			continue;
		}
		else if (mainBoard.check_full()) {
			result = 2;
			gameOver = true;
			final = mainBoard;
			continue;
		}

	} while (!gameOver);

	cout << "Final board state: " << endl << mainBoard;

	return result;
}