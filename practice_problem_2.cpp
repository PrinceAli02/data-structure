// This is a card game simulator
// Four players play this game. In the beginning, each player holds 13 random cards each.
// In every turn they select one card.
// If the 2 of the chosen cards are the same, the pair is discard. The remaining cards goes back to the deck.
// If the 3 of the chosen cards are the same, a random pair is discard. The remaining cards goes back to the deck.
// If all the chosen cards are the same, all are discard.
// Game ends when one of the player has no cards.
// Player with fewest cards wins the game.

#include<iostream>
#include<list>
#include<random>
#include <algorithm>

using namespace std;

struct card {
    int num;
    int shape;

    card(int n, int s) {
        num = n;
        shape = s;        
    }

    void printCard() {
        switch(num) {
            case 1:
                cout << "Ace";
                break;
            case 11:
                cout << "Jack";
                break;
            case 12:
                cout << "Queen";
                break;
            case 13:
                cout << "King";
                break;
            default:
                cout << num;
                break;
        }
        cout << " of ";
        switch(shape) {
            case 1:
                cout << "Spades";
                break;
            case 2:
                cout << "Clovers";
                break;
            case 3:
                cout << "Diamonds";
                break;
            case 4:
                cout << "Hearts";
                break;
        }
        cout << endl;
    }
};

void StartGame(list<card>& p1,list<card>& p2,list<card>& p3,list<card>& p4) {
    vector<card> cards;
    for(int i = 1; i <= 13; i++) {
        for(int j = 1; j <= 4; j++) {
            cards.push_back(card(i, j));
        }
    }

    // randomize cards

    // distribute to players

    //delete this later
    for(auto x : cards) x.printCard();
    
}

int main() {
    list<card> player1, player2, player3, player4;

    StartGame(player1, player2, player3, player4);
}