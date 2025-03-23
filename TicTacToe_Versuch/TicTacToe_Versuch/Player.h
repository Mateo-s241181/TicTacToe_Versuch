#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Move.h"

class Player {

public:

	std::string name;
	int score;
	char symbol;

	Player() {
		name = "";
		score = 0;
		symbol = ' ';
	}

	int getScore() {
		return score;
	}

	std::string getName() {
		return name;
	}

	void IncrementScore() {
		score++;
	}

	Move getMove() {

		std::cout << name << ", gib ein valides Feld für deinen nächsten Zug an (row/col mit Leerzeichen getrennt)" << std::endl;

		int x{};
		int y{};

		std::cin >> x >> y;

		Move result = Move();

		result.row = x;
		result.col = y;
		result.symbol = symbol;

		return result;
	}
};

#endif