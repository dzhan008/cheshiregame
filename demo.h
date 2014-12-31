#ifndef DEMO_H
#define DEMO_H
#include<vector>
#include<string>

using namespace std;

class demo
{
    public:
    void statprogression(); //Adds stats to players when they level up
    void inputStats(int& remainingStats); //Input prompts for stats
    void addPoints(int& points, int rstat); //Add points to specific stat

};

#endif
