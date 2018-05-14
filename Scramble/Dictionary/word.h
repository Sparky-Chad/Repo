//Made by Chad Lape
//word.h
//Will all user to input from Dic.txt in various forms
//5/13/18

//Needs Dic.txt and randgen.h

/*
  this is a general utility class for the rest of the dictionary programs
  this class allows for easy array creation and for the ability to sort through the
  dictionary words easily in the classes

  *constructors
    word() - will create an empty string, allow for it to be used later
    word(string in) - will create a word with the inputed string

  *functions
    setword(string in)  - will set my word to the inputed string
    getword()           - returns the word in string form

*/
#ifndef _WORD_H
#define _WORD_H

#include <string>

using namespace std;

class word { //class to define each word
public:
  word(); //default constructor
  word(string in);  //to set the word

  //member functions
  void setword(string in);
  int length();

  string getnodup();
  string getword();
private:
  string myword;  //private data stored
};
word::word() {
  myword = "";
}
word::word(string in) {
  myword = in;
}
int word::length() {
  return myword.length();
}

string word::getnodup() //will output the word with no duplicates and in alphabetical order
{
  string out = "";
  for(int i = 0; i < length(); i++) //run for each char of myword
  {
    bool ns = true;       //saves if there is a letter the same
    int o = out.length(); //gets out . length and saves it
    string s = myword.substr(i, 1); //saves mywords letter

    for(int j = 0; j < o; i++)
    {
      if(out.substr(j, 1) == s) ns = false;
    }// end fill check
    if(ns) out += s;
  }//end myword copy


  return out;
}//end getnodup
string word::getword() {
  return myword;
}
void word::setword(string in) {
  myword = in;
}

#endif
