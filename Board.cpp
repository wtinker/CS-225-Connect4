#include "Board.h"

Board::Board() {
	reset_board();
}

void Board::display_board_simple() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout <<std::endl;
	}
}

void Board::drop_piece(int column, int id) {
	for (int i = 5; i >= 0; i--) {
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