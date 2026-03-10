#pragma once

#include "Board.h"
// BOT FILE

class Bot {
  private:
    int weights[7];
	Board tempBoard;
	void calculate_weights(const Board&);
  public:
	int get_move(const Board&);
	int first_move();
};