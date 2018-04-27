//Chad Lape
//Check Book
//Adapt to use struct array

//#include "stdafx.h"
#include <iostream>	//cin cout
#include <iomanip>	//For any formating
#include <string>	//Because strings
#include <sstream>	//String Stream for ints and such

using namespace std;
enum accType { Check = 0, Sav = 1, demo = 2, supersave = 3};
struct SAC {	//Declares variables that when used in combonation with Type give correct account actions
	double fee[4] = {10, 0, 5, 0};		//Current check = 0, savings = 1
	double min[4] = { 0, 150, 0, 400};
	double interest[4] = { 0, .004 , 0, .03};
	double checkF[4] = {.50, 0, 0, 1};
};
struct account {			//Structure for every account that is made
	double start = 0;			//For finding the starting balance
	double track[4][50];	//[1][y] Deposits [0][y] Withdrawls [2][y] Charges [3] Wired payments
	int index[4] = { 0, 0, 0, 0 };	//Index for each of the different value calls
	double totD = 0;	//Total of Deposits
	double totC = 0;	//Total of Checks
	double totS = 0;	//Total of Insuficient Funds
	double totI = 0;	//Total of interest
	double totW = 0;	//Total of Wired Transactions
	double totF = 0;
	string line; //Temp data storage of strings
	string accName;
	accType Type;
	SAC wAcc;
};

void start(account &user);
short getIn(account &user);
double total(double ar[][50], int j);
string endings(account user);
string line(int w);

double roundDollar(double in);

int main()
{
	//Initialize
	account U[100]; short doAgain = 1; int doo = 1; int ind = 0;
	do {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 100; j++) {
				U[ind].track[i][j] = 0;
			}
		}
		U[ind].Type = Check;
		start(U[ind]);		//
		while (doAgain == 1) {
			doAgain = getIn(U[ind]);
		}
		string line = endings(U[ind]);
		cout << line;
		cout << "Add another account's transactions?\n";
		char in;
		cin >> in;
		if (in == 'n' || in == 'N') {
			doo = 0;
		}
		else {
			ind++;
		}
		system("CLS");
	} while (doo == 1);
	doAgain = 1;
	do {					//Reshow each of the accounts made previously
		for (int i = 0; i <= ind; i++) {
			cout << i << ".) " << U[i].accName << endl;
		}
		cout << "-1.) exit\n";
		cout << "Chose something there to print account or whatever: ";
		cin >> doo;
		if (doo == -1) break;
		cout << endings(U[doo]);
	} while (doAgain == 1);
    return 0;
}


void start(account &user) {		//First call			START THE PROGRAM CHOSE ACCOUNT
	char in;
		cout << "Welcome to the online banking calculator and register\n" <<
			"C - Checking: ODP, monthly fees, no interest, $0.50 per check fee, no wired fees\n" <<
			"S - Saving: ODP, min balance of $150, no check fee, .5% interest, no wired fees\n" <<			//Used for later to calculate ending balance
			"D - A wonderful account purely for Mr Kummers own use\n" <<
			"U - SuperSavings: "
			"Chose account: ";
		cin >> in;
		cin.ignore();
		if(in == 'c' || in == 'C') user.Type = Check;
		if(in == 's' || in == 'S') user.Type = Sav;
		if(in == 'd' || in == 'D') user.Type = demo;
		if(in == 'u' || in == 'U') user.Type = supersave;
		cout << "Name Your account: ";
		getline(cin, user.accName);
		cout << "Enter Starting Balance + min balance of $" << user.wAcc.min[user.Type] << ":";
		cin >> user.start;									//Gets starting balance and ends

}


short getIn(account &user) {			//Gets inputs and info
	double tm; char in;
	user.totC = total(user.track, 0);		//Gets the running totals of all
	user.totD = total(user.track, 1) + user.start;
	cout << "Enter transaction type(C, D, W, E): ";
	cin >> in;
	if (in == 'e' || in == 'E') return 0;	// to end
	cout << "Enter your transaction amount: $";
	cin >> tm;
	tm = roundDollar(tm);
	if (in == 'C' || in == 'c') {			//Checks				USER INPUT
		if (tm <= ((user.totD + user.start) - user.totC)) {
			user.track[0][user.index[0]] = tm;
			user.index[0]++;
			user.totF += user.wAcc.checkF[user.Type];
		}
		else if(tm > ((user.totD + user.start)-user.totC)){
			user.track[2][user.index[2]] = 10;	//If they over filled the balance
			user.index[2]++;
		}
	}
	else if (in == 'D' || in == 'd') {		//Deposits
		user.track[1][user.index[1]] = tm;
		user.index[1]++;
	}
	else if (in == 'W' || in == 'w') {
		user.track[3][user.index[3]] = tm;
		user.index[3]++;
	}
	return 1;
}


string endings(account user) {		//Creates a string to be outputted immidiatley after
	string str; int w = 20; int numW = 10;
	accType stand = Sav;
	user.wAcc.fee[user.Type] = 5;
	user.totC = total(user.track, 0);
	user.totD = total(user.track, 1);
	user.totS = total(user.track, 2);
	user.totW = total(user.track, 3);
	double end = (user.start + user.totD) - (user.totC + user.wAcc.fee[user.Type]);

	stringstream sup;
	sup << setiosflags(ios::fixed | ios::showpoint) << setprecision(2);
	sup << "Account: " << user.accName;
	sup << line(w + numW) << setw(w) << left << 	//The fun end block of code
		"Transactions TOtal:" << setw(numW) << right << "Amnt" << setw(numW) << "TrNum" << setw(numW) << "Balance" << endl <<
		setw(w) << left <<
		"Starting Balance" << right << setfill('.') << user.start << endl;
	end = user.start + user.totD;
	sup << setw(w) << left <<
		"Deposits" << setw(numW) << right << user.totD << setw(numW) << user.index[1] << end << endl;
	end -= user.totC;
	sup << setw(w) << left <<
		"Checks" << setw(numW) << right << user.totC << setw(numW) << user.index[0] << setw(numW) << end << endl;
		end -= user.totW;
	sup << setw(w) << left <<
		"Wired Withdrawl" << setw(numW) << right << user.totW << setw(numW) << user.index[3] << setw(numW) << end << endl;
	end -= user.totS;
	sup << setw(w) << left <<
		"Insufficient Funds" << setw(numW) << right << user.totS << setw(numW) << user.index[2] << setw(numW) << end << endl ;

	if (user.Type == stand || user.Type == 3) {			//Checking for if it is a savings account
		user.totI = end * user.wAcc.interest[user.Type];
		end += user.totI;
		sup << setw(w) << left <<
			"Interest earned"  << setw(numW) << right << user.totI << setw(numW) << '.' << setw(numW) << end << endl;
	}
	else if (user.Type != stand) {
		end -= user.wAcc.fee[user.Type];
		sup << setw(w) << left <<
			"Service Charge" << right << setw(numW) << user.wAcc.fee[user.Type]<< setw(numW) << "1" << setw(numW) << end << endl;
	}

	sup << setw(w) << left <<
		"Ending Balance" << right << setw(numW) << right << endl;

	str = sup.str();		//Create String
	return str;
}


string line(int w) {
	stringstream str;
	str << setw(w) << setfill('=') << "=\n" << setfill(' ');
	return str.str();
}


double roundDollar(double in) {
	in = int(in * 100 + .5);
	in /= 100;									//Rounds the dollar amount and accounts
	return in;									//accounts for rounding up
}


double total(double ar[][50], int j) {
	double re = 0;
	for (int i = 0; i < 50; i++) {
		re += ar[j][i];
	}
	return re;
}
