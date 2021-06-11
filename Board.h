//
// Created by Janusz on 28.03.2020.
//

#ifndef L2Z1_BOARD_H
#define L2Z1_BOARD_H

#include <array>
using namespace std;

//  Klasa przechowujaca wszystkie dane dotyczace gry
class Board {
public:
    //  zmienne
    enum class FieldType{FIELD_NULL, FIELD_X, FIELD_O}; //  zbior wszystkich stanow, w jakich moze znajdowac sie pojedyncze pole

    //  metody
    Board();    //  konstruktor
    FieldType& getCurrentTurn();    //  zwraca referencje aktualnej tury
    bool checkField(int column, int row, FieldType type); //  sprawdza, czy pole o wspolrzednych [column]x[row] jest [type]
    void clearBoard();  //  ustawia wszystkie pola na NULL
    void clearWinningFields();  //  ustawia wszystkie pola, ktore daly wygrana na false
    bool setField(string coordinates);  //  konwertuje coordinates na odpowiednie liczby, a nastepnie ustawia pole na aktualnego gracza
    int convertLetter(char letter); //  konwertuje litere A, B lub C na odpowiednio inta 1, 2 lub 3
    bool checkIfWinningFieldExist();    //  zwraca true, jesli istnieja jakiekolwiek pola dajace wygrana (wazne przy remisie)

    //  getters
    array<array<FieldType, 3>, 3> &getAllFields();  //  zwraca referencje wszystkich pol na planszy
    array<array<bool, 3>, 3> &getWinningFields();   //  zwraca referencje wygrywajacyh pol na planszy
    int &getTurnCounter();  //  zwraca licznik tur (aktualna ture)
    bool &getIsPlayingAgain();  //  zwraca boola, ktory mowi o tym, czy gracz chce zagrac ponownie

private:
    //  zmienne
    int turnCounter = 1;    //  licznik tur
    bool isPlayingAgain = false;    //  przechowuje informacje o tym, czy gracz chce zagrac ponownie
    array<array<FieldType, 3>, 3> allFields;    //  przechowuje stan wszystkich pol na planszy
    array<array<bool, 3>, 3> winningFields = {{{false, false, false}, {false, false, false}, {false, false, false} }};  //  przechowuje pola, ktore daly wygrana
    FieldType currentTurn = FieldType::FIELD_X;  //  przechowuje aktualna ture (informacje, ktory gracz wykonuje ruch)
};


#endif //L2Z1_BOARD_H
