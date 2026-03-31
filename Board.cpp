#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
	/*
	 * Class: Board
	 * Name: Board (constructor)
	 * Input(s): none
	 * Return: none
	 * Description: Default constructor for the Board class. Initializes the board to be empty (0 in all spaces).
	 */
	resetBoard();
}

ostream& operator<<(ostream& os, const Board& b) {
	/*
	 * Class: Board
	 * Name: operator<< (operator overload)
	 * Input(s): os - the output stream to write to
	 *		b - the board object to display
	 * Return: the output stream with the board displayed
	 * Description: Overloading of the insertion operator to display the board in a user-friendly format.
	 */
	for (int i = 0; i < ROWS; i++) {
		os << i + 1 << " | ";

		for (int j = 0; j < COLUMNS; j++) {
			if (b.board[i][j] == 0) {
				os << "* ";
			}
			else if (b.board[i][j] == 1) {
				os << "O ";
			}
			else if (b.board[i][j] == 2) {
				os << "X ";
			}
		}

		os << "|" << endl;
	}
	os << "+-----------------+" << endl;
	os << "    1 2 3 4 5 6 7 " << endl << endl;

	return os;
}

void Board::dropPiece(int column, int id) {
	/*
	 * Class: Board
	 * Name: dropPiece
	 * Input(s): column - the column index where the piece should be dropped
	 *		id - the ID of the piece to drop (1 for player, 2 for bot)
	 * Return: void
	 * Description: "Drops" a piece in the specified column by placing the 
	 *		piece in the lowest available space in that column. If the column
	 *		is full, an out_of_range exception is thrown.
	 */
	if (board[0][column] != 0) {
		throw out_of_range("Column is full");
	}
	for (int i = ROWS - 1; i >= 0; i--) {
		if (board[i][column] == 0) {
			board[i][column] = id;
			break;
		}
	}
}

void Board::resetBoard() {
	/*
	 * Class: Board
	 * Name: resetBoard
	 * Input(s): none
	 * Return: void
	 * Description: Resets the board to be empty by setting all spaces to 0.
	 */
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = 0;
		}
	}
}

int Board::getId(int row, int column) {
	/*
	 * Class:
	 * Name:
	 * Input(s):
	 * Return:
	 * Description:
	 */
	if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
		throw out_of_range("Row or column index is out of bounds");
	}
	return board[row][column];
}

bool Board::checkFull() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

int Board::checkRight(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkRight(id, row, column + 1);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds right" << std::endl;
		return 0;
	}
}

int Board::checkLeft(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkLeft(id, row, column - 1);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds left" << std::endl;
		return 0;
	}
}

int Board::checkDown(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkDown(id, row + 1, column);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds down" << std::endl;
		return 0;
	}
}

int Board::checkUp(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkUp(id, row - 1, column);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds up" << std::endl;
		return 0;
	}
}

int Board::checkUpperLeft(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkUpperLeft(id, row - 1, column - 1);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds up left" << std::endl;
		return 0;
	}
}

int Board::checkUpperRight(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkUpperRight(id, row - 1, column + 1);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds up right" << std::endl;
		return 0;
	}
}

int Board::checkLowerLeft(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkLowerLeft(id, row + 1, column - 1);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds down left" << std::endl;
		return 0;
	}
}

int Board::checkLowerRight(int id, int row, int column) {
	try {
		if (this->getId(row, column) != id) {
			return 0;
		}
		else {
			return 1 + checkLowerRight(id, row + 1, column + 1);
		}
	}
	catch (out_of_range& e) {
		//std::cout << "out of bounds down right" << std::endl;
		return 0;
	}
}

bool Board::checkPlayerWin() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == 1) {
				if (checkRight(1, i, j) + checkLeft(1, i, j) - 1 >= 4 ||
					checkDown(1, i, j) + checkUp(1, i, j) - 1 >= 4 ||
					checkUpperLeft(1, i, j) + checkLowerRight(1, i, j) - 1 >= 4 ||
					checkUpperRight(1, i, j) + checkLowerLeft(1, i, j) - 1 >= 4) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Board::checkBotWin() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == 2) {
				if (checkRight(2, i, j) + checkLeft(2, i, j) - 1 >= 4 ||
					checkDown(2, i, j) + checkUp(2, i, j) - 1 >= 4 ||
					checkUpperLeft(2, i, j) + checkLowerRight(2, i, j) - 1 >= 4 ||
					checkUpperRight(2, i, j) + checkLowerLeft(2, i, j) - 1 >= 4) {
					return true;
				}
			}
		}
	}
	return false;
}

int Board::checkAllConnections(int id) {
	int total = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == id) {
				total += checkRight(id, i, j) + checkLeft(id, i, j)
					+ checkDown(id, i, j) + checkUp(id, i, j)
					+ checkUpperLeft(id, i, j) + checkUpperRight(id, i, j)
					+ checkLowerLeft(id, i, j) + checkLowerRight(id, i, j) - 8;
			}
		}
	}
	return total;
}

int Board::checkHighestConnection(int id) {
	int highest = 0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == id) {
				int connection_length = checkRight(id, i, j) + checkLeft(id, i, j)
					+ checkDown(id, i, j) + checkUp(id, i, j)
					+ checkUpperLeft(id, i, j) + checkUpperRight(id, i, j)
					+ checkLowerLeft(id, i, j) + checkLowerRight(id, i, j) - 8;
				if (connection_length > highest) {
					highest = connection_length;
				}
			}
		}
	}
	return highest;
}

Board::~Board() {
	// No dynamic memory to free
}

Board Board::operator=(int new_board[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			this->board[i][j] = new_board[i][j];
		}
	}
	return *this;
}