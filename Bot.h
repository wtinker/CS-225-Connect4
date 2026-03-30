#pragma once

#include "Board.h"
// BOT FILE

class Bot {
  protected:
    int weights[COLUMNS];
	Board tempBoard, tempBoard2;
	void calculate_weights(Board);
  public:
	int get_move(Board);
	int first_move();
	Bot();
	~Bot();
};