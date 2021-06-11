//
// Created by Janusz on 29.03.2020.
//

#include "GameOver.h"
#include <iostream>
using namespace std;

GameOver::GameOver(Board *board) {
    GameOver::boardPointer = board;
}


bool GameOver::checkIfGameOver() {
    if (getBoard().getTurnCounter() > 5) {
        checkRows();
        checkColumns();
        checkDiagonal();
        if (isColumnWinning || isDiagonalWinning || isRowWinning) {
            clearFieldCheckers();
            return true;
        }
    }
        return false;
}


void GameOver::clearFieldCheckers() {
    isColumnWinning = false;
    isDiagonalWinning = false;
    isRowWinning = false;
}


void GameOver::checkColumns() {
    for (int i = 0; i < 3; i++) {
        if((getBoard().getAllFields().at(0).at(i) == getBoard().getAllFields().at(1).at(i)) && (getBoard().getAllFields().at(1).at(i) == getBoard().getAllFields().at(2).at(i)) && (getBoard().getAllFields().at(2).at(i) != Board::FieldType::FIELD_NULL)) {
            for (int j = 0; j < 3; j++) {
                getBoard().getWinningFields().at(j).at(i) = true;
            }
            isColumnWinning = true;
        }
    }
}


void GameOver::checkRows() {
    for (int i = 0; i < 3; i++) {
        if((getBoard().getAllFields().at(i).at(0) == getBoard().getAllFields().at(i).at(1)) && (getBoard().getAllFields().at(i).at(1) == getBoard().getAllFields().at(i).at(2)) && (getBoard().getAllFields().at(i).at(2) != Board::FieldType::FIELD_NULL)) {
            for (int j = 0; j < 3; j++) {
                getBoard().getWinningFields().at(i).at(j) = true;
            }
            isRowWinning = true;
        }
    }
}


void GameOver::checkDiagonal() {
    if((getBoard().getAllFields().at(0).at(0) == getBoard().getAllFields().at(1).at(1)) && (getBoard().getAllFields().at(1).at(1) == getBoard().getAllFields().at(2).at(2)) && (getBoard().getAllFields().at(2).at(2) != Board::FieldType::FIELD_NULL)) {
        for (int i = 0; i < 3; i++) {
            getBoard().getWinningFields().at(i).at(i) = true;
        }
        isDiagonalWinning = true;
    }
    else if((getBoard().getAllFields().at(0).at(2) == getBoard().getAllFields().at(1).at(1)) && (getBoard().getAllFields().at(1).at(1) == getBoard().getAllFields().at(2).at(0)) && (getBoard().getAllFields().at(2).at(0) != Board::FieldType::FIELD_NULL)) {
        for (int i = 0; i < 3; i++) {
            getBoard().getWinningFields().at(i).at(2 - i) = true;
        }
        isDiagonalWinning = true;
    }
}


Board &GameOver::getBoard() {
    Board &helper = *GameOver::boardPointer;
    return helper;
}







