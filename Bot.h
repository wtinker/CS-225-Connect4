#pragma once

#include "Board.h"
// BOT FILE

class Bot {
  private:
    int weights[COLUMNS];
	Board tempBoard;
	void calculate_weights(const Board&);
  public:
	int get_move(const Board&);
	int first_move();
};