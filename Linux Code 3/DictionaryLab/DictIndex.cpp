//Dictionary Index
//Made by Chad Lape
//Will input the Dic.txt and take the largest word and a random word
//begun 4/23/18

#include <fstream>  //file reading
#include <iostream> //to input and output from user
#include <string> //the string you need
#include <sstream> //for string sstream
#include "randgen.h"//for randgen classes
#include "stdlib.h" //standard calls and such

//for use of std
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

int main() {
  //initialization of variables
  int w = 60000;
  index words[w];  //initializes many word variables
  RandGen ran;
  int which;
  char end = 'y';

  ifstream ifile("Dic.txt");  //opens Dic


    if(ifile) { //read the file make sure to have befrore the for loop
      for(int i = 0; i < w; i++) { //runs through each of the words objects to get the word value
      string str;
      getline(ifile, str);
        //debug
        //cout << i << endl;
        words[i].getWord(str);    //gets the value for each of the word strings
          }//end For

      ifile.close();
    } //end ifile if statement

    else cout << "FILE FAIL"; //if FAIL


  do {
    which = 0;
    int choice;
    cout << "Welcome to Dictionary\nMade By Chad\n";
    cout << "1 - find longest word\n";
    cout << "2 - random word\n" <<
            "3 - word certain num\n" <<
            "4 - Exit";
    cout << "\n\nYour choice: ";
    cin >> choice;
    system("clear");
    cout << "\n";
    switch(choice) {
      case 1:
        which = 0;
        for(int i = 1; i < w; i++) {
          if (words[which].length() < words[i].length()) {
            which = i;
          }
        }
        cout << "The largest word is " << words[which].toString() << endl;
        break;
        case 2:
          which = ran.RandInt(w - 1);
          cout << "Your random word at " << which << " is: " << words[which].toString() << endl;
        break;
        case 3:
          cout << "choose a word length: ";
          cin >> which;
          for(int i = 0; i < w; i++) {
            int length = words[i].length() - 1;
            if(which == length) {
              cout << words[i].toString() << endl;
            }
          }
        break;
        case 4:
          end = 'n';
        break;
    }
    cout << "\n\n";

  }while (end == 'y' || end == 'Y');


  return 0;
}
