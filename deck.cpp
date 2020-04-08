//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#include "deck.h"

Deck::Deck(){}

Card Deck::dealFromTop(){
    Card card = cards.at(0);
    cards.erase(cards.begin());
    return card;
}

void Deck::addToBottom(const Card & card){
    cards.push_back(card);
}

int Deck::size() const{
    return cards.size();
}

bool Deck::isEmpty() const{
    if (cards.size() == 0){
        return true;
    }
    else {
        return false;
    }
}

string Deck::toString() const{
    string temp;
    if (isEmpty()) {
        temp = "[]";
    }
    else {
        for (Card card : cards) {
            temp += "[" + card.toString() + "]";
        }
    }
    return temp;
}

int Deck::getTotalHandValue()const{
    int total = 0;
    for (Card card : cards) {
        if (card.getValue() == 11) {
            if (total > 10) {
                total += 1;
            }
            else {
                total += 11;
            }
        }
        else {
            total += card.getValue();
        }
    }
    return total;
}