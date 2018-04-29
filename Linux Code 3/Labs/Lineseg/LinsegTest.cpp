//LinsegTest.cpp
//Made by Chad Lape
//4/25/18
//To test point and line seg class

#include "point.h"
#include "lineseg.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Point first;
  first.setx(8);
  first.sety(22);
  Point second(1,3);
  cout << "First point " << first.tostring();
  cout << "\nSecond point " << second.tostring();
  
  LineSeg line(first, second);
  cout << line.tostring();
  char blank;
  cout << "Press enter to leave";
  cin >> blank;

  return 0;
}
