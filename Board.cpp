#include "Board.h"

Board::Board() {
	reset_board();
}

void Board::display_board_simple() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout <<std::endl;
	}
}

void Board::drop_piece(int column, int id) {
	if (board[0][column] != 0) {
		throw std::out_of_range("Column is full");
	}
	for (int i = COLUMNS - 1; i >= 0; i--) {
		if (board[i][column] == 0) {
			board[i][column] = id;
			break;
		}
	}
}

void Board::reset_board() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = 0;
		}
	}
}

int Board::get_id(int row, int column) {
	if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
		throw std::out_of_range("Row or column index is out of bounds");
	}
	return board[row][column];
}

bool Board::check_full() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

int Board::check_right(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_right(id, row, column + 1);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds right" << std::endl;
		return 0;
	}
}

int Board::check_left(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_left(id, row, column - 1);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds left" << std::endl;
		return 0;
	}
}

int Board::check_down(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_down(id, row + 1, column);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds down" << std::endl;
		return 0;
	}
}

int Board::check_up(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_up(id, row - 1, column);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds up" << std::endl;
		return 0;
	}
}

int Board::check_upper_left(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_upper_left(id, row - 1, column - 1);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds up left" << std::endl;
		return 0;
	}
}

int Board::check_upper_right(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_upper_right(id, row - 1, column + 1);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds up right" << std::endl;
		return 0;
	}
}

int Board::check_lower_left(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_lower_left(id, row + 1, column - 1);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds down left" << std::endl;
		return 0;
	}
}

int Board::check_lower_right(int id, int row, int column) {
	try {
		if (this->get_id(row, column) != id) {
			return 0;
		}
		else {
			return 1 + check_lower_right(id, row + 1, column + 1);
		}
	}
	catch (std::out_of_range& e) {
		std::cout << "out of bounds down right" << std::endl;
		return 0;
	}
}

bool Board::check_player_win() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == 1) {
				if (check_right(1, i, j) + check_left(1, i, j) - 1 >= 4 ||
					check_down(1, i, j) + check_up(1, i, j) - 1 >= 4 ||
					check_upper_left(1, i, j) + check_lower_right(1, i, j) - 1 >= 4 ||
					check_upper_right(1, i, j) + check_lower_left(1, i, j) - 1 >= 4) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Board::check_bot_win() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (board[i][j] == 2) {
				if (check_right(2, i, j) + check_left(2, i, j) - 1 >= 4 ||
					check_down(2, i, j) + check_up(2, i, j) - 1 >= 4 ||
					check_upper_left(2, i, j) + check_lower_right(2, i, j) - 1 >= 4 ||
					check_upper_right(2, i, j) + check_lower_left(2, i, j) - 1 >= 4) {
					return true;
				}
			}
		}
	}
	return false;
}