#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include "Move.h"
#include <cstdlib> //Für system("cls")

int main()
{

    //Initialisierung der Spielumgebung
    Game g;

    //User müssen nach ihren Namen gefragt werden.
    g.UserNames();

    //Player Symbole werden initialisiert
    g.Players[0].symbol = 'X';
    g.Players[1].symbol = 'O';

    //Konsole clearen
    system("cls");

    //PlayerInfo und Spielfeld ausgeben
    g.PrintGame();

    //Zusatz: (Abfragen, bis wie viel die Spieler spielen wollen)

    //Variable initialisieren, die überwacht ob ein Gewinner gefunden worden ist.
    bool winnerFound = false;


    //counter zum überwachen wer gerade dran ist
    int counter = 0;

    //Solange kein Gewinner gefunden worden ist soll folgende Schleife wiederholt werden
    while (!winnerFound) {

        //Spieler nach Move fragen und in "move" speichern
        Move move = g.Players[counter % 2].getMove();

        //Konsole clearen
        system("cls");

        //Wenn der Move nicht legal ist, soll das Einlesen wiederholt werden
        if (!g.b.isLegal(move)) {

            std::cout << "Invalider Move, versuch es nochmal..." << std::endl;
            continue;
        }

        //Falls der Move legal ist, ist der nächste Spieler an der Reihe und das neue Board wird geprintet

        g.b.grid[move.row - 1][move.col - 1] = move.symbol;

        counter++;

        g.PrintGame();

        //prüfen ob der Spieler gewonnen hat
        if (g.checkWinner() != "") {

            //Konsole clearen
            system("cls");

            std::cout << "\n\n\n" << "$$$ " << g.checkWinner() << ", du hast gewonnen $$$" << "\n\n\n\n";

            //Spieler suchen, der gewonnen hat uns deinen Score inkrementieren

            winnerFound = true;
        }

        if (g.b.isFull()) {

            std::cout << std::endl << "Unentschieden";

            winnerFound = true;
        }
    }
}

