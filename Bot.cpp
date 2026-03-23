#include "Bot.h"

int Bot::get_move(const Board& trueBoard) {
	calculate_weights(trueBoard);
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

void Bot::calculate_weights(const Board& trueBoard) {
	for (int i = 0; i < COLUMNS; i++) {
		weights[i] = 0;
		tempBoard = trueBoard;
		//drop a bot piece in column i, if bot win, add 10000 weight
		tempBoard.drop_piece(i, 2); 
		if (tempBoard.check_bot_win()) {
			weights[i] += 10000;
		}
		for (int j = 0; j < COLUMNS; j++) {
			//drop a player piece in column j
			// if player win, subtract 1000 weight
			//add all bot connections to weight
			//subract all player connections from weight
			tempBoard2 = tempBoard;
			tempBoard2.drop_piece(j, 1);
			if (tempBoard2.check_player_win()) {
				weights[i] -= 1000;
			}
			weights[i] += tempBoard2.check_all_connections(2);
			weights[i] -= tempBoard2.check_all_connections(1);
		}
	}
}

int Bot::first_move() {
	srand(time(NULL));
	int first_move = rand() % COLUMNS;
	return first_move;
}