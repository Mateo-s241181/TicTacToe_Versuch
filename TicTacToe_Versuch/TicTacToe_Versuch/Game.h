#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Player.h"
#include "Board.h"



class Game {

public:

	Player Players[2];
	Board b;

	//TODO: NumberOfGames hinzufügen

	//Konstruktor Funktion für Klasse Game
	Game() {
		//Leere Player Klassen Initialisieren
		for (int i = 0; i < 2; i++) {
			Players[i] = Player();
		}

		//Leeres Board initialisieren
		b = Board();
	}

	//Methode lässt den User die Namen der beiden Spieler festlegen
	void UserNames() {

		std::cout << "Geben Sie den Namen von Spieler 1 ein: ";
		std::cin >> Players[0].name;
		std::cout << "\nGeben Sie den Namen von Spieler 2 ein: ";
		std::cin >> Players[1].name;
	}

	//Methode check die WinCondition und ordnet sie Falls vorhanden einem Player zu

	bool symbolWins(char c) {

		if (b.DiagDownRightContainsOnly(c) || b.DiagUpLeftContainsOnly(c)) {
			return true;
		}

		for (int i = 0; i < 3; i++) {

			if (b.RowContainsOnly(i, c) || b.ColContainsOnly(i, c)) {
				return true;
			}
		}
		return false;
	}

	std::string checkWinner() {

		for (int i = 0; i < 2; i++) {

			if (symbolWins(Players[i].symbol)) {
				return Players[i].getName();
			}
		}
		return "";
	}

	void PrintGame() {
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Spieler 1: " << Players[0].getName() << "   (" << Players[0].symbol << ")" << "       Score: " << Players[0].getScore() << std::endl << std::endl;
		std::cout << "Spieler 2: " << Players[1].getName() << "   (" << Players[1].symbol << ")" << "       Score: " << Players[1].getScore() << std::endl;
		std::cout << "-------------------------------------" << std::endl << std::endl;
		b.PrintBoard();
	}

};

#endif
