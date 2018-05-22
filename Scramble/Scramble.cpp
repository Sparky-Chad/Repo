//Chad Lape
//main for the scramble project

#include "scramble.h"
#include "./Player/player.h"
#include "./Dictionary/dictionary.h"
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
  game.end();

  return 0;
}
