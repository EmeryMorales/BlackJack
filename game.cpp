//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#include "game.h"

Game::Game(string name1, string name2, int money1, int money2, Deck main){
    this->game_name1 = name1;
    this->game_name2 = name2;
    this->game_money1 = money1;
    this->game_money2 = money2;
    this->game_moneyD = 0;
    this->game_main = main;
}

void Game::setDeck(int player, const Deck & deck){
    if (player == 0){
        dealer = deck;
    }
    else if (player == 1){
        p1 = deck;
    }
    else {
        p2 = deck;
    }
}

void Game::playRound() {
    int bet1 = 0;
    int bet2 = 0;
    string answer1 = "Y", answer2 = "Y", answer_dealer = "Y";
    bool busted_p1 = false, busted_p2 = false, busted_dealer = false;

    cout << "Time for everyone to place their bet!" << endl;
    cout << "-----------------------" << endl;
    cout << game_name1 + ", how much would you like to bet? ";
    cin >> bet1;
    cout << game_name2 + ", how much would you like to bet? ";
    cin >> bet2;

    cout << endl;

    cout << game_name1 + " bets $" << bet1;
    cout << endl;
    cout << game_name2 + " bets $" << bet2;
    cout << endl;

    cout << endl;

    cout << "The initial starting cards are:" << endl;
    cout << "--------------------------------" << endl;

    //First card dealt
    p1.addToBottom(game_main.dealFromTop());
    p2.addToBottom(game_main.dealFromTop());
    dealer.addToBottom(game_main.dealFromTop());


    cout << game_name1 + "'s current hand: [??]" + p1.toString() << endl;
    cout << game_name2 + "'s current hand: [??]" + p2.toString() << endl;
    cout << "Dealer's current hand: [??]" + dealer.toString() << endl << endl;

    //Second card dealt
    p1.addToBottom(game_main.dealFromTop());
    p2.addToBottom(game_main.dealFromTop());
    dealer.addToBottom(game_main.dealFromTop());

    while (answer1 == "Y" || answer2 == "Y" || answer_dealer == "Y") {
        //Player 1
        //Checks to make sure player chose to stay in previous round
        if (answer1 == "Y") {
            cout << game_name1 + "'s turn:" << endl;
            cout << "-------------------" << endl;
            cout << game_name1 << "'s current hand: [" + p1.toString() << "(" << p1.getTotalHandValue() << ")" << endl;
            cout << "Would you like to draw another card? (Y or N): ";
            cin >> answer1;
            if (answer1 == "Y") {
                p1.addToBottom(game_main.dealFromTop());
                cout << game_name1 << "'s current hand: [" + p1.toString() << "(" << p1.getTotalHandValue() << ")" << endl;
                if (p1.getTotalHandValue() > 21) {
                    busted_p1 = true;
                    cout << "You've busted!" << endl;
                    answer1 = "N";
                }
            }
            else {
                cout << game_name1 + " chooses to stay";
                cout << endl;
            }
        }
        cout << endl;

        //Player 2
        if (answer2 == "Y") {
            cout << game_name2 + "'s turn:" << endl;
            cout << "-------------------" << endl;
            cout << game_name2 << "'s current hand: [" + p2.toString() << "(" << p2.getTotalHandValue() << ")" << endl;
            cout << "Would you like to draw another card? (Y or N): ";
            cin >> answer2;
            if (answer2 == "Y") {
                p2.addToBottom(game_main.dealFromTop());
                cout << game_name2 << "'s current hand: [" + p2.toString() << "(" << p2.getTotalHandValue() << ")" << endl;
                if (p2.getTotalHandValue() > 21) {
                    busted_p2 = true;
                    cout << "You've busted!" << endl;
                    answer2 = "N";
                }
            }
            else {
                cout << game_name2 + " chooses to stay";
                cout << endl;
            }
        }

        cout << endl;

        //Dealer
        if (answer_dealer == "Y") {
            cout << "Dealer's turn:" << endl;
            cout << "-------------------" << endl;
            cout << "Dealer's current hand: [" + dealer.toString() << "(" << dealer.getTotalHandValue() << ")" << endl;
            if (dealer.getTotalHandValue() <= 16) {
                cout << "Dealer chooses to draw" << endl;
                dealer.addToBottom(game_main.dealFromTop());
                answer_dealer = "Y";
                cout << "Dealer's current hand: [" + dealer.toString() << "(" << dealer.getTotalHandValue() << ")" << endl;
                if (dealer.getTotalHandValue() >= 21) {
                    busted_dealer = true;
                    cout << "You've busted!" << endl;
                    answer_dealer = "N";
                }
            }
            else {
                cout << "Dealer chooses to stay";
                cout << endl;
                answer_dealer = "N";
            }
        }
        cout << endl;
    }

    //Determining winner
    cout << "Let's see how it turned out:" << endl;
    cout << "----------------------------" << endl;

    char win_1, win_2, win_dealer;
    if (busted_dealer) {
        if (busted_p1) {
            win_dealer = 'Y';
            win_2 = 'N';
        }
        else {
            win_1 = 'Y';
            win_dealer = 'N';
        }
        if (busted_p2) {
            win_dealer = 'Y';
            win_2 = 'N';
        }
        else {
            win_2 = 'Y';
            win_dealer = 'N';
        }
    }
    else {
        if (busted_p1) {
            win_dealer = 'Y';
            win_1 = 'N';
        }
        else {
            if (p1.getTotalHandValue() > dealer.getTotalHandValue()) {
                win_1 = 'Y';
                win_dealer = 'N';
            }
            else {
                win_dealer = 'Y';
                win_1 = 'N';
            }
        }
        if (busted_p2) {
            win_dealer = 'Y';
            win_2 = 'N';
        }
        else {
            if (p2.getTotalHandValue() > dealer.getTotalHandValue()) {
                win_2 = 'Y';
                win_dealer = 'N';
            }
            else {
                win_dealer = 'Y';
                win_2 = 'N';
            }
        }
    }

    if (win_1 == 'Y') {
        cout << game_name1 << " wins $" << bet1 << endl;
    }
    else if (win_1 == 'N'){
        cout << game_name1 << " loses $" << bet1 << endl;
    }
    if (win_2 == 'Y') {
        cout << game_name2 << " wins $" << bet2 << endl;
    }
    else if (win_2 == 'N'){
        cout << game_name2 << " loses $" << bet2 << endl;
    }

}