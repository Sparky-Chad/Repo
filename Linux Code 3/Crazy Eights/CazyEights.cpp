//Chad Lape
//Crazy Eights
//Make a game of crazy Eights
//4/4/2018

//#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct card { //Basic structure for
	int num;
	int suit;
	string name;
	bool inHand;
};
struct held {
	struct card inD[52];  //Cards that are in this struct
	int dCount = 0;     //Counts where the cards are
};
struct p {
	struct held hand;
	string name;
};
struct center {
	int nP;
	int T = 0;
	int Turn = 1;
	int oT = 1;
	int score = 0;
	card topCard;
	card possible[52];
};

//    Globalvariables
struct held deck;     //Holds the values of the main deck in the program
struct held discard;  //Structure of discard pile
struct p player[5]; //Hold values of each player
struct card blank = { -1, -1, " ", false };
struct center ruling;

//    Function Prototypes
void makeDeck();  // Called to create a deck
void shuffle();   // Used to shuffle the created deck
string index(card &in);
void changeT();
int findS();
void print();
void makeGame();
card deal(struct held &dD, int where);
void rule(card in); //Used to find which cards someone would actually be able to play
string highscore(int who);

int main() {
	/* Debug Explanation

	currently what debug will do
	will output a single hand of cards allowing for debug of primary fold

	*/
	bool debug = false;  //For use of debug only should be false if not running Debug

	if (debug) {
		char en = 'y';
		do {                                  //Debug Run
			makeDeck();
			for (int i = 0; i < 52; i++) {
				deck.inD[i].name = index(deck.inD[i]);	//Card Faces
														//cout << deck.inD[i].name << endl;
			}
			for (int i = 0; i < 52; i++) {
				cout << deck.inD[i].name << endl;
			}
			shuffle();
			makeGame();
			for (int i = 0; i < 52; i++) {
				cout << deck.inD[i].name << endl;
			}
			for (int i = 0; i < ruling.nP; i++) {   //Print their hands
				cout << player[i].name << "'s hand:\n";
				int j = 0;
				while (player[i].hand.inD[j].suit != -1) {

					cout << player[i].hand.inD[j].name << endl; //debug print hand test
					j++;
				}
			}
			cout << "enter y to cont: ";
			cin >> en;
		} while (en == 'y' || en == 'Y');
		return 0;
	}//debug end

	 //Initialize variables and constants
	bool gOn = true;
	string winner;
	char fin = 'n';
	bool end = false;
	int w;

	do {
		/*
		Initialization of Program,
		Will create the objects for the players, create the deck and then begin the game

		*/
		makeDeck();
		shuffle();
		shuffle();
		makeGame();


		/*
		Main running

		*/

		//start each turn
		do {
			print();
			ruling.Turn++;
			for (int i = 0; i < ruling.nP; i++) {	//checks each player for win
				if (player[i].hand.dCount <= 0) {
					gOn = false;
					winner = player[i].name;
					w = i;
				}
			}
			if (deck.dCount <= 4) {										//refill deck
				while (discard.inD[1].suit != -1) {
					deck.inD[deck.dCount] = deal(discard, 0);
					deck.dCount++;
				}
			}


			/*if (ruling.topCard.num == 1) {
				int choice;
				system("clear");
				cout << "Changing suit\n" <<
					"-0 for spades\n" <<
					"-1 for hearts\n" <<
					"-2 for heart\n" <<
					"-3 for diamonds\n" <<
					"Choose: ";
				cin >> choice;
				ruling.topCard.suit = choice;
			}*/




		} while (gOn);
		ruling.score = findS();
		cout << winner << " Wins with score of " << ruling.score<<"\n\n";
		cout << highscore(w) << endl;
		cout << "press y and enter to play again: ";
		cin >> fin;
		if (fin == 'y' || fin == 'Y') end = true;
	} while (end);

	return 0;
}


//Main Funcctions

