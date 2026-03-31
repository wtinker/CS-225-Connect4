#pragma once
#include "Bot.h"
#include "Board.h"
class BotTester : private Bot {
  private:
	Board b;
  public:
	void loadBoard(int board[ROWS][COLUMNS]);
	void testCalculateWeights();
	void testGetMove();
	void testFirstMove();
	void randomBoard(int rows);
	void dispBoard();
};