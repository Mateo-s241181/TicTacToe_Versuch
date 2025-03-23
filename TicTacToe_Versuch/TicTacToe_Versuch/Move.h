#ifndef MOVE_H
#define MOVE_H


class Move
{
public:

	int row;
	int col;
	char symbol;

	Move() {
		row = -1;
		col = -1;
		symbol = ' ';
	}
};

#endif
