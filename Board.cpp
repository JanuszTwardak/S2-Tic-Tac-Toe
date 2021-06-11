//
// Created by Janusz on 28.03.2020.
//

#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    clearBoard();
}

array<array<Board::FieldType, 3>, 3> &Board::getAllFields() {
    array<array<FieldType, 3>, 3> &helper = Board::allFields;
    return helper;
}

void Board::clearBoard() {
    turnCounter = 1;

    for (array<Board::FieldType , 3> &iteratedRow: Board::getAllFields()) {
        for (Board::FieldType &iteratedElement: iteratedRow) {
            iteratedElement = Board::FieldType::FIELD_NULL;
        }
    }
}




bool Board::setField(string input) {  // na inpucie dostaje string w formacie "A1"
    string helper(1, input.at(1)); // tworzy string, ktory wypelnia n (1) elementami, ktore sa kopiami c (input.at(1))
    int row = stoi(helper) - 1; // odejmujemy jeden ze wzgledu na numeracje
    int column = convertLetter(input.at(0));

    if (checkField(column, row, Board::FieldType::FIELD_NULL)) {
        getAllFields().at(row).at(column) = getCurrentTurn();   //  ustawia wybrane pole na gracza, ktory wykonuje ture
        return true;
    }
    else if (checkField(column, row, Board::FieldType::FIELD_X) || checkField(column, row, Board::FieldType::FIELD_O)){
        cout << "\nTo pole jest juz zajete, musisz wybrac inne!";
        return false;
    }
    else {
        cout <<"\n POLE NIE JEST ANI NULL, ANI X, ANI O";
        return false;
    }
}

bool Board::checkField(int column, int row, Board::FieldType type) {
    return (getAllFields().at(row).at(column) == type);   //  zwraca true jesli pole zgadza sie podanym lub false w przeciwnym wypadku
}

int Board::convertLetter(char letter) {
    switch (letter) {   //  przepisujemy litere na odpowiednia cyfre
        case 'a':
        case 'A':
            return 0;
        case 'b':
        case 'B':
            return 1;
        case 'c':
        case 'C':
            return 2;
        default:
            cout << "<ERROR> letter nie moze byc rozne od A, B lub C <ERROR>";
            return 2;
    }
}
Board::FieldType &Board::getCurrentTurn() {
    Board::FieldType &helper = Board::currentTurn;
    return helper;
}

int &Board::getTurnCounter() {
    int &helper = Board::turnCounter;
    return helper;
}

array<array<bool, 3>, 3> &Board::getWinningFields() {
    array<array<bool, 3>, 3> &helper = Board::winningFields;
    return helper;
}

void Board::clearWinningFields() {
    getWinningFields() = {{{false, false, false}, {false, false, false}, {false, false, false} }};
}

bool Board::checkIfWinningFieldExist() {

    for (array<bool , 3> &iteratedRow: Board::getWinningFields()) {
        for (bool &iteratedElement: iteratedRow) {
            if (iteratedElement) {return true;}
        }
    }
    return false;
}

bool &Board::getIsPlayingAgain() {
    bool &helper = Board::isPlayingAgain;
    return helper;
}




