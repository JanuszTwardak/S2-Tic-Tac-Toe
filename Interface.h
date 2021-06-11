//
// Created by Janusz on 28.03.2020.
//

#ifndef L2Z1_INTERFACE_H
#define L2Z1_INTERFACE_H
#include "Board.h"
#include <array>

//  Klasa odpowiadajaca za wyswietlanie wszystkiego w konsoli

class Interface {

public:

    //  metody
    explicit Interface(Board *board);   //  konstruktor
    void printBoard();  //  drukuje tabelke z polami na ekran
    void welcomingMessage();    //  drukuje wiadomosc powitalna
    void nextTurnMessage();     //  drukuje wiadomosc rozpoczetej tury
    bool gameOverMessage();     //  drukuje wiadomosc, ktora wystepuje przy koncu gry
    string getCoordinates();    //  pobiera przez uzytkownika informacje, ktore pole chce wybrac

    //  getters
    Board &getBoard();  //  zwraca referencje na board (referencja na zawartosc ukryta pod wskaznikiem na board)

private:
    //  zmienne
    Board *boardPointer;    //  wskaznik na obiekt przechowujacy wszystkie dane gry
};


#endif //L2Z1_INTERFACE_H
