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
    int money; //Currency
    string name; //Name of player
    vector<int> playerstats; //Stats
    void statprogression(); //Adds stats to players when they level up
    
};

#endif