//dictionary.h
//made by chad Lape
//creates word objects from the Dic.txt and allows for their functionality easily


#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <string>     //for the help of strings in this class
#include <fstream>    //inputs from file, ifstream
#include <iostream>   //monstly for debugging purposes
#include <cstring>    //functional check of equal in letters
#include <cstdio>     //for a few functions in cstring
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
  bool equalletters(int, string);
  //will check to see if an inputed string is the same as the one being checked
  bool equal(int, string);
  //Will check whether two strings, one inputed are the same or not
  bool inlimit(int);
  //checks if your number is in the limit of the limited array
private:
  int w = 60000;
  //length constant for string array
  string *myword = new string[w];
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
  mypath = "Dic.txt"; //the default path to call from
  setword();      //a default call from normall path
}
Dictionary::Dictionary(string path)
{
  mypath = path;  //changed path variable created
  setword();      //sets the dictionary as with this path
}

//Private Data Manip******************************************
void Dictionary::setword() //-------------------------------------------------setword
{
  ifstream ifile(mypath); //opens the file
  string temp = "";       //temp string for use passing the string array

  for(int i = 0; i < w; i++)  //runs through whole array
  {
    myword[i] = blank;
  }//end for

  if(ifile)
  {
    int i = 0;
    while(!ifile.eof()) //repeats until reaching the end of the file
    {
      getline(ifile, temp);
      myword[i] = temp;
      //puts temp into my word
      i++;
    }//end when file opens

    ifile.close();
  }//end if file opened
  else
  {
    cout << "**File Fail**";
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
  string fin = in.substr(0, 1);
  while(fin != myword[i].substr(0,1))
  {
    cout << "no " << myword[i] << endl;
    i++;

  }
  point = i;
  while(fin == myword[i].substr(0, 1))
  {
    cout << "yes " << myword[i] << endl;
    limit++;
    i++;
  }
  cout.flush();
}//end set limitray
string Dictionary::getlimitstring(int i) //------------------------------------------getlimitstring
{
  if(inlimit(i))
  {
    //cout << "returning limitstring " << *(point + 1) << endl;
    return myword[point + i];
  }
  else return "fail";
}
//member functions*******************************************************
bool Dictionary::equalletters(int i, string in) //---------------------------------------equalletters
{
  if(myword[i].length() == in.length()) //rechecks if lengths are equal
  {
    char cur[2][myword[i].length() + 1];      //initailizes a cstring
    strcpy(cur[0], myword[i].c_str()); //uses cstring to make char arrays to compare raw int values of the chars
    strcpy(cur[1], in.c_str());

    int hm[2] = {0, 0};
    int stlen = strlen(cur[0])-1;
    for(int i = 0; i < stlen; i++)
    {
      hm[0] += int(cur[0][i]);  //gets the int values of the characters
      hm[1] += int(cur[1][i]);
    }
    if(hm[0] == hm[1]) return true; //if the chars are the same the numbers sshould be equal
    else return false;
  }
  return false; //if nothing else just return false
} //end equal letters
bool Dictionary::equal(int i, string in) //-------------------------------------------equal`
{
  if(myword[i] == in) return true;
  else return false;
}
bool Dictionary::inlimit(int i)  //---------------------------------------------------inlimit
{
  if(i < limit) {
    return true;
  }
  else return false;
}
#endif
