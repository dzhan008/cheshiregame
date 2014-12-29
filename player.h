#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>

using namespace std;

class player
{
    public:
    int maxhp; //The maximum health points of the player.
    int currhp; //The current health the player has at the moment.
    int pmoney; //The amount of money the player has.
    string playername; //The player's name.
    vector<int> currstats; //Current stats for the player.
    void getInfo(); //Grabs information?
    void updateInfo();
    
};

#endif