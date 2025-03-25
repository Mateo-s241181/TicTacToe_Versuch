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

		//Cin.fail gibt true zurück, wenn das letzte Input nicht in den Variablen gespeichert werden konnte. Es entsteht ein Errorbit, den die Funktion prüft.
		if (std::cin.fail()) {

			std::cout << "\n\nInput failed, try again \n\n";

			//löscht Errorbits, nicht den Inhalt des Buffers
			std::cin.clear();
			//Ignoriert die alles im Buffer, bis ein '\n' vorkommt
			//std::cin.ignore(Wie viele Zeichen soll ich ignorieren? (maximale Anzahl), Bei Welchem Zeichen soll ich abbrechen? (\n))
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			//Invalider Move wird returned => Neue Abfrage in main()
			return result;
		}


		result.row = x;
		result.col = y;
		result.symbol = symbol;

		return result;
	}
};

#endif