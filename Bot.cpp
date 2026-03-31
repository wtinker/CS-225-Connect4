#include "Bot.h"

int Bot::getMove(Board trueBoard) {
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
	int first_move = rand() % COLUMNS;
	return first_move;
}

Bot::Bot() {
	for (int i = 0; i < COLUMNS; i++) {
		weights[i] = 0;
	}
}

Bot::~Bot() {
	// No dynamic memory to free
}