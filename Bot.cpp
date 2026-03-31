#include "Bot.h"

int Bot::getMove(Board trueBoard) {
	/*
	 * Class: Bot
	 * Name: getMove
	 * Input(s): trueBoard - the current state of the board
	 * Return: the column index of the best move for the bot
	 * Description: This function passes the true board to the calculateWeights
	 *		function to fill the weights array with the current weight for each
	 *		column. It then determines the index of the column with the highest
	 *		weight.
	 */
	calculateWeights(trueBoard);
	int max_weight = weights[0];
	int weight_index = 0;
	for (int i = 1; i < COLUMNS; i++) {
		if (weights[i] > max_weight) {
			max_weight = weights[i];
			weight_index = i;
		}
	}
	return weight_index;
}

void Bot::calculateWeights(Board trueBoard) {
	/*
	 * Class: Bot
	 * Name: calculateWeights
	 * Input(s): trueBoard - the current state of the board
	 * Return: void
	 * Description: This function takes the current state of the board and fills
	 *		the weights array with the calculated weight in each column. The function
	 *		uses nested loops to simulate dropping a bot piece in each column and
	 *		then dropping a player piece in each column. The weights are calculated 
	 *		based on the following:
	 *			-1,000,000 if the bot cannot drop a piece in the column (column is full)
	 *			+1,000,000 if a move in the column would result in an immediate win for the bot
	 *			-100,000 if the player has a winning move in the next turn
	 *			+the total number of bot connections on the board after the move
	 *			+the increase in the bot's highest connection after the move
	 *			-the total number of player connections on the board after the move
	 *			+3 times the increase in the player's highest connection after the move 
	 *				(weighted more heavily than bot connections to prioritize blocking player wins)
	 *		optimizations to the speed of this function were made using continue; to skip unnecessary
	 *		evaluations.
	 */
	for (int i = 0; i < COLUMNS; i++) {
		weights[i] = 0;
		tempBoard = trueBoard;
		int botHighest = tempBoard.checkHighestConnection(2);
		int playerHighest = tempBoard.checkHighestConnection(1);
		//drop a bot piece in column i, if bot win, add very high weight
		try{tempBoard.dropPiece(i, 2);}
		catch (std::out_of_range& e) {
			weights[i] = -1000000;
			continue;
		}
		if (tempBoard.checkBotWin()) {
			weights[i] += 1000000;
			continue;
		}
		for (int j = 0; j < COLUMNS; j++) {
			//drop a player piece in column j
			// if player win, subtract high weight
			//add all bot connections to weight
			//subract all player connections from weight
			tempBoard2 = tempBoard;
			try { 
				tempBoard2.dropPiece(j, 1); 
				if (tempBoard2.checkPlayerWin()) {
					weights[i] -= 100000;
					continue;
				}
				weights[i] += (1 * tempBoard2.checkAllConnections(2) + 1 * (botHighest - tempBoard2.checkHighestConnection(2)));
				weights[i] -= (1 * tempBoard2.checkAllConnections(1) + 3 * (playerHighest - tempBoard2.checkHighestConnection(1)));
			}
			catch (std::out_of_range& e) {
				weights[i] += (1 * tempBoard2.checkAllConnections(2) + 1 * (botHighest - tempBoard2.checkHighestConnection(2)));
				weights[i] -= (1 * tempBoard2.checkAllConnections(1) + 3 * (playerHighest - tempBoard2.checkHighestConnection(1)));
				continue;
			}
		}
	}
}

int Bot::firstMove() {
	/*
	 * Class: Bot
	 * Name: firstMove
	 * Input(s): none
	 * Return: the column index of the first move for the bot
	 * Description: Determine a random number for the first move of the bot
	 */
	int first_move = rand() % COLUMNS;
	return first_move;
}

Bot::Bot() {
	/*
	 * Class: Bot
	 * Name: Bot (constructor)
	 * Input(s): none
	 * Return: none
	 * Description: Default constructor for the Bot class. Initializes the weights array to 0.
	 */
	for (int i = 0; i < COLUMNS; i++) {
		weights[i] = 0;
	}
}

Bot::~Bot() {
	/*
	 * Class: Bot
	 * Name: ~Bot (destructor)
	 * Input(s): none
	 * Return: none
	 * Description: Destructor for the bot class, no dynamic memory to free so it is empty.
	 *		Exists purely because required.
	 */
}