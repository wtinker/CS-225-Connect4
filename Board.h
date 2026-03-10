#pragma once
#include <iostream>
#include <string>
// BOARD FILE

class Board {
  protected:
	int board[6][7];
  public:
	  Board();
	  void display_board_simple();
	  void drop_piece(int column, int id);
	  void reset_board();
};
