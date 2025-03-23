#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include "Move.h"

int main()
{

    //Initialisierung der Spielumgebung
    Game g;

    //User müssen nach ihren Namen gefragt werden.
    g.UserNames();

    //Player Symbole werden initialisiert
    g.Players[0].symbol = 'X';
    g.Players[1].symbol = 'O';

    //User Namen auf die Konsole ausgeben
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Spieler 1: " << g.Players[0].getName() << "   (" << g.Players[0].symbol << ")" << std::endl << std::endl;
    std::cout << "Spieler 2: " << g.Players[1].getName() << "   (" << g.Players[1].symbol << ")" << std::endl;
    std::cout << "-------------------------------------" << std::endl << std::endl;

    //Zusatz: (Abfragen, bis wie viel die Spieler spielen wollen)

    //Spiel ist Initialisiert

    //Ablauf eines Zuges in eine while-Schleife schreiben

    bool winnerFound = false;

    std::cout << "----------------- Spielfeld -----------------" << std::endl << std::endl;
    g.b.PrintBoard();
    std::cout << "\n---------------------------------------------\n\n\n\n\n\n\n\n\n\n" << std::endl;

    //counter zum überwachen wer gerade dran ist
    int counter = 0;

    //Solange kein Gewinner gefunden worden ist soll folgende Schleife wiederholt werden
    while (!winnerFound) {


        Move move = g.Players[counter % 2].getMove();

        //Wenn der Move nicht legal ist, soll das Einlesen wiederholt werden
        if (!g.b.isLegal(move)) {

            std::cout << "Invalider Move, versuch es nochmal..." << std::endl;
            continue;
        }

        //Falls der Move legal ist, ist der nächste Spieler an der Reihe und das neue Board wird geprintet

        g.b.grid[move.row - 1][move.col - 1] = move.symbol;

        counter++;

        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Spieler 1: " << g.Players[0].getName() << "   (" << g.Players[0].symbol << ")" << std::endl << std::endl;
        std::cout << "Spieler 2: " << g.Players[1].getName() << "   (" << g.Players[1].symbol << ")" << std::endl;
        std::cout << "-------------------------------------" << std::endl << std::endl;
        std::cout << "----------------- Spielfeld -----------------" << std::endl << std::endl;
        g.b.PrintBoard();
        std::cout << "\n---------------------------------------------\n\n\n" << std::endl;
        std::cout << "\n\n\n\n\n\n\n";

        //prüfen ob der Spieler gewonnen hat
        if (g.checkWinner() != "") {

            std::cout << "\n\n\n\n\n\n\n" << "$$$ " << g.checkWinner() << ", du hast gewonnen $$$" << "\n\n\n\n\n\n\n\n";

            //Spieler suchen, der gewonnen hat uns deinen Score inkrementieren

            winnerFound = true;
        }

        if (g.b.isFull()) {

            std::cout << std::endl << "Unentschieden";

            winnerFound = true;
        }
    }
}

