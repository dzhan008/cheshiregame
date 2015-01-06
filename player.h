#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>

using namespace std;

class player
{
    public:

    /*Get Functions: Returns the respective value.*/
    int getHP();
    int getlevel();
    int getmoney();
    int getexp();

    string getname();

    /*Set Functions: Sets every value into a certain number.*/
    void setHP(int& health); //Changes currHP to the updated hp value after a certain instance.
    void setlevel(int&level);
    void setmoney(int& money);
    void setexp(int& exp);
    void setstats(vector<int>& stats);

    /*Misc*/
    void displayInfo();

    private:
    int maxHP; //The maximum health points of the player.
    int currHP; //The current health the player has at the moment.
    int plevel; //The player's current level.
    int pmoney; //The amount of money the player has.
    int pexp; //The amount of exp the player has.
    //int maxexp; //The maximum amount of exp the player has. May be put into another class.
    string playername; //The player's name.
    vector<int> playerstats; //Current stats for the player.


};

#endif
