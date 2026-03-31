#pragma once

#include "Board.h"
// BOT FILE

class Bot {
  protected:
    int weights[COLUMNS];
	Board tempBoard, tempBoard2;
	void calculateWeights(Board);
  public:
	int getMove(Board);
	int firstMove();
	Bot();
	~Bot();
};