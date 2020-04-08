//
// Name: Emery Morales Osorio
// Date: 02/03/20
//

#include "game.h"
using namespace std;

int main() {
    ifstream inFile;
    string filename, name1, name2;
    int balance1, balance2;
    Deck deck;

    cout << "Please enter the file name you'd like to open: ";
    cin >>  filename; // getting the file name

    inFile.open(filename); // opening the file for you
    while (!inFile.is_open()){
        //cout << "no file, exiting\n";
        //exit(1);
        cout << "Error, Please enter a valid file name: ";
        cin >>  filename; // getting the file name
        inFile.open(filename); // opening the file for you
        if(inFile.is_open()){
            break;
        }
    }

    inFile >> name1;
    inFile >> balance1;
    inFile >> name2;
    inFile >> balance2;

    cout << "Name1 and balance 1: " << name1 << " " << balance1 << endl;
    cout << "Name2 and balance 2: " << name2 << " " << balance2 << endl;

    while(!inFile.eof()) // while the current line you're on is not the end of the file
    {
        string temp;
        inFile >> temp;
        Card currCard(temp[0], temp[1]);
        deck.addToBottom(currCard);
    }

    Game play_game = Game(name1, name2, balance1, balance2, deck);
    play_game.playRound();


}
