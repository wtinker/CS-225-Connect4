#include "Board_Test.h"
#include <iostream>
#include <ctime>

using namespace std;

void Board_Tester::test_board_initialization() {
	cout << "Board initialization test:" << endl;
	cout << "Creating board...:" << endl;
	this->reset_board();
	cout << "Displaying board...:" << endl;
	cout << *this;
}
void Board_Tester::test_drop_piece() {
	cout << "Board drop piece test:" << endl;
	this->reset_board();
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping player piece in column " << i << endl;
		this->drop_piece(i, 1);
		cout << *this;
	}
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping bot piece in column " << i << endl;
		this->drop_piece(i, 2);
		cout << *this;
	}
}

void Board_Tester::test_player_win() {
	cout << "Player win test:" << endl;
	this->reset_board();
	for (int i = 0; i < 4; i++) {
		this->drop_piece(i, 1);
	}
	cout << *this;
	if (this->check_player_win()) {
		cout << "Player win detected successfully!" << endl;
	}
	else {
		cout << "Player win detection failed!" << endl;
	}
}

void Board_Tester::test_bot_win() {
	cout << "Bot win test:" << endl;
	this->reset_board();
	for (int i = 0; i < 4; i++) {
		this->drop_piece(i, 2);
	}
	cout << *this;
	if (this->check_bot_win()) {
		cout << "Bot win detected successfully!" << endl;
	}
	else {
		cout << "Bot win detection failed!" << endl;
	}
}

void Board_Tester::test_checks() {
	srand(time(NULL));
	cout << "Check functions test:" << endl;
	this->reset_board();
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			int id = rand() % 2 + 1;
			this->drop_piece(i, id);
		}
	}
	cout << *this;
	int pieceID = this->get_id(2, 3);
	cout << "Calculating checks for center piece ID "<< pieceID << endl;
	cout << "Right check: " << this->check_right(pieceID, 2, 3) << endl;
	cout << "Left check: " << this->check_left(pieceID, 2, 3) << endl;
	cout << "Down check: " << this->check_down(pieceID, 2, 3) << endl;
	cout << "Up check: " << this->check_up(pieceID, 2, 3) << endl;
	cout << "Upper left check: " << this->check_upper_left(pieceID, 2, 3) << endl;
	cout << "Upper right check: " << this->check_upper_right(pieceID, 2, 3) << endl;
	cout << "Lower left check: " << this->check_lower_left(pieceID, 2, 3) << endl;
	cout << "Lower right check: " << this->check_lower_right(pieceID, 2, 3) << endl;
}

void Board_Tester::full_board_test() {
	cout << "Full board test:" << endl;
	this->test_board_initialization();
	this->test_drop_piece();
	this->test_player_win();
	this->test_bot_win();
	this->test_checks();
}

/* Old board test code

void test_board_initialization() {
	cout << "Board initialization test:" << endl;
	cout << "Creating board...:" << endl;
	Board board;
	cout << "Displaying board...:" << endl;
	cout << board;
}

void test_drop_piece() {
	cout << "Board drop piece test:" << endl;
	Board board;
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping player piece in column " << i << endl;
		board.drop_piece(i, 1);
		cout << board;
	}
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping bot piece in column " << i << endl;
		board.drop_piece(i, 2);
		cout << board;
	}
}

void test_player_win() {
	cout << "Player win test:" << endl;
	Board board;
	for (int i = 0; i < 4; i++) {
		board.drop_piece(i, 1);
	}
	cout << board;
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
	cout << board;
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
	cout << board;
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

*/