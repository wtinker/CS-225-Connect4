#include "Run_Game.h"
#include "Board.h"
#include "Bot.h"
#include <stdio.h>

using namespace std;

int Run_Game(bool playerFirst) {
	Board mainBoard;
	Bot bot;
	bool gameOver = false;
	int result = 0;

	//reset board
	mainBoard.reset_board();

	if (!playerFirst) {
		mainBoard.drop_piece(bot.first_move(), 2);
	}

	do {
		//display board

		//get player move

		//check win/loss/tie

		//get bot move

		//check win/loss/tie
		
	} while (!gameOver);

	return result;
}