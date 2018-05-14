//dictionary.h
//made by chad Lape
//creates word objects from the Dic.txt and allows for their functionality easily


#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <string>
#include <fstream>
#include <sstream>
#include "word.h"
#include "randgen.h"

class dic
{
public:
  dic(); //default constructor and will

  string setword();
  string getword(int i);
  string ranget();
private:
  word myword[60000];
  word temp[1000];
};


#endif
