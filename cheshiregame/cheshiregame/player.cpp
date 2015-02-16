#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*Get Functions*/

player::player(){
    playername = "Player";
    maxHP = 1;
    currHP = 1;
    plevel = 1;
    pexp = 0;
	statpoints = 0;
	playerstats.resize(5);
}
player::player(string pName, int health, int lvl, int amount, int statpts)
{
    playername = pName;
    maxHP = health;
    currHP = health;
    plevel  = lvl;
    pexp = amount;
	statpoints = statpts;
	playerstats.resize(5);
}

int player::getMaxHP()
{
    return maxHP;
}
int player::getHP()
{
    return currHP;
}

int player::getlevel()
{
    return plevel;
}

int player::getmoney()
{
    return pmoney;
}

int player::getexp()
{
    return pexp;
}

string player::getname()
{
    return playername;
}

/*Set Functions*/
void player::setHP(int health)
{
    currHP = health;
}

void player::setlevel(int& level)
{
    plevel = level;
}

void player::setmoney(int& money)
{
    pmoney = money;
}

void player::setexp(int expx)
{
    pexp = expx;
}

void player::setstats(vector<int>& stats)
{
    playerstats.at(0) += stats.at(0);
    playerstats.at(1) += stats.at(1);
    playerstats.at(2) += stats.at(2);
    playerstats.at(3) += stats.at(3);
    playerstats.at(4) += stats.at(4);
}

/*Misc*/

void player::displayInfo()
{
    cout << playername << endl;
    cout << "Health: " << currHP << "/" << maxHP << endl;
    cout << "Stats" << endl;
    cout << "Strength:  " << playerstats.at(0) << endl;
    cout << "Agility:   " << playerstats.at(1) << endl;
    cout << "Vitality:  " << playerstats.at(2) << endl;
    cout << "Dexterity: " << playerstats.at(3) << endl;
    cout << "Luck:      " << playerstats.at(4) << endl;
}
