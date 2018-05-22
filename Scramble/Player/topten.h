//Chad Lape
//Store top ten players
//always have

#ifndef _TOPTEN_H
#define _TOPTEN_H

#include "player.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Top
{
public:
    Top(); 
    //default constructor

    void setpath(string in);
    string getpath();
    //path gets and such

    void settop();
    Player gettop(int);


    //members
    int restock(Player);
    //compares each player to see if any work, returns the place they are in, replaces in file too
    void filereplace();
    //outputs each player there
    string tostring();
    //returns every player
private:
    string path;
    Player p[10];
};
Top::Top()
{
    path = "./Player/top10.txt";
}

void Top::setpath(string in)
{
    path = in;
}
string Top::getpath()
{
    return path;
}

void Top::settop()
{
    Player blank;
    ifstream ifile(path);
    if(ifile.is_open())
    {
        int i = 0;
        while(ifile.eof() && i < 10)
        {
            p[i] = blank;
            string tempname, temppoint;
            int nospoint;
            getline(ifile, tempname);
            getline(ifile, temppoint);
            nospoint = atoi(temppoint.c_str());
            Player temp(tempname, nospoint);
            p[i] = temp;
            i++;
        }
        ifile.close();
    }
}

Player Top::gettop(int in)
{
    return p[in];
}

int Top::restock(Player in)
{
    int out;
    for(int i = 9; i >= 0; i--)
    {
        if(in.getpoint() > p[i].getpoint())
        {
            p[i] = in;
            return(10 - i);
        }
    }
    return -1;
}

void Top::filereplace()
{
    ofstream ofile(path);
    if(ofile.is_open())
    {
        for(int i = 0; p[i].getpoint() != 0; i++)
        {
            ofile << p[i].getplayername() << '\n';
            ofile << p[i].getpoint() << '\n';
        }
        ofile.close();
    }
}
string Top::tostring()
{
    ostringstream ss;
    string str;
    ss << "Top 10 Players:\n\n";

    for(int i = 0; i < 10; i++)
    {
        int real = i+1;
        ss <<  real << ". " << p[i].getplayername() << " at " << p[i].getpoint() << " points\n"; 
    }
    str = ss.str();
    return str;
}



#endif