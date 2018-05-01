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
  double tempx, tempy;
  Point first;

  cout << "First point x,y: ";
  cin >> tempx >> tempy;
  first.setx(tempx);
  first.sety(tempy);
  cout << "second point x,y: ";
  cin >> tempx >> tempy;
  Point second(tempx, tempy);
  cout << "First point " << first.tostring();
  cout << "\nSecond point " << second.tostring() << endl;

  LineSeg line(first, second);
  cout << line.tostring();

  return 0;
}
