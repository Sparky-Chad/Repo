//Chad Lape
//main for the scramble project

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "scramble.h"

int main()
{
  Scramble game;
  game.initialize();
  int end = 1;
  game.main();

  return 0;
}
