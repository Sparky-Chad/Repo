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

class dic
{
public:
  dic();            //default constructor and will use default path to file Dic.txt
  dic(string path); //fill constructor with an inputed path to file

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

  //member functions
  bool equal(int, string);
  //will check to see if an inputed string is the same as the one being checked
private:
  int w = 60000;
  //length constant for string array
  string *myword = new string[w];
  //Utilized for the loading of saved words to memory and their use in the program
  string blank = "";
  //blank string
  string mypath;
  //path to file variable
};
//Constructors*************************************************
dic::dic()
{
  mypath = "Dic.txt"; //the default path to call from
  setword();      //a default call from normall path
}
dic::dic(string path)
{
  mypath = path;  //changed path variable created
  setword();      //sets the dictionary as with this path
}

//Private Data Manip******************************************
void dic::setword() //-------------------------------------------------setword
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
    cout << "**File Fail**";
  }
}//end set word
string dic::getword(int i) //---------------------------------------------getword
{
  return myword[i];
}
string dic::getword()     //---------------------------------------------getword - random
{
  RandGen r;
  return myword[r.RandInt(w)];
}
void dic::setpath(string in)  //-----------------------------------------setpath
{
  mypath = in;
}
string dic::getpath()   //------------------------------------------------getpath
{
  return mypath;
}

//member functions*******************************************************
bool dic::equal(int i, string in) //---------------------------------------equal
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
      hm[0] += int(cur[0][i]);
      hm[1] += int(cur[1][i]);
    }
    if(hm[0] == hm[1]) return true;
    else return false;
  }
  return false; //if nothing else just return false
}
#endif
