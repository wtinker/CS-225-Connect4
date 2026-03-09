#pragma once
#ifndef BOT
#define BOT
using "Board.h";
// BOT FILE

class Bot {
  private:
    int weights[7];
	Board tempBoard;
	void calculate_weights(const Board&);
	int check_down();
	int check_up();
	int check_left();
	int check_right();
	int check_upper_left();
	int check_upper_right();
	int check_lower_left();
	int check_lower_right();
  public:
	int get_move(const Board&);
};

int Bot::get_move(const Board& trueBoard) {
	calculate_weights(trueBoard);
	int max_weight = weights[0];
	int weight_index = 0;
	for (int i = 1; i < 7; i++) {
		if (weights[i] > max_weight) {
			max_weight = weights[i];
			weigt_index = i;
		}
	}
	return weight_index;
}

#endif // !BOT
