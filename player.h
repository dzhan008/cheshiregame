#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>

using namespace std;

class player
{
    public:
    int maxhp;
    int currhp;
    string playername; //Player's name
    vector<int> currstats; //Current stats for the player.
    void getInfo();
    void updateInfo();
    
};

#endif