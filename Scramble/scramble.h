//Chad Lape
//scramble.h
//will allow for the use of scrambling words from dictionary class
//Depends on the Dictionary Folder

#ifndef _SCRAMBLE_H
#define _SCRAMBLE_H

#include "./Dictionary/dictionary.h"
//#include "./General/Utillity.h"
#include "./Player/player.h"
#include <string>
#include <iostream>
#include <limits>
#include "./Player/topten.h"

using namespace std;
void pause();
void clear();
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
    int gettempscore();
    //returns the average score the user has, does not overide actual score
    void setppoint();
    //will set the point value using the algorithm

    //member functions
    void initialize();
    //Initializes the scramble game
    void main();
    //main running of the game
    bool insame();
    //checks if the inword characters matches some chars from the other
    void end();
private:
    Player p;
    Dictionary myd;
    string myscramword;
    string inword;
    string tempor;
    int temppoint;
    //changes per round
    int myroundnum;
    //counts each round
    int total;
    //stores the total score, not used for actual score
    int points;
    //stores the point value
};

//Constructors
Scramble::Scramble()    //---------------------------default constructor
{
    myd.setpath("./Dictionary/Dictionary.txt");
    myd.setword();
    myscramword = "";
    inword = "";
    resettemppoint();
    myroundnum = 1;
    total = 0;
}

//Private Data Manipulation

void Scramble::setPath(string path)  //------------------sets a different path var
{
    myd.setpath(path);
}

void Scramble::setscram()   //---------------------------sets scramble word to a random word
{
    tempor = myd.getword();
    myscramword = tempor;            //gets a random word
    int length = myscramword.length() - 1;
    RandGen r;
    for(int i = 0; i < length; i++)   //runs through each letter
    {
        int rand = r.RandInt(myscramword.length());
        char a = myscramword[i];
        myscramword[i] = myscramword[rand];
        myscramword[rand] = a;

    }
    //cout <<  tempor << " " << myscramword << endl << endl;
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
int Scramble::gettempscore()    //----------------------------------gettempscore
{
    resettemppoint();
    temppoint = p.getpoint() / myroundnum;
    return temppoint;
}

//member functions **********************************************************
bool Scramble::insame()   //----------------------------------------insame
{
    resettemppoint();
    //cout << "same length?**\n";
    if(inword.length() <= myscramword.length())
    {
        int inlength = inword.length();
        
        int mylength = myscramword.length();

        int innercountchar = 0;
        pause();
        int j = 0;
        for(int i = 0; i < inlength; j++)    //outer inword loop
        {
            if(inword[i] == myscramword[j]) 
            {
                innercountchar++;
                addtemppoint();
            }
            if(j >= mylength) 
            {
                j = 0;
                i++;
            }
            
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

void Scramble::setppoint()   //----------------------------set point
{
    total += temppoint;
    int temp = total / myroundnum;
    p.setpoint(temp);
    resettemppoint();
}
void Scramble::initialize() //----------------------------Initialize
{
    //cout << "initialize\n";
    inword = "";
    string name;
    int total = 40;
    setscram();
    total = total / myscramword.length();
    p.setdefaultpoint(total);
    cout << "Welcome to Scramble Word game by Chad Lape\n" << 
            "The goal is to find how ever many words you can make given a scrambled word" <<
            "\nDouble Points for finding the original word\n\n";
    cout << "Player name: ";
    getline(cin, name);
    p.setplayername(name);
    cout << "\nHello " << p.getplayername() << ", your scrambled word is " << myscramword << endl;
    cout << "For every letter of that scram word you use you get " << p.getdefaultpoint() << " points\n";
    cout << "You get as many rounds as you want until you end it\nYour score will be the average of each round";
    cout << "\n\nGood Luck!!!";

    //Util::pause();
}
void Scramble::main()   //*******************************MAIN
{
    myroundnum = 1;
    bool end = false;
    bool canend;
    //Util::clear();
    string temp = p.getplayername();    //display info
    p.resetpoints();

    
    while(!end) //run until all inword chars match some of scramble
    {
        cout << "Scramble word "
             << "          " << endl;
        cout << "Your Scrambled Word is: " << myscramword << endl
             << "Each letter the same is worth " << p.getdefaultpoint() << " points\n"  
             << "What you earn is averaged with the rounds it takes to earn those points\n";

        canend = false;
        cin.clear();
        cout << "Chose a word: ";       
        cin >> inword;
        cout << "\n\n";
        //cout << "before if**\n";


        if(insame())    //If any of the characters are the same
        {
            //cout << "after if **\n";
            int charsa = temppoint / p.getdefaultpoint();   //display stakes
            //cout << "Your word " << inword << " and scrambled word " << myscramword << endl;
            //cout << "You matched " << charsa << " characters with the scrambled word\n" << 
            //        "You will recieve " << temppoint << " points if you match a word\n";

            myd.setlimitray(inword);
            bool in = true;
            int i = 0;
            while(myd.inlimit(i) && !canend)
            {
                string mydword = myd.getlimitstring(i);
                //cout << i << " for loop " << mydword <<  "\n";
                in = myd.inlimit(i);
                if(inword == mydword) //if any of the words in the temp string match you get the points
                {
                    canend = true;
                    total += temppoint;
                    p.resetpoints();
                    if (inword == tempor);
                    points = total / myroundnum;
                    p.setpoint(total / myroundnum);
                    cout << "Correct!\nYou earned " << temppoint << " points at " << myroundnum << " rounds\n";
                    resettemppoint();
                    myroundnum++;
                    //pause();
                }//end if
                i++;
            }
            if(!canend)    //this displays out the user missed the word
            {
                cout << "\nThe word was not found in the dictionary";
                pause();
            }
            resettemppoint();   //just good data management
        }//end the if chars are same
        else 
        {
            cout << "\nA character must match the scrambled word";
            pause();  //make sure the user sees the above
        }


        
        //END OF MAIN AREA TO CHOSE FOR RUNNING AGAIN

        cin.clear();
        cout << "Your current score is now " << points << endl;
        char there;
        pause();
        cout << "End Game?(y/n)  ";
        cin >> there;
        if(there == 'y' || there == 'Y') end = true;
        
        clear();
        //Util::clear();
    }//end while doesn't end
}

void Scramble::end()
{
    Top t;
    t.settop();
    clear();
    cout << "Your end score is: " << p.getpoint() << endl;
    cout << '\n' << t.tostring();

    int en = t.restock(p);

    if(en = -1) cout << "You did not make the top ten\n";
    else cout << "You made " << en << " on the score board\n";

    t.filereplace();

    cout << "That's all folks";
    pause();

}




//general
void clear()
{
    for (int i = 0; i < 1000; i++)
    {
        std::cout << "\n";
    }
}
void pause()
{
    std::cout << "\n\nPress Enter to Continue: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif