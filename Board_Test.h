#pragma once
#include "Board.h"
/*
void test_board_initialization();
void test_drop_piece();
void test_player_win();
void test_bot_win();
void test_checks();
void full_board_test();
*/

class Board_Tester : private Board{
  public:
	void test_board_initialization();
	void test_drop_piece();
	void test_player_win();
	void test_bot_win();
	void test_checks();
	void full_board_test();
};