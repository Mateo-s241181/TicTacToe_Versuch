#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Move.h"


class Board
{
public:

	char grid[3][3];

	Board() {																		//Konstruktor Funktion essenziell für solche Klassen (Vergleichbar mit New() bei Golang structs

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				grid[i][j] = ' ';													//Alle Elemente im Grid werden auf ' ' gesetzt.
			}
		}

	}

	//Methode zum Ausgeben des Boards auf die Konsole

	void PrintBoard() {

		std::cout << "----------------- Spielfeld -----------------" << std::endl << std::endl;

		std::cout << "	 (1) (2) (3) " << std::endl;

		for (int j = 0; j < 3; j++) {

			std::cout << "	+---+---+---+" << std::endl;									//Erste Zeile 
			std::cout << "    (" << j + 1 << ") ";

			for (int i = 0; i < 3; i++) {													//For-Schleife um mittlere Zeilen mit den Zeichen auszugeben

				std::cout << "| " << grid[j][i] << " ";
			}

			std::cout << "|\n";


		}

		std::cout << "        +---+---+---+\n";												//Letzte Zeile


		std::cout << "\n---------------------------------------------\n\n\n\n\n\n\n\n\n\n\n";
		/*
		Board soll so aussehen:


			 (1) (2) (3)
			+---+---+---+
		(1)	| x | x | x |
			+---+---+---+
		(2)	| x | x | x |
			+---+---+---+
		(3)	| x | x | x |
			+---+---+---+
		*/
	}

	/*-----------------------------------Methoden um auf Win Condition zu checken-----------------------------------------------*/

	//Funktion prüft, ob alle Zeichen in einer Reihe c sind.
	bool RowContainsOnly(int row, char c) {

		//Jedes Element einer Zeile checken
		for (int i = 0; i < 3; i++) {

			//Wenn ein Element nicht c ist, ist die Aussage falsch
			if (grid[row][i] != c) {
				return false;
			}
		}
		//Ansonsten ist die Aussage wahr
		return true;
	}

	//Funktion prüft, ob alle Zeichen in einer Spalte c sind
	bool ColContainsOnly(int col, char c) {

		//Jedes Element in der Spalte checken
		for (int i = 0; i < 3; i++) {

			//Wenn ein Element nicht gleich c ist falsch zurückgeben
			if (grid[i][col] != c) {
				return false;
			}
		}
		//Ansonsten ist die Aussage wahr
		return true;
	}

	//Funktion prüft ob alle Zeichen in der Diagonalen von links oben nach rechts unten c sind
	bool DiagDownRightContainsOnly(char c) {

		for (int i = 0; i < 3; i++) {

			if (grid[i][i] != c) {
				return false;
			}
		}
		return true;
	}

	//Funktion prüft ob alle Zeichen in der Diagonalen von links unten nach rechts oben c sind
	bool DiagUpLeftContainsOnly(char c) {

		for (int i = 0; i < 3; i++) {

			//RICHTIGE INIZES???
			if (grid[2 - i][i] != c) {
				return false;
			}
		}
		return true;
	}

	//Methode prüft ob ein Zug auf dem Board legal ist
	bool isLegal(Move m) {

		//Checken ob row oder col out of Range ist
		/*if (m.row < 0 || m.row > 3 || m.col < 0 || m.col > 3) {
			return false;
		}*/
		
		if (m.row > 0 && m.row <= 3 && m.col > 0 && m.col <= 3) {
			//Checken ob der Platz, an dem das Symbol hingesetzt werden soll, frei ist
			if (grid[m.row - 1][m.col - 1] != ' ') {
				return false;
			}
			return true;
		}

		return false;
	}

	//Methode nimmt einen Zug als Input an und setzt ihn auf das Board, falls er valide ist.
	//Gibt außerdem an, ob der eingegebene zug tatsächlich auf das Board gesetzt worden ist.

	void setMove(Move m) {

		//Checken ob der eingegebene Zug legal ist
		if (!isLegal(m)) {

			std::cout << "Dein eingegebener Zug ist nicht legal." << std::endl;
			return;
		}

		//Falls legal, Zug auf das Board printen

		grid[m.row - 1][m.col - 1] = m.symbol;
	}

	bool isFull() {

		for (int i = 0; i < 3; i++) {

			for (int j = 0; j < 3; j++) {

				if (grid[i][j] == ' ') {
					return false;
				}
			}
		}
		return true;
	}





};


#endif

