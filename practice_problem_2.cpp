// This is a Card game simulator
// Four players play this game. In the beginning, each player holds 13 random cards each.
// In every turn they select one Card.
// If the 2 of the chosen cards are the same, the pair is disCard. The remaining cards goes back to the deck.
// If the 3 of the chosen cards are the same, a random pair is disCard. The remaining cards goes back to the deck.
// If all the chosen cards are the same, all are disCard.
// Game ends when one of the player has no cards.
// Player with fewest cards wins the game.

#include<iostream>
#include<list>
#include<random>
#include <algorithm>

using namespace std;

struct Card {
    int num;
    int shape;

    Card(int n, int s) {
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

void startGame(list<Card>& p1,list<Card>& p2,list<Card>& p3,list<Card>& p4) {
    vector<Card> cards;
    for(int i = 1; i <= 13; i++) {
        for(int j = 1; j <= 4; j++) {
            cards.push_back(Card(i, j));
        }
    }

    // shuffle cards
    random_device rd;
    mt19937 gen(rd());
    shuffle(cards.begin(), cards.end(), gen);

    // distribute to players
    for(int i = 0; i < 52; i += 4) {
        p1.push_back(cards[i]);
        p2.push_back(cards[i+1]);
        p3.push_back(cards[i+2]);
        p4.push_back(cards[i+3]);
    }    
}

list<Card>::iterator drawRandomly(list<Card> p) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, p.size());
    int index = distr(gen);

    auto temp = p.begin();
    advance(temp, index);
    return temp;
}

void printDeck(list<Card> p) {
    for(auto it = p.begin(); it != p.end(); it++) {
        it->printCard();
    }
}

int main() {
    list<Card> player1, player2, player3, player4;

    startGame(player1, player2, player3, player4);
    printDeck(player1);

    auto temp = drawRandomly(player1);
    temp->printCard();

    // temp = player1.erase(temp);

    cout << endl << endl << endl <<endl;
    
}