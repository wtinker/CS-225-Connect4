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
	  bool check_player_win();
	  bool check_bot_win();
	  bool check_full();
	  int check_down(int id);
	  int check_up(int id);
	  int check_left(int id);
	  int check_right(int id);
	  int check_upper_left(int id);
	  int check_upper_right(int id);
	  int check_lower_left(int id);
	  int check_lower_right(int id);
};