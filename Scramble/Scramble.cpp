//Chad Lape
//main for the scramble project

#include "scramble.h"
#include <iostream>

using namespace std;
int main()
{
  cout.clear();
  fflush(stdout);
  Scramble game;
  game.initialize();
  int end = 1;
  game.main();

  return 0;
}
