//
// Created by Janusz on 28.03.2020.
//

#include "Engine.h"
#include "Interface.h"
#include <iostream>
using namespace std;

Engine::Engine() {
    do {
        getBoard().getIsPlayingAgain() = false; //  resetowanie przy nowej grze
        startNewGame();
    } while (getBoard().getIsPlayingAgain());
}


void Engine::startNewGame() {
    while((!Engine::checkIfGO.checkIfGameOver()) && (getBoard().getTurnCounter() < 10)) {    //  UWAGA: ostatni ruch NIE jest wykonywany automatycznie
        nextTurn();
    }

    if (getInferface().gameOverMessage()) {getBoard().getIsPlayingAgain() = true;}
    getBoard().getCurrentTurn() = Board::FieldType::FIELD_X;    //  domyslnie zawsze startuje X
    getBoard().getTurnCounter() = 1;    //  reset licznika
    getBoard().clearBoard();
    getBoard().clearWinningFields();
}


void Engine::nextTurn() {
    getInferface().nextTurnMessage();   //  wywoluje wiadomosc nastepnej tury

    // getCoordinates czyta input z klawiatury, a potem przekazuje do setField, ktore zmienia pole na zajete
    while (!getBoard().setField(getInferface().getCoordinates())) {};
    //  ALE jesli pole jest juz zajete, setField zwraca false i uzytkownik musi podac inne

    if (getBoard().getCurrentTurn() == Board::FieldType::FIELD_X) {     //  przekazanie tury drugiemu graczowi
        getBoard().getCurrentTurn() = Board::FieldType::FIELD_O;
    }
    else if (getBoard().getCurrentTurn() == Board::FieldType::FIELD_O){
        getBoard().getCurrentTurn() = Board::FieldType::FIELD_X;
    } else {
        cout << "\n<ERROR> currentTurn nie moze byc rowny FIELD_NULL <ERROR>";
    }

    getBoard().getTurnCounter()++;  //  zwieksza licznik tur
}


bool Engine::checkIfProperInput(string input) {
    //  WARUNKI PRAWIDLOWEGO POLA
    //  dlugosc inputu to 2 znaki
    if (input.length() != 2) {
        cout << "Nie ma takiego pola!";
        return false;
    }

    //  pierwszy znak to litera A, B lub C (lub pisane z malej litery)
    switch (input.at(0)) {
        default:
            cout << "Nie ma takiego pola!";
            return false;
        case 'A':
        case 'a':
        case 'B':
        case 'b':
        case 'C':
        case 'c':
            break;
    }

    //  drugi znak to cyfra 1, 2 lub 3
    switch (input.at(1)) {
        case '1':
        case '2':
        case '3':
            return true;
        default:
            cout << "Nie ma takiego pola!";
            return false;
    }
}

// gettery
Board &Engine::getBoard() {
    Board &helper = Engine::board;
    return helper;
}

Interface &Engine::getInferface() {
    Interface &helper = Engine::interface;
    return helper;
}

