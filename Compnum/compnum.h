#ifndef _COMPNUM_H
#define _COMPNUM_H

#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

/*
	Complex number class
	add, divide, power, need 2 numbers

	****TODO******
	- add member fuctions to perform math operations with another one
*/
class Compnum
{
public:
	Compnum(); //Default constructor
	Compnum(double real, double imag); //Fill constructor
	Compnum(string compstr); //Fill constructor with string

	void setreal(double in);	//Will set the real number
	double getreal(); //Returns the real number

	void setimag(double in);	//Will set the imaginary number
	double getimag(); //return imaginary number

	void instring(string in); //will find what the comp num is from a string
	string tostring(); //return the compnum in string

	double mag();
	double angle();

	//Manipulation classes
	Compnum conjugate(); //returns the conjugate of this compnum
	Compnum divide(Compnum in);
	Compnum add(Compnum in);
	Compnum subtract(Compnum in);
	Compnum multiply(Compnum in);
	Compnum powers(int r);
	Compnum root(int r);

private:
	double realnum;
	double imagnum;

};
//*******These are constructor definitions
Compnum::Compnum()
{
	realnum = 0;
	imagnum = 0;
}
Compnum::Compnum(double real, double imag)
{
	realnum = real;
	imagnum = imag;
}
Compnum::Compnum(string compstr)
{
	instring(compstr);
}

//Private data manipulation, gets and sets
void Compnum::setreal(double in)
{
	realnum = in;
}
double Compnum::getreal()
{
	return realnum;
}
void Compnum::setimag(double in)
{
	imagnum = in;
}
double Compnum::getimag()
{
	return imagnum;
}
void Compnum::instring(string in)
{
	stringstream real;
	stringstream im;
	int i = 0;
	bool imag = false;
	bool eimag = false;
	int length = in.length();
	while(i + 1 < length)	//Will take string and get the string stream to put into a double
	{
		if (in.substr(i , 1) == "i") eimag = true;
		if (in.substr(i, 1) == " ")
		{
			imag = true;
			i++;
			if(in.substr(i, 1) == "-") im << "-";
			i++;
		}
		else
		{
			if(imag)
			{
				im << in.substr(i, 1);
			}
			else if(!eimag)
			{
				real << in.substr(i, 1);
			}
		}

		i++;
	}	//End the while loop

	im >> imagnum;
	real >> realnum;
}//end string to Compnum

double Compnum::mag()	//gets the magnitude of the complex number
{
	return sqrt(realnum * realnum) + (imagnum * imagnum);
}
double Compnum::angle()
{
	double arg = imagnum / realnum;
	return atan(arg);
}
//returning manipulated Compnums

Compnum Compnum::add(Compnum in)	//Adds two Compnums
{
	double tR = 0, iR = 0;
	tR = in.getreal() + realnum;
	iR = in.getimag() + imagnum;
	Compnum temp(tR, iR);
	return temp;
}//end add function

Compnum Compnum::subtract(Compnum in)	//subtracts the original with another
{
	double tR = realnum - in.getreal();
	double tI = imagnum - in.getimag();
	Compnum temp(tR, tI);
	return temp;
}
Compnum Compnum::multiply(Compnum in)	//will find everything after multiplying
{
	double nreal = (in.getreal() * realnum) - (in.getimag() * imagnum);
	double nimag = (in.getreal() * imagnum) + (in.getimag() * realnum);
	Compnum temp(nreal, nimag);

	return temp;
}
Compnum Compnum::conjugate()	//returns the conjugate to get for dividing
{
	double conImag = -imagnum;
	Compnum temp(realnum, conImag);
	return temp;
}
Compnum Compnum::divide(Compnum in)
//make denomenator and num variables then multiply each with conjugate of it
{
	Compnum numer;
	numer = multiply(in.conjugate());
	Compnum denom;
	denom = in.multiply(in.conjugate());
	double tR = numer.getreal() / denom.getreal();
	double tI = numer.getimag() / denom.getreal();
	Compnum temp(tR, tI);
	return temp;
}
Compnum Compnum::powers(int r) //will find the root of the complex number
{
	double length = pow(mag(), r);
	double argument = angle() * r;

	double real = cos(argument) * length;
	double imag = sin(argument) * length;
	Compnum temp(real, imag);
	return temp;
}
Compnum Compnum::root(int r) //will find the root of the complex number
{
	double length = pow(mag(), 1/r);
	double argument = angle() / r;

	double real = cos(argument) * length;
	double imag = sin(argument) * length;
	Compnum temp(real, imag);
	return temp;
}

//Outputs
string Compnum::tostring()
{
	stringstream ss;
	string str;
	double imag = imagnum;
	string mid = "+";
	if(imagnum < 0)
	{
		mid = "-";
		imag = -imagnum;
	}
	ss << setiosflags(ios::showpoint | ios::fixed) << setprecision(2);
	ss << realnum << " " << mid << " " << imag << "i";
	str = ss.str();
	return str;
}





#endif
