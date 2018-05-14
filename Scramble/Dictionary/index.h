//Made by Chad Lape
//index.h
//Will all user to input from Dic.txt in various forms
//5/13/18

//Needs Dic.txt and randgen.h

#ifndef _INDEX_H
#define _INDEX_H

#include <string>
#include "randgen.h"

using namespace std;

class index { //class to define each word
public:
  index(); //default constructor
  index(string in);  //to get the word

  //member functions
  void getWord(string in);
  int length();
  string toString();
private:
  string word;  //private data stored
};
index::index() {
  word = "";
}
index::index(string in) {
  word = in;
}
int index::length() {
  return word.length();
}
string index::toString() {
  return word;
}
void index::getWord(string in) {
  word = in;
}

#endif