void makeGame() {
	int start;    //Used for the starting hand size
	do {
		cout << "How many players(max 5): ";
		cin >> ruling.nP;
	} while (ruling.nP <= 1 || ruling.nP > 5);
	cout << "Crazy Eights Creator\nMade by Chad Lape\n\n";	//make players and such
	for (int i = 0; i < ruling.nP; i++) {
		cout << "Player " << i << " name: ";
		cin >> player[i].name;
	}
	//choose num


	cout << "Num cards in starting hand(3, 5, 7): ";
	cin >> start;
	/*
	Reservere for making AI Player
	*/
	for (int i = 0; i < 52; i++) {
		deck.inD[i].name = index(deck.inD[i]);	//Card Faces
		//cout << deck.inD[i].name << endl;
	}
	for (int i = 0; i < start; i++) {
		shuffle();
	}
	deck.dCount = 52;
	for (int i = 0; i < ruling.nP; i++) {
		for (int j = 0; j < 52; j++) {
			player[i].hand.inD[j] = blank;
			ruling.possible[j] = blank;
		}
		player[i].hand.dCount = 0;
	}
	for (int j = 0; j < ruling.nP; j++) {
		for (int i = 0; i < start; i++) {											//make player hands

			player[j].hand.inD[i] = deal(deck, 0);
			deck.dCount--;
		}

		player[j].hand.dCount = start;
	}
	ruling.topCard = deal(deck, 0);
	deck.dCount--;

}

void print() {
	int choice;
	bool correct = false;
	do {
		string curS;
		switch (ruling.topCard.suit) {
		case 0: curS = "♠"; break;
		case 1: curS = "♣"; break;
		case 2: curS = "♥"; break;
		case 3: curS = "♦"; break;
		}
		/*switch (ruling.topCard.suit) {
		case 0: curS = "0"; break;
		case 1: curS = "1"; break;
		case 2: curS = "2"; break;
		case 3: curS = "3"; break;
	}*/
		system("clear");
		//system("clear");
		cout << "Current Match        Turn: " << ruling.Turn << endl << endl;	//turn time
		for (int i = 0; i < ruling.nP; i++) {
			if (ruling.T != i) cout << player[i].name << " has " << player[i].hand.dCount << " cards in their hand\n";
		}																					//player hand amounts
		cout << "\nThe Deck has " << deck.dCount << "\nDiscard has " << discard.dCount << "\n\n";	//deck and dis
		cout << "top card is-\n" << ruling.topCard.name << "\n";
		//cout << "the current suit is " << curS << "\n\n";
		cout << "Your (" << player[ruling.T].name << ") Deck-\n";

		int lastchoice = 0;
		for (int i = 0; i < 52 && (player[ruling.T].hand.inD[i].suit != -1); i++) {	//Display Deck
			cout <<  i << "-\n" << player[ruling.T].hand.inD[i].name << endl;
			lastchoice = i;
		}
		lastchoice++;
		cout << lastchoice << "- Draw";

		cout << "\n8 = wild, J = Skip, Q = draw 1, King = draw 2\n";

		rule(ruling.topCard);
		cout << "\n\n Your Choice: ";
		cin >> choice;

		if (choice >= 0 && choice < lastchoice) {		//whaty happens
			for (int i = 0; i < 52; i++) {
				if (ruling.possible[i].suit == player[ruling.T].hand.inD[choice].suit && ruling.possible[i].num == player[ruling.T].hand.inD[choice].num) {
					correct = true;																						//if card works
					discard.inD[discard.dCount] = ruling.topCard;
					discard.dCount++;
					ruling.topCard = deal(player[ruling.T].hand, choice);
					player[ruling.T].hand.dCount--;

					if (ruling.topCard.num == 13) {															//Special
						for (int i = 0; i < 2; i++) {
							player[ruling.oT].hand.inD[player[ruling.oT].hand.dCount] = deal(deck, 0);
							deck.dCount--;
							player[ruling.oT].hand.dCount++;
							changeT();
							changeT();
						}
					}
					else if (ruling.topCard.num == 12) {
						player[ruling.oT].hand.inD[player[ruling.oT].hand.dCount] = deal(deck, 0);
						deck.dCount--;
						player[ruling.oT].hand.dCount++;
						changeT();
						changeT();
					}
					else if (ruling.topCard.num == 11) {
						changeT();
						changeT();
					}
					else {											//normal
						changeT();
					}
					break;
				}
			}
		}
		else if (choice == lastchoice) {													//deal
			correct = true;
			player[ruling.T].hand.inD[player[ruling.T].hand.dCount] = deal(deck, 0);
			player[ruling.T].hand.dCount++;
			deck.dCount--;
			changeT();
			break;
		}
		else {
			cout << "Choose a correct one next time please, not " << choice;
			system("pause");
		}


		cout <<"end\n";
	}while (!correct);

}//end print

