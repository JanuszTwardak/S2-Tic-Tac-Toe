//
// Created by Janusz on 29.03.2020.
//

#ifndef L2Z1_GAMEOVER_H
#define L2Z1_GAMEOVER_H


#include "Board.h"

class GameOver {

public:
    //  metody
    explicit GameOver(Board *board);    //  konstruktor
    Board &getBoard();  //  zwraca referencje na board (referencja na zawartosc ukryta pod wskaznikiem na board)
    void clearFieldCheckers();  //  czysci informacje o boolach informujacych o jakiejkolwiek wygranej
    void checkRows();   //  sprawdza, czy nastapila wygrana w odpowiednio: rzedzie / kolumnie / diagonalu (i zapisuje w board.winningFields dokladnie, gdzie)
    void checkColumns();    //  ^
    void checkDiagonal();   //  ^
    bool checkIfGameOver(); //  zwraca true jesli nastapila gdziekolwiek wygrana (jakiekolwiek z booli isWinning jest true)

private:
    Board *boardPointer;    //  przechowuje wskaznik na board
    bool isRowWinning = false,  //  boole przechowujace informacje, czy nastapila wygrana w jakiejkolwiek kolumnie / rzedzie / przekatnej
    isColumnWinning = false,    //  ^
    isDiagonalWinning = false;  //  ^

};


#endif //L2Z1_GAMEOVER_H
