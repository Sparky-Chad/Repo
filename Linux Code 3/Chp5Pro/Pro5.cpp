//Made By: Chad Lape
//Project Name: Pro5.cpp
//Date Due: sometime this week
//Purpose: to sort many different bits of code and get the different
//things

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
//#include <sstring>

void dashLine(int w) { //Creates a dash line with a set width

	std::cout << std::setw(w) << std::setfill('-') << "-\n" << std::setfill(' ');

}
int front() {	//Front end control for the first part of the program

	dashLine(40);
	std::cout << "Welcome to the Project 5 Display\n" <<
		"Made by Chad Lape \n";
	dashLine(40);


	return 0;
}//end Front

int main() {

	//Will use main program as front end control of various functions
	system("clear");
	int index = front();

}//End Main Program
