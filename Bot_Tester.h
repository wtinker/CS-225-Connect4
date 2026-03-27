#pragma once
#include "Bot.h"
#include "Board.h"
class Bot_Tester : public Bot {
  private:
	Board b;
public:
	void load_board(int board[ROWS][COLUMNS]);
	void test_calculate_weights();
	void test_get_move();
};