#include <iostream>
#include "stdafx.h"
#include <vector>
#include <string>
#include "player.h"
#include "demo.h"

using namespace std;

player p;
vector<int> stats(5); //5 Stats

//Note to self: Put this in another class

void demo::statProgression() //Adding stats
{
    int remainingStats = 0; //Figure out how to add more points here. Maybe make a parameter?

    //For the demo only
    cout << "Welcome to the stat simulator!" << endl;
    cout << "As you level up in this game, you will gain points to put into your character's stats." << endl;
    cout << "Each type of stat will influence your character in different ways." << endl;
    cout << "Before we start, please set the number of stat points for the simulation." << endl;
    cin >> remainingStats;

    while(remainingStats > 0)
    {
        cout << "Strength:  " << stats.at(0) << endl;
        cout << "Agility:   " << stats.at(1) << endl;
        cout << "Vitality:  " << stats.at(2) << endl;
        cout << "Dexterity: " << stats.at(3) << endl;
        cout << "Luck:      " << stats.at(4) << endl;
        cout << "You have " << remainingStats << " stat points remaining." << endl;
        cout << "Which stat would you like to add to?" << endl;

        inputStats(remainingStats);
    }

    p.setstats(stats);

    cout << "Here are your final stats:" << endl;
    cout << "Strength:  " << stats.at(0) << endl;
    cout << "Agility:   " << stats.at(1) << endl;
    cout << "Vitality:  " << stats.at(2) << endl;
    cout << "Dexterity: " << stats.at(3) << endl;
    cout << "Luck:      " << stats.at(4) << endl;
}

void demo::inputStats(int& remainingStats)
{
    int points = 0;
    string stat;

    cin >> stat;

    if (stat == "Str" || stat == "Strength" || stat == "str" || stat == "strength") //Add points to appropriate stat
    {
        addPoints(points, remainingStats);
        stats.at(0) += points;
    }
    else if (stat == "Agi" || stat == "Agility" || stat == "agi" || stat == "agility")
    {
        addPoints(points, remainingStats);
        stats.at(1) += points;
    }
    else if (stat == "Vit" || stat == "Vitality" || stat == "vit" || stat == "vitality")
    {
        addPoints(points, remainingStats);;
        stats.at(2) += points;
    }
    else if (stat == "Dex" || stat == "Dexterity" || stat == "dex" || stat == "dexterity")
    {
        addPoints(points, remainingStats);
        stats.at(3) += points;
    }
    else if (stat == "Luk" || stat == "Luck" || stat == "luk" || stat == "luck")
    {
        addPoints(points, remainingStats);
        stats.at(4) += points;
    }
    else
    {
        cout << "Invalid stat type." << endl;
        inputStats(remainingStats);
    }
    remainingStats -= points;
}

void demo::addPoints(int& points, int rstat)
{
    cout << "How many points?" << endl;
    cin >> points;
    if(points > rstat)
    {
        cout << "You do not have enough points to do this." << endl;
        addPoints(points, rstat);
    }
    else if(points < 0)
    {
        cout << "You can't add in negative points, silly." << endl;
        addPoints(points,rstat);
    }
}

/*void demo::expgain()
{
    cout << "You gained 100 exp points!" << endl; //Implement to combat systems later
    if(pexp > maxexp)
    {
        cout << "Level Up!" << endl;
        -set exp to 0
        -change maxexp
        -level up player
        -add stat points to player (5)?
    }

}*/

/*
Looking at each cell in order:
0 = Strength
1 = Agility
2 = Vitality
3 = Dexterity
4 = Luck
*/
