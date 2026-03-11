#include "Board.h"
#include "Board_Test.h"
#include <iostream>
#include <ctime>

using namespace std;

void test_board_initialization() {
	cout << "Board initialization test:" << endl;
	cout << "Creating board...:" << endl;
	Board board;
	cout << "Displaying board...:" << endl;
	board.display_board_simple();
}

void test_drop_piece() {
	cout << "Board drop piece test:" << endl;
	Board board;
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping player piece in column " << i << endl;
		board.drop_piece(i, 1);
		board.display_board_simple();
	}
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping bot piece in column " << i << endl;
		board.drop_piece(i, 2);
		board.display_board_simple();
	}
}

void test_player_win() {
	cout << "Player win test:" << endl;
	Board board;
	for (int i = 0; i < 4; i++) {
		board.drop_piece(i, 1);
	}
	board.display_board_simple();
	if (board.check_player_win()) {
		cout << "Player win detected successfully!" << endl;
	}
	else {
		cout << "Player win detection failed!" << endl;
	}
}

void test_bot_win() {
	cout << "Bot win test:" << endl;
	Board board;
	for (int i = 0; i < 4; i++) {
		board.drop_piece(i, 2);
	}
	board.display_board_simple();
	if (board.check_bot_win()) {
		cout << "Bot win detected successfully!" << endl;
	}
	else {
		cout << "Bot win detection failed!" << endl;
	}
}

void test_checks() {
	srand(time(NULL));
	cout << "Check functions test:" << endl;
	Board board;
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			int id = rand() % 2 + 1;
			board.drop_piece(i, id);
		}
	}
	board.display_board_simple();
	int pieceID = board.get_id(2, 3);
	cout << "Calculating checks for center piece ID "<< pieceID << endl;
	cout << "Right check: " << board.check_right(pieceID, 2, 3) << endl;
	cout << "Left check: " << board.check_left(pieceID, 2, 3) << endl;
	cout << "Down check: " << board.check_down(pieceID, 2, 3) << endl;
	cout << "Up check: " << board.check_up(pieceID, 2, 3) << endl;
	cout << "Upper left check: " << board.check_upper_left(pieceID, 2, 3) << endl;
	cout << "Upper right check: " << board.check_upper_right(pieceID, 2, 3) << endl;
	cout << "Lower left check: " << board.check_lower_left(pieceID, 2, 3) << endl;
	cout << "Lower right check: " << board.check_lower_right(pieceID, 2, 3) << endl;
}

void full_board_test() {
	cout << "Full board test:" << endl;
	test_board_initialization();
	test_drop_piece();
	test_player_win();
	test_bot_win();
	test_checks();
}