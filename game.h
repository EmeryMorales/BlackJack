//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#include "deck.h"
#ifndef GAME_H
#define GAME_H

class Game : public Deck {
public:
    Game(string name1, string name2, int money1, int money2, Deck main);
    void setDeck(int player, const Deck & deck);
    void playRound();

private:
    Deck p1, p2, dealer, game_main;
    string game_name1, game_name2;
    int game_money1, game_money2, game_moneyD;

};

#endif //BLACKJACK_GAME_H
