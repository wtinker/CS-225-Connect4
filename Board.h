#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

#define ROWS 6
#define COLUMNS 7

// BOARD FILE

class Board {
  private:
	int board[ROWS][COLUMNS];
  public:
	  Board();
	  void display_board_simple();
	  void drop_piece(int column, int id);
	  int get_id(int row, int column);
	  void reset_board();
	  bool check_player_win();
	  bool check_bot_win();
	  bool check_full();
	  int check_down(int id, int row, int column);
	  int check_up(int id, int row, int column);
	  int check_left(int id, int row, int column);
	  int check_right(int id, int row, int column);
	  int check_upper_left(int id, int row, int column);
	  int check_upper_right(int id, int row, int column);
	  int check_lower_left(int id, int row, int column);
	  int check_lower_right(int id, int row, int column);
};