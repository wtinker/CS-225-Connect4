#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#define ROWS 6
#define COLUMNS 7

// BOARD FILE

class Board {
  protected:
	int board[ROWS][COLUMNS];
	int checkDown(int id, int row, int column);
	int checkUp(int id, int row, int column);
	int checkLeft(int id, int row, int column);
	int checkRight(int id, int row, int column);
	int checkUpperLeft(int id, int row, int column);
	int checkUpperRight(int id, int row, int column);
	int checkLowerLeft(int id, int row, int column);
	int checkLowerRight(int id, int row, int column);
  public:
	Board();
	~Board();
	friend ostream& operator<<(ostream& os, const Board& b);
	//void display_board_simple();
	void dropPiece(int column, int id);
	int getId(int row, int column);
	void resetBoard();
	bool checkPlayerWin();
	bool checkBotWin();
	bool checkFull();
	int checkAllConnections(int id);
	int checkHighestConnection(int id);
	Board operator=(int[ROWS][COLUMNS]);
};