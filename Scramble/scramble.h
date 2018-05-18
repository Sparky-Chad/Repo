//Chad Lape
//scramble.h
//will allow for the use of scrambling words from dictionary class
//Depends on the Dictionary Folder


#include "./Dictionary/dictionary.h"
#include "./General/utillity.h"
#include "./Player/player.h"
#include <string>
#include <iostream>
#include <iomanip>


using namespace std;

class Scramble
{
public:
    Scramble();
    //default constructor sets all empty and a default path

    //sets and gets
    void setPath(string path); 
    //sets the path variable
    string getdictionaryinfo();
    //should display some needed info of dictionary for later use
    void setscram();
    //will set the scramble word to a random dictionary word and scramble
    void setinword(string in);
    //set the inputed word that will be checked with the rest of the word for its point value
    void addtemppoint();
    //will add the player default point to temp point
    void addtemppoint(int in);
    //add to temp point
    void resettemppoint();
    //resetstemp point
    int gettemppoint();
    //returns the temp point

    //member functions
    void initialize();
    //Initializes the scramble game
    bool main();
    //main running of the game
    bool insame();
    //checks if the inword characters matches some chars from the other
private:
    Player p;
    Dictionary myd;
    string myscramword;
    string inword;
    int temppoint;
};

//Constructors
Scramble::Scramble()    //---------------------------default constructor
{
    myscramword = "";
    inword = "";
    resettemppoint();
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
void Scramble::addtemppoint()       //------------------------------addtemppoint default
{
    addtemppoint(p.getdefaultpoint());
}
void Scramble::addtemppoint(int in) //------------------------------addtemppoint
{
    temppoint += in;
}
void Scramble::resettemppoint() //----------------------------------resettemppoint
{
    temppoint = 0;
}
int Scramble::gettemppoint()    //----------------------------------gettemppoint
{
    return temppoint;
}

//member functions
bool Scramble::insame()   //----------------------------------------insame
{
    if(inword <= myscramword)
    {
        int innercountchar = 0;

        for(int i = 0; i < inword.length(); i++)    //outer inword loop
        {
            for(int j = 0; j < myscramword.length(); i++)
            {
                if(inword[i] == myscramword[j]) 
                {
                    innercountchar++;
                    addtemppoint();
                }
            }//myscramword loop
        }//end inword for loop
        if(innercountchar == 0) {
                resettemppoint();
                return false;
        }
        return true;
    }
    else
    {
        resettemppoint();
        return false;
    }
}
void Scramble::initialize() //----------------------------Initialize
{
    inword = "";
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
    string temp = p.getplayername();    //display info
    cout << "Scramble word" << setw(30) << right << temp;
    cout << "Your Scrambled Word is: " << myscramword << endl <<
            "Each letter the same is worth " << p.getdefaultpoint() << " points\n";
    
    bool end = false;
    while(!end) //run until all inword chars match some of scramble
    {
        cout << "Chose a word: ";
        getline(cin, inword);
        cout << "\n\n";
        end = insame();
    }
}