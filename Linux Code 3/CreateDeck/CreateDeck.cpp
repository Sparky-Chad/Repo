//Chad Lape
//Make two decks

//#include "stdafx.h"
#include <iostream> //cout
#include "stdio.h"
#include <string> //string
#include "stdlib.h" //rand
#include <sstream>
#include <iomanip>

using namespace std;


struct card {
  int num;
  int suit;
  string name;
  bool inHand;
};
struct center {
  int dN = 0;
  card hand[2][52]; //0 = dealer, 1 = player
};

void makeDeck(card *in);
void shuffle(card *in);
string index(card &in);


int main() {
  card deck[52];
  center idx;
  makeDeck(deck);
  shuffle(deck);
  for(int i = 0; i < 52; i++) {
    deck[i].name = index(deck[i]);
  }
  //Initialize and send out the fun deck for the hands
  int fIdx = 0;
  for(int i = 0; i < 7; i++) {
    deck[fIdx].inHand = true;
    idx.hand[0][i] = deck[fIdx];
    fIdx++;
    deck[fIdx].inHand = true;
    idx.hand[1][i] = deck[fIdx];
    fIdx++;
  }
  cout << "Dealer: ";
  for(int i = 0; i < 7; i++) {
    cout << idx.hand[0][i].name << ", ";
  }
  cout << endl;
  cout << "Player: ";
  for(int i = 0; i < 7; i++) {
    cout << idx.hand[1][i].name << ", ";
  }
  cout << endl;

return 0;
}

void makeDeck(card *in) {
  int s=0, n=0;
  for (int i = 0; i < 52; i++) {    //makes each deck
   (in+i)->num = n;
   (in+i)->suit = s;
   n++;
   if (n == 12) {
     n = 0;
     s++;
   }
  }
}//end make deck

void shuffle(card *in) {
  for(int i = 0; i < 52; i++) {   //For each card of the deck
    int r = int (rand() % 52);
    card temp = *(in+i);
    card *o = (in + i);       //swaps at source
    card *n = (in + r);
    *o = *(in + r);
    *n = temp;
  }
}
string index(card &in) {    //makes string version of each card
  string temp;
  stringstream ss;
  switch(in.num) {
    case 0: temp = "Ace"; break;
    case 10: temp = "Jack"; break;
    case 11: temp = "Queen"; break;
    case 12: temp = "King"; break;
    default:
      ss << in.num;
      temp = ss.str();
  }
  switch (in.suit) {
    case 0: temp += " of Spades"; break;
    case 1: temp += " of Clubs"; break;
    case 2: temp += " of Heart"; break;
    case 3: temp += " of Diamonds"; break;
  }
  return temp;
}
