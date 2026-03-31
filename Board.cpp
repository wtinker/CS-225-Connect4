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
	 * Class: Board
	 * Name: getId
	 * Input(s): row - the row index of the space to check
	 *		column - the column index of the space to check
	 * Return: the ID of the piece at the specified location (0 for empty, 1 for player, 2 for bot)
	 * Description: Returns the ID of the piece at the specified location
	 *		on the board. Throws an out_of_range exception if the specified
	 *		location is outside the bounds of the board.
	 */
	if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
		throw out_of_range("Row or column index is out of bounds");
	}
	return board[row][column];
}

bool Board::checkFull() {
	/*
	 * Class: Board
	 * Name: checkFull
	 * Input(s): none
	 * Return: true if the board is full (no empty spaces), false otherwise
	 * Description: Checks if the board is full by iterating through all spaces
	 *		and checking for any empty spaces (0). If an empty space is found, 
	 *		returns false. Otherwise, if no empty spaces are found, returns true.
	 */
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
	/*
	 * Class: Board
	 * Name: checkRight
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified 
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkLeft
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkDown
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkUp
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkUpperLeft
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkUpperRight
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkLowerLeft
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkLowerRight
	 * Input(s): id - the ID of the piece to check for connections
	 *		row - the row index of the starting piece
	 *		column - the column index of the starting piece
	 * Return: the number of connected pieces with the same ID in the specified
	 *		direction, including the starting piece
	 * Description: Uses recursion to check how many pieces with the given ID
	 *		are connected to the piece in the given direction.
	 */
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
	/*
	 * Class: Board
	 * Name: checkPlayerWin
	 * Input(s): none
	 * Return: true if the player has won (4 pieces in a row), false otherwise
	 * Description: Iterates through all spaces on the board and uses the check
	 *		functions to determine if there are 4 pieces with the player's ID (1) 
	 *		in a row in any direction. If such a connection exists, returns true.
	 *		Otherwise, returns false. 1 is subtracted from the total connections
	 *		to avoid counting the currently selected piece twice.
	 */
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
	/*
	 * Class: Board
	 * Name: checkBotWin
	 * Input(s): none
	 * Return: true if the bot has won (4 pieces in a row), false otherwise
	 * Description: Iterates through all spaces on the board and uses the check
	 *		functions to determine if there are 4 pieces with the bot's ID (2)
	 *		in a row in any direction. If such a connection exists, returns true.
	 *		Otherwise, returns false. 1 is subtracted from the total connections
	 *		to avoid counting the currently selected piece twice.
	 */
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
	/*
	 * Class: Board
	 * Name: checkAllConnections
	 * Input(s): id - the ID of the piece to check for connections
	 * Return: the number of piece connections with the same ID
	 * Description: Iterates through all spaces on the board and uses the check
	 *		functions to count the total number of connections for pieces with
	 *		the given ID. 8 is subtracted from the total to avoid counting the
	 *		currently selected piece.
	 */
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
	/*
	 * Class: Board
	 * Name: checkHighestConnection
	 * Input(s): id - the ID of the piece to check for connections
	 * Return: the highest number of piece connections with the same ID
	 * Description: Iterates through all spaces on the board and uses the check
	 *		functions to count the total number of connections for pieces with
	 *		the given ID. 8 is subtracted from the total to avoid counting the
	 *		currently selected piece. If the total number of connections for a
	 *		piece is higher than the current highest connection, the highest
	 *		connection is updated accordingly.
	 */
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
	/*
	 * Class: Board
	 * Name: ~Board (destructor)
	 * Input(s): none
	 * Return: none
	 * Description: Destructor for the Board class, no dynamic memory to free so it is empty.
	 *		Exists purely because required.
	 */
}

Board Board::operator=(int newBoard[ROWS][COLUMNS]) {
	/*
	 * Class: Board
	 * Name: operator= (operator overload)
	 * Input(s): newBoard - a 2D array representing the new state of the board
	 * Return: a reference to the updated board object
	 * Description: Overloading of the assignment operator to allow assigning a 2D array
	 *		to the board to set a custom board state for testing.
	 */
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			this->board[i][j] = newBoard[i][j];
		}
	}
	return *this;
}