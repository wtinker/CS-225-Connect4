#include "Bot.h"

int Bot::get_move(Board trueBoard) {
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

void Bot::calculate_weights(Board trueBoard) {
	for (int i = 0; i < COLUMNS; i++) {
		weights[i] = 0;
		tempBoard = trueBoard;
		//drop a bot piece in column i, if bot win, add very high weight
		try{tempBoard.drop_piece(i, 2);}
		catch (std::out_of_range& e) {
			weights[i] = -1000000;
			continue;
		}
		if (tempBoard.check_bot_win()) {
			weights[i] += 1000000;
		}
		for (int j = 0; j < COLUMNS; j++) {
			//drop a player piece in column j
			// if player win, subtract high weight
			//add all bot connections to weight
			//subract all player connections from weight
			tempBoard2 = tempBoard;
			try { 
				tempBoard2.drop_piece(j, 1); 
				if (tempBoard2.check_player_win()) {
					weights[i] -= 100000;
				}
				weights[i] += (1 * tempBoard2.check_all_connections(2) + 1 * (trueBoard.check_highest_connection(2) - tempBoard2.check_highest_connection(2)));
				weights[i] -= (1 * tempBoard2.check_all_connections(1) + 3 * (trueBoard.check_highest_connection(1) - tempBoard2.check_highest_connection(1)));
			}
			catch (std::out_of_range& e) {
				weights[i] += (1 * tempBoard2.check_all_connections(2) + 1 * (trueBoard.check_highest_connection(2) - tempBoard2.check_highest_connection(2)));
				weights[i] -= (1 * tempBoard2.check_all_connections(1) + 3 * (trueBoard.check_highest_connection(1) - tempBoard2.check_highest_connection(1)));
				continue;
			}
		}
	}
}

int Bot::first_move() {
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