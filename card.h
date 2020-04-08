//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Card {
public:
    //Two character arguments corresponding to the rank and the suit with which to initialize the card
    Card(char rank, char suit);
    Card();
    //Declare functions
    string toString();
    int getValue();

private:
    char card_rank, card_suit;
};

#endif //CARD_H
