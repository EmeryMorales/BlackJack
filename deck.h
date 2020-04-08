//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#include "card.h"
#ifndef DECK_H
#define DECK_H
#include <vector>

class Deck : public Card {
public:
    //Constructor
    Deck();

    //Declare functions
    Card dealFromTop();
    void addToBottom(const Card & card); //Pass by Reference
    int size() const;
    bool isEmpty() const;
    string toString() const;
    int getTotalHandValue() const;

private:
    vector<Card> cards;
};

#endif //DECK_H
