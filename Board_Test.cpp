#include "Board_Test.h"
#include <iostream>
#include <ctime>

using namespace std;

void BoardTester::testBoardInitialization() {
	cout << "Board initialization test:" << endl;
	cout << "Creating board...:" << endl;
	this->resetBoard();
	cout << "Displaying board...:" << endl;
	cout << *this;
}
void BoardTester::testDropPiece() {
	cout << "Board drop piece test:" << endl;
	this->resetBoard();
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping player piece in column " << i << endl;
		this->dropPiece(i, 1);
		cout << *this;
	}
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Dropping bot piece in column " << i << endl;
		this->dropPiece(i, 2);
		cout << *this;
	}
}

void BoardTester::testPlayerWin() {
	cout << "Player win test:" << endl;
	this->resetBoard();
	for (int i = 0; i < 4; i++) {
		this->dropPiece(i, 1);
	}
	cout << *this;
	if (this->checkPlayerWin()) {
		cout << "Player win detected successfully!" << endl;
	}
	else {
		cout << "Player win detection failed!" << endl;
	}
}

void BoardTester::testBotWin() {
	cout << "Bot win test:" << endl;
	this->resetBoard();
	for (int i = 0; i < 4; i++) {
		this->dropPiece(i, 2);
	}
	cout << *this;
	if (this->checkBotWin()) {
		cout << "Bot win detected successfully!" << endl;
	}
	else {
		cout << "Bot win detection failed!" << endl;
	}
}

void BoardTester::testChecks() {
	srand(time(NULL));
	cout << "Check functions test:" << endl;
	this->resetBoard();
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			int id = rand() % 2 + 1;
			this->dropPiece(i, id);
		}
	}
	cout << *this;
	int pieceID = this->getId(2, 3);
	cout << "Calculating checks for center piece ID "<< pieceID << endl;
	cout << "Right check: " << this->checkRight(pieceID, 2, 3) << endl;
	cout << "Left check: " << this->checkLeft(pieceID, 2, 3) << endl;
	cout << "Down check: " << this->checkDown(pieceID, 2, 3) << endl;
	cout << "Up check: " << this->checkUp(pieceID, 2, 3) << endl;
	cout << "Upper left check: " << this->checkUpperLeft(pieceID, 2, 3) << endl;
	cout << "Upper right check: " << this->checkUpperRight(pieceID, 2, 3) << endl;
	cout << "Lower left check: " << this->checkLowerLeft(pieceID, 2, 3) << endl;
	cout << "Lower right check: " << this->checkLowerRight(pieceID, 2, 3) << endl;
}

void BoardTester::fullBoardTest() {
	cout << "Full board test:" << endl;
	this->testBoardInitialization();
	this->testDropPiece();
	this->testPlayerWin();
	this->testBotWin();
	this->testChecks();
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