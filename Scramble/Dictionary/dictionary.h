//dictionary.h
//made by chad Lape
//creates word objects from the Dic.txt and allows for their functionality easily


#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <string>     //for the help of strings in this class
#include <fstream>    //inputs from file, ifstream
#include "randgen.h"  //for random get word

using namespace std;
class Dictionary
{
public:
  Dictionary();            //default constructor and will use default path to file Dic.txt
  Dictionary(string path); //fill constructor with an inputed path to file

  //private data manip functions
  void setword();
  //sets word array with the inputed file from path
  string getword(int i);
  //gets one of words chosen from inputed i
  string getword();
  //will get a random word
  void setpath(string in);
  //sets the path variable
  string getpath();
  //gets the path variable
  void setlimitray(string);
  //sets a limited array with the passed strings first character
  string getlimitstring(int);
  //returns a string from inside the limits of the array, uses less resources as smaller portion to look through

  //member functions
  //bool equalletters(int, string);
  //will check to see if an inputed string is the same as the one being checked
  bool equal(int, string);
  //Will check whether two strings, one inputed are the same or not
  bool inlimit(int);
  //checks if your number is in the limit of the limited array
private:
  int w = 58112;
  //length constant for string array
  string *myword = new string[58112];
  //Utilized for the loading of saved words to memory and their use in the program
  string blank = "";
  //blank string
  string mypath;
  //path to file variable
  int point;
  //number points to beginning of section of the array
  int limit = 0;
  //limit as to how far you are allowed to move in the section
};
//Constructors*************************************************
Dictionary::Dictionary()
{
  mypath = "Dictionary.txt"; //the default path to call from
  //setword();      //a default call from normall path
}
Dictionary::Dictionary(string path)
{
  mypath = path;  //changed path variable created
  setword();      //sets the dictionary as with this path
}

//Private Data Manip******************************************
void Dictionary::setword() //-------------------------------------------------setword
{
  //cout << mypath << endl;
  ifstream ifile(mypath, ios::in); //opens the file
  string temp = "";       //temp string for use passing the string array

  for(int i = 0; i < w; i++)  //runs through whole array
  {
    myword[i] = blank;
  }//end for

  if(ifile.is_open())
  {
    int i = 0;
    while(getline(ifile, temp)) //repeats until reaching the end of the file
    {
      myword[i] = temp;
      //puts temp into my word
      i++;
    }//end when file opens

    ifile.close();
  }//end if file opened
  else
  {
    //cout << "**File Fail**";
  }
}//end set word
string Dictionary::getword(int i) //---------------------------------------------getword
{
  //cout << "returning word " << myword[i] << endl;
  return myword[i];
}
string Dictionary::getword()     //---------------------------------------------getword - random
{
  RandGen r;
  int randman = r.RandInt(w);
  //cout << "returning random word " << myword[randman] << endl;
  return myword[randman];
}
void Dictionary::setpath(string in)  //-----------------------------------------setpath
{
  mypath = in;
}
string Dictionary::getpath()   //------------------------------------------------getpath
{
  return mypath;
}
void Dictionary::setlimitray(string in) //-------------------------------------------setlimitray(string)
{
  int i = 0;  //constant index int
  limit = 0;
  while(in[0] != myword[i][0])
  {
    //cout << "no " << myword[i] << endl;
    i++;

  }
  point = i;
  while(in[0] == myword[i][0])
  {
    //cout << "yes " << myword[i] << endl;
    limit++;
    i++;
  }
  //cout.flush();
}//end set limitray
string Dictionary::getlimitstring(int i) //------------------------------------------getlimitstring
{
  //cout << "returning limitstring " << *(point + 1) << endl;
  return myword[point + i];
}
bool Dictionary::equal(int i, string in) //-------------------------------------------equal`
{
  if(myword[i] == in) return true;
  else return false;
}
bool Dictionary::inlimit(int i)  //---------------------------------------------------inlimit
{
  return (i < limit);
}
#endif
