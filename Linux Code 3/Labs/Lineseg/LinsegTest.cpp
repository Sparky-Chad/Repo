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
  second.tostring;
  first.tostring;
  
  LineSeg line(first, second);
  cout << slope << endl;

}
