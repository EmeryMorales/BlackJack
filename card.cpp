//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#include "card.h"

Card::Card(char rank, char suit){
    this->card_rank = rank;
    this->card_suit = suit;
}

Card::Card(){}

string Card::toString(){
    string card_entire;
    card_entire += card_rank;
    card_entire += card_suit;
    return card_entire;
}

int Card::getValue() {
    char temp[] = {'0', '0', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 10; i++) {
        if (card_rank == temp[i]) {
            return i;
        }
    }
    if (card_rank == 'A') {
        return 11;
    }
    else {
        return 10;
    }

}