#include "Bot.h"

int Bot::get_move(const Board& trueBoard) {
	calculate_weights(trueBoard);
	int max_weight = weights[0];
	int weight_index = 0;
	for (int i = 1; i < 7; i++) {
		if (weights[i] > max_weight) {
			max_weight = weights[i];
			weight_index = i;
		}
	}
	return weight_index;
}

void Bot::calculate_weights(const Board& trueBoard) {}