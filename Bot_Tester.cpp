#include "Bot_Tester.h"

using namespace std;

void BotTester::loadBoard(int board[ROWS][COLUMNS]) {
	b = board;
}

void BotTester::testCalculateWeights() {
	calculateWeights(b);
	cout << "Board: " << endl;
	cout << b;
	cout << "Weights: ";
	for (int i = 0; i < COLUMNS; i++) {
		cout << weights[i] << " ";
	}
	cout << endl;
}

void BotTester::testGetMove() {
	int move = getMove(b);
	cout << "Board: " << endl;
	cout << b;
	cout << "Best move: " << move  + 1<< endl;
}

void BotTester::testFirstMove() {
	int move_counts[COLUMNS] = { 0 };
	for (int i = 0; i < 1000; i++) {
		int move = firstMove();
		move_counts[move]++;
	}
	cout << "First move distribution after 1000 trials:" << endl;
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Column " << i << ": " << move_counts[i] << " times" << endl;
	}
}

void  BotTester::randomBoard(int rows) {
	b.resetBoard();
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < rows; j++) {
			int id = rand() % 2 + 1;
			b.dropPiece(i, id);
		}
	}
}

void BotTester::dispBoard() {
	cout << b;
}