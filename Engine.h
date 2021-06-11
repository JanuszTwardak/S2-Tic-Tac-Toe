//
// Created by Janusz on 28.03.2020.
//

#ifndef L2Z1_ENGINE_H
#define L2Z1_ENGINE_H

#include "Board.h"
#include "Interface.h"
#include "GameOver.h"

//  Klasa odpowiadajaca za mechanizm i dzialanie gry



class Engine {

public:
    // metody
    Engine();   //  konstruktor
    void startNewGame();    //  rozpoczyna nowa gre
    void nextTurn();    //  rozpoczyna nowa ture
    static bool checkIfProperInput(string input);   //  zwraca boola, jesli input podany przez gracza zgadza sie z wymaganym

    //  getters
    Board &getBoard();  //  zwraca referencje boardu
    Interface &getInferface();  //  zwraca referencje interfacu

private:
    //  zmienne
    Board board;    //  obiekt przechowujacy wszystkie dane gry
    Interface interface = Interface(&board);    //  obiekt odpowiedzialny za pobieranie danych oraz wyswietlanie gry na ekranie
    GameOver checkIfGO = GameOver(&board);  //  obiekt odpowiedzialny za sprawdzanie, czy nastapil koniec gry i jesli tak to kto wygral
};


#endif //L2Z1_ENGINE_H
