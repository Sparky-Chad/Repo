//player class
//stores player names, scores, and the top ten
//player.h
//chad lape


#include <string>
#include <sstream>

using namespace std;

class Player
{
public:
    Player();
    //default constructor
    Player(string, int);
    //fill constructor with name

    //private data manip
    void setplayername(string);
    //sets the player name
    string getplayername();
    //gets player name
    void setmyhighscore();
    //sets highscore to default path
    void setmyhighscore(string);
    //sets a highscore filepath
    string gethighscore();
    //returns top 15 high scores
    string gethighscorepath();
    //returns highscore path var
    void setpoint(int in);
    //sets the point value
    void addpoint(int in);
    //adds that many points
    int getpoint();
    //returns the current point value
    void setdefaultpoint(int);
    //sets the default amount of points added
    int getdefaultpoint();
    //gets the default point add

    //method functions
    void addpoint();
    //default add amount of points
    void resetpoints();
    //sets points back to zero
    string topscores(int i)
    {

    }
private:
    string myplayername;
    string myhighscorefile;
    int mypoints;
    
    //private settings
    int defaultpointadd = 1;
    //the default amount of points to add
};  //end player class

Player::Player()
{
    myplayername = "";
    mypoints = 0;
    setmyhighscore();
}
Player::Player(string name, int in)
{
    setmyhighscore();
    setplayername(name);
    mypoints = in;
}

//private data manip****************************
void Player::setplayername(string in) //---------------------set player name
{
    myplayername = in;
}
string Player::getplayername()  //----------------------------get player name string
{
    return myplayername;
}
void Player::setmyhighscore()   //----------------------------setmyhighscore default
{
    setmyhighscore("highscore.txt");
}
void Player::setmyhighscore(string in)  //--------------------set player name path
{
    myhighscorefile = in;
    if(myhighscorefile.substr(myhighscorefile.length()-4, 4) != ".txt") myhighscorefile += ".txt";
}
void Player::setpoint(int in)   //----------------------------set point
{
    mypoints = in;
}
void Player::addpoint(int in)   //----------------------------add point
{
    mypoints += in;
}
int Player::getpoint()  //--------------------------------------get point
{
    return mypoints;
}
void Player::setdefaultpoint(int in)    //--------------------set default point var
{
    defaultpointadd = in;
}
int Player::getdefaultpoint()  //-----------------------------get default point var
{
    return defaultpointadd;
}

//method functions
void Player::addpoint() //------------------------------------add default points
{
    addpoint(defaultpointadd);
}
void Player::resetpoints()  //--------------------------------reset point
{
    setpoint(0);
}