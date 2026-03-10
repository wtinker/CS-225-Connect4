#pragma once

#include "Board.h"
// BOT FILE

class Bot {
  private:
    int weights[7];
	Board tempBoard;
	void calculate_weights(const Board&);
	int check_down();
	int check_up();
	int check_left();
	int check_right();
	int check_upper_left();
	int check_upper_right();
	int check_lower_left();
	int check_lower_right();
  public:
	int get_move(const Board&);
};