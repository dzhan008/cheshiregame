#ifndef VALUES_H
#define VALUES_H
#include<vector>
#include<string>

using namespace std;

class values
{
    public:
    int hp; //Health Value
    int lvl; //Level
    string name; //Name of player
    vector<int> playerstats;
    void statprogression(); //Adds stats to players when they level up
    
};

#endif