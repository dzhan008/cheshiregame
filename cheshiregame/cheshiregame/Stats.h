#ifndef STATS_H
#define STATS_H

#include "stdafx.h"
#include<vector>
#include<string>
#include "player.h"

using namespace std;

class stats
{
	private:
	/*
	Looking at each cell in order:
		0 = Strength
		1 = Agility
		2 = Vitality
		3 = Dexterity
		4 = Luck
	*/
	vector<int> curr_stats; // 5 Stats

    public:

	stats();

    void statProgression(player* p); //Adds stats to players when they level up
    void inputStats(int& remainingStats); //Input prompts for stats
    void addPoints(int& points, int rstat); //Add points to specific stat

};

#endif
