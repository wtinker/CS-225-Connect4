#include "Bot_Tester.h"

using namespace std;

void Bot_Tester::load_board(int board[ROWS][COLUMNS]) {
	b = board;
}

void Bot_Tester::test_calculate_weights() {
	calculate_weights(b);
	cout << "Weights: ";
	for (int i = 0; i < COLUMNS; i++) {
		cout << weights[i] << " ";
	}
	cout << endl;
}