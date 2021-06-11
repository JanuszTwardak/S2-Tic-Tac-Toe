//
// Created by Janusz on 28.03.2020.
//

#include "Interface.h"
#include "Engine.h"
#include <iostream>
#include <string>
using namespace std;

Interface::Interface(Board *board){
    welcomingMessage();
    Interface::boardPointer = board;  //  zapisanie wskaznika na obiekt board, ktory przechowuje wszystkie dane gry
}

Board& Interface::getBoard() {
    Board &helper = *Interface::boardPointer;
    return helper;
}

void Interface::printBoard() {
    cout << "        TURA " << getBoard().getTurnCounter() << "\n";
    cout << "\n     A  |  B  |  C"; //  rysowanie
    for (int i = 0; i < 3; i++) {
        cout << "\n   - - - - - - - - -";   //  rysowanie
        cout << "\n" << i + 1 << " | "; //  rysowanie

        for (int j = 0; j < 3; j++) {

            // drukowanie odpowiednich pol (switch nie obsluguje enuma, wiec niestety na ifach)
            if(getBoard().getAllFields().at(i).at(j) == Board::FieldType::FIELD_X) {
                switch (getBoard().getWinningFields().at(i).at(j)) {
                    case true:
                        cout << "[X]";
                        break;
                    case false:
                        cout << " X ";
                        break;
                }

            }
            else if(getBoard().getAllFields().at(i).at(j) == Board::FieldType::FIELD_O) {
                switch (getBoard().getWinningFields().at(i).at(j)) {
                    case true:
                        cout << "[O]";
                        break;
                    case false:
                        cout << " O ";
                        break;
                }
            }
            else {cout << "   ";}
            if (j != 2) {cout << " | ";}
        }
    }


}

void Interface::welcomingMessage() {
    cout << "Witaj w grze kolko i krzyzyk! \nWspolrzedne pol musza byc podane w formacie [LITERA][LICZBA] (przyklad: A1)\n\n";
}

void Interface::nextTurnMessage() {
    if (getBoard().getTurnCounter() != 1) {system("CLS");};

    printBoard();

    cout << "\n\nAktualny ruch: ";
    if(getBoard().getCurrentTurn() == Board::FieldType::FIELD_X)    cout << "X";
    else if(getBoard().getCurrentTurn() == Board::FieldType::FIELD_O)    cout << "O";
    else cout << "\n<ERROR> currentTurn nie moze przyjac FIELD_NULL <ERROR>";

}

string Interface::getCoordinates() {

    string coordinates;
    do {
        cout << "\nPodaj wspolrzedne: ";
        getline(cin, coordinates);
    }
    while(! Engine::checkIfProperInput(coordinates));

    return coordinates;
}

bool Interface::gameOverMessage() {
    system("CLS");
    printBoard();
    cout << "\n\nKoniec gry - ";
    if (!getBoard().checkIfWinningFieldExist()) {
        cout << "remis!";
    }
    else if (getBoard().getCurrentTurn() == Board::FieldType::FIELD_O) {
        cout << "wygral krzyzyk!";
    }
    else if (getBoard().getCurrentTurn() == Board::FieldType::FIELD_X) {
        cout << "wygralo kolko!";
    }

    cout << "\n Czy chcecie zagrac ponownie? Wpisz T aby zagrac ponownie lub cokolwiek innego, aby wyjsc z programu: ";
    char confirmation;
    cin >> confirmation;
    switch (confirmation){
            case 'T':
            case 't':
                system("CLS");
                return true;
            default:
                return false;
        }

}