string highscore(int who) {
	stringstream ss;
	string str;
	string out = "";
	int high;
	ifstream ifile ("highscore.txt");
	if(ifile) {	//open highscore file

		getline(ifile, str);
		out = str;
		getline(ifile, str);
		stringstream ss(str);
		ss >> high;

		//cout << out << high << endl;
		if(high < ruling.score) {
			cout << high << "you have the highscore!";
				out = player[who].name;
				high = ruling.score;
		}
		ifile.close();
	}
	else cout << "IFILE FAIL";
ofstream ofile ("highscore.txt");
		if (ofile) {

			if(ofile.is_open()){
				ofile << out << "\n";
				ofile << high << "\n";
			}
			ofile.close();
		}
	ss << "HIGHSCORE: " << out << " with score of " << high;
	str = ss.str();
	return str;
}


void rule(card in) {
	int run = 0;		//keeps track of which card in rules it is on
	for (int i = 0; i < 52; i++) {
		ruling.possible[i] = blank;
	}
	//enter in for suit
	for (int i = 1; i <= 13; i++) {
		ruling.possible[run] = { i, ruling.topCard.suit, "", false };
		run++;
	}
	//now for number
	for (int i = 0; i < 4; i++) {
		ruling.possible[run] = { ruling.topCard.num, i, "", false };
		run++;
	}
	//now for special cards
	for (int i = 0; i < 4; i++) {
		ruling.possible[run] = {8, i, "", false };
		run++;
	}
}	//rule


//    Utilities functions

int findS() {
	int out = 0;
	for (int i = 0; i < ruling.nP; i++) {
		int j = 0;
		while (player[i].hand.inD[j].suit != -1) {
			out += player[i].hand.inD[j].suit;
			j++;
		}
	}
	return out;
}

void changeT() {
	ruling.T++;
	if (ruling.T >= ruling.nP) ruling.T = 0;
	ruling.oT = ruling.T + 1;
	if (ruling.oT >= ruling.nP) ruling.oT = 0;
}

card deal(struct held &dD, int where) {
	held in = dD;
	card away;
	away = in.inD[where];
	for (int i = where; i < 51 && (dD.inD[i].suit != -1); i++) {
		dD.inD[i] = dD.inD[i + 1];
		where++;
	}
	dD.inD[where] = blank;
	return away;
}


void makeDeck() {
	int s = 0, n = 1;
	for (int i = 0; i < 52; i++) {    //makes the deck
		deck.inD[i].num = n;
		deck.inD[i].suit = s;
		n++;
		if (n == 14) {
			n = 1;
			s++;
		}
	}
}//end make deck

void shuffle() {
	int randomnum = rand() % 6 + 1;
	for (int j = 0; j < randomnum; j++) {
		for (int i = 0; i < 52; i++) {   //For each card of the deck
			int r = int(rand() % 52);    //Shuffles deck only
			card temp = deck.inD[i];
			card *o = &deck.inD[i];       //swaps at source
			card *n = &deck.inD[r];
			*o = *n;
			*n = temp;
		}
	}
}                               //End Shuffle

string index(card &in) {    //makes string version of each card
	string tempn;
	string temps;
	stringstream ss;
	switch (in.num) {
	case 1: tempn = "A"; break;
	case 11: tempn = "J"; break;
	case 12: tempn = "Q"; break;
	case 13: tempn = "K"; break;      //Letter
	default:
		ss << in.num;
		tempn = ss.str();
		ss.str(string());
	}
	switch (in.suit) {
	case 0: temps = "♠"; break;
	case 1: temps = "♣"; break;
	case 2: temps = "♥"; break;
	case 3: temps = "♦"; break;
	/*case 0: temps = "0"; break;
	case 1: temps = "1"; break;
	case 2: temps = "2"; break;
	case 3: temps = "3"; break;*/
	default:
		ss << in.suit;
		temps = ss.str();
		ss.str(string());
	}

	ss << "-------\n" <<
		"|" << setw(5) << left << tempn << "|\n" <<
		"|" << setw(7) << right << "|\n" <<
		"|" << "  " << temps << setw(4) << "|\n" <<
		"|" << setw(7) << "|\n" <<
		"|" << setw(5) << tempn << "|\n" <<
		"-------";
	temps = ss.str();
	return temps;
}
