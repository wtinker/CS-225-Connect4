#include "Bot_Tester.h"

using namespace std;

void Bot_Tester::load_board(int board[ROWS][COLUMNS]) {
	b = board;
}

void Bot_Tester::test_calculate_weights() {
	calculate_weights(b);
	cout << "Board: " << endl;
	cout << b;
	cout << "Weights: ";
	for (int i = 0; i < COLUMNS; i++) {
		cout << weights[i] << " ";
	}
	cout << endl;
}

void Bot_Tester::test_get_move() {
	int move = get_move(b);
	cout << "Board: " << endl;
	cout << b;
	cout << "Best move: " << move  + 1<< endl;
}

void Bot_Tester::test_first_move() {
	int move_counts[COLUMNS] = { 0 };
	for (int i = 0; i < 1000; i++) {
		int move = first_move();
		move_counts[move]++;
	}
	cout << "First move distribution after 1000 trials:" << endl;
	for (int i = 0; i < COLUMNS; i++) {
		cout << "Column " << i << ": " << move_counts[i] << " times" << endl;
	}
}

void  Bot_Tester::random_board(int rows) {
	b.reset_board();
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < rows; j++) {
			int id = rand() % 2 + 1;
			b.drop_piece(i, id);
		}
	}
}

void Bot_Tester::disp_board() {
	cout << b;
}