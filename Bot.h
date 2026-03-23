#pragma once

#include "Board.h"
#include <cstdlib>
#include <ctime>
// BOT FILE

class Bot {
  private:
    int weights[COLUMNS];
	Board tempBoard, tempBoard2;
	void calculate_weights(const Board&);
  public:
	int get_move(const Board&);
	int first_move();
};