//Chad Lape
//scramble.h
//will allow for the use of scrambling words from dictionary class
//Depends on the Dictionary Folder


#include "./Dictionary/dictionary.h"
#include "./General/utillity.h"
#include "./Player/player.h"
#include <string>
#include <iostream>


using namespace std;

class Scramble
{
public:
    Scramble();
    //default constructor sets all empty and a default path
    Scramble(string path);
    //constructor will automatically fill the path of dictionary

    //sets and gets
    void setPath(string path); 
    //sets the path variable
    string getdictionaryinfo();
    //should display some needed info of dictionary for later use
    void setscram();
    //will set the scramble word to a random dictionary word and scramble
    void setinword(string in);
    //set the inputed word that will be checked with the rest of the word for its point value

    //method functions
    void initialize();
    //Initializes the scramble game
    bool main();
    //main running of the game
private:
    Player p;
    Dictionary myd;
    string myscramword;
    string inword;
};

//Constructors
Scramble::Scramble()    //---------------------------default constructor
{
    myscramword = "";
    inword = "";
}
Scramble::Scramble(string path) //-------------------alternative path constructor
{
    myd.setpath(path);
    myd.setword();
    Scramble();
}

//Private Data Manipulation

void Scramble::setPath(string path)  //------------------sets a different path var
{
    myd.setpath(path);
}

void Scramble::setscram()   //---------------------------sets scramble word to a random word
{
    myscramword = myd.getword();            //gets a random word
    for(int i = 0; i < myscramword.length(); i++)   //runs through each letter
    {
        RandGen r;
        myscramword[i] = myscramword[r.RandInt(myscramword.length())];
        //debug
        //cout << "scram word = " << myscramword << endl;
    }
}

//member functions
void Scramble::initialize() //----------------------------Initialize
{
    string name;
    int total = 40;
    setscram();
    total = total / myscramword.length();
    p.setdefaultpoint(total);
    cout << "Welcome to Scramble Word game by Chad Lape\n" << 
            "The goal is to find how ever many words you can make given\na scrambled word" <<
            "\nDouble Points for finding the original word";
    cout << "Player name: ";
    getline(cin, name);
    p.setplayername(name);
    cout << "Hello " << p.getplayername << " you scramble is " << myscramword << endl;
    cout << "For every letter of that scram word you use you get " << p.getdefaultpoint() << "points";
    cout << "\n\nGood Luck!!!";
    Util::pause();
}
bool Scramble::main()   //*******************************MAIN
{
    Util::clear();
}