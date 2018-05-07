#include "compnum.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{

  Compnum temp;
  //Temp for outputing other Compnums
  double inR, inI;
  //for inputs
  cout << "First Complex number: ";
  cin >> inR >> inI;
  Compnum first(inR, inI);
  //First Compnum block
  cout << "Second: ";
  cin >> inR >> inI;
  Compnum second(inR, inI);
  //Second Compnum block
  int end = 0;
  do
  {
  cout << "\n\nFirst Compnum: " << first.tostring() << endl;
  cout << "Second Compnum: " << second.tostring() << endl;
  temp = first.add(second);
  cout << "\nThe two added: " << temp.tostring() << endl;
  temp = first.multiply(second);
  cout << "Multiplied: " << temp.tostring() << endl;
  temp = first.subtract(second);
  cout << "subtracted: " << temp.tostring() << endl;
  temp = second.conjugate();
  cout << "conjugate of second: " << temp.tostring() << endl;
  temp = first.divide(second);
  cout << "divide: " << temp.tostring() << endl;

  string in;
  cin.ignore();
  if(end == 0)
  {
    cout << "input a complex in string: ";
    getline(cin, in);
    Compnum some(in);
    cout << "that is: " << some.tostring() << " will run again, this is first\n\n";
    first = some;
  }
  end++;
} while(end != 2);
return 0;
}
