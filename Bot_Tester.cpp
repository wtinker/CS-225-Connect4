#include "Bot_Tester.h"

using namespace std;

void BotTester::loadBoard(int board[ROWS][COLUMNS]) {
	/*
	 * Class: BotTester
	 * Name: loadBoard
	 * Input(s): board - a 2D array representing the state of the board
	 * Return: void
	 * Description: Loads a custom board state to test certain cases for bot behavior.
	 *		Makes use of the overloaded assignment operator in the Board class to assign 
	 *		the 2D array to the board object.
	 */
	b = board;
}

void BotTester::testCalculateWeights() {
	/*
	 * Class: BotTester
	 * Name: testCalculateWeights
	 * Input(s): none
	 * Return: void
	 * Description: Tests the calculateWeights function with the currently loaded board.
	 *		Then, displays the board and the calculated weights for each column.
	 */
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
	/*
	 * Class: BotTester
	 * Name: testGetMove
	 * Input(s): none
	 * Return: void
	 * Description: Tests the getMove function with the currently loaded board. Then,
	 *		displays the board and the calculated best move for the bot.
	 */
	int move = getMove(b);
	cout << "Board: " << endl;
	cout << b;
	cout << "Best move: " << move  + 1<< endl;
}

void BotTester::testFirstMove() {
	/*
	 * Class: BotTester
	 * Name: testFirstMove
	 * Input(s): none
	 * Return: void
	 * Description: Runs the firstMove function 1000 times and counts the number each
	 *		column is returned, then displays the distribution of first moves.
	 */
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
	/*
	 * Class: BotTester
	 * Name: randomBoard
	 * Input(s): rows - the number of rows to fill with random pieces
	 * Return: void
	 * Description: Fills the board with random pieces up to the specified number of rows.
	 */
	b.resetBoard();
	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < rows; j++) {
			int id = rand() % 2 + 1;
			b.dropPiece(i, id);
		}
	}
}

void BotTester::dispBoard() {
	/*
	 * Class: BotTester
	 * Name: dispBoard
	 * Input(s): none
	 * Return: void
	 * Description: Displays the current state of the board. 
	 */
	cout << b;
}