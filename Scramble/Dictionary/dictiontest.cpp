//chad lape
//dictiontest.cpp
//testing parts of dictionary.h

#include <string>
#include <iostream>
#include "dictionary.h"
using namespace std;

void pause();

int main()
{
  Dictionary d;
  d.setword();
  for (int i = 25; i < 256; i++)
  {
    cout << d.getword(i) << endl;
  }
  pause();
  cout << d.getword() << endl;
  pause();
  d.setlimitray("d");
  pause();
  for(int i = 0; d.inlimit(i); i++)
  {
    cout << d.getlimitstring(i) << endl;
  }
  pause();
  return 0;
}

void pause()
{
  cout << "press enter to coninue: ";
  cin.ignore(256, '\n');
}
