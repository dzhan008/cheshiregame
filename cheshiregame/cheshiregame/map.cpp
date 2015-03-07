#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Map.h"
#include "player.h"
#include <fstream>
using namespace std;
//constructs blank map of 10*10 zeros 
//aka open space
map::map()
{
	mapitems.resize(100);
	//creates 10 * 10 map
	//playerposition.resize(100);
	playerposition.first = 0; // row
	playerposition.second = 0;// column
	mapitems.at(0).at(0) = 2;
	//keeps track of player position
}
map::map(int, string& file)
{
	ifstream mapfile;
	mapfile.open(file.c_str());
	//change the open function later to be more versatile
	if (!mapfile.is_open())
	{
		std::cout << "Error mapfile not open. " << std::endl;
	}
	int blocks;
	vector<int> row;
	while (mapfile >> blocks)
	{
		row.push_back(blocks);
	}
	mapitems.push_back(row);
	//for (int i = 0; i < mapitems.at(0).size()-1)
}
void map::updateplayer()
{
	for (int i = 0; i < mapitems.size(); i++)
	{
		for (int j = 0; j < mapitems.size(); j++)
		{
			if (mapitems.at(i).at(j) == 2)
			{
				int x = i;
				int y = j;
				mapitems.at(playerposition.first).at(playerposition.second) = 2;
				mapitems.at(x).at(y) = 0;
			}
		}
		
	}
}
void map::moveLeft()
{
	//may go out of bounds
		if (wallcheck(playerposition.first, playerposition.second - 1) == false)
		{
			if (playerposition.second == 0)
			{
				return;
			}
			playerposition.second--;
			updateplayer();
		}
		return;
	
}
void map::moveRight()
{
	if (wallcheck(playerposition.first, playerposition.second + 1) == false)
	{
		if (playerposition.second == mapitems.at(0).size()-1)
		{
			return;
		}
		playerposition.second++;
		updateplayer();
	}
	return;
}
void map::moveUp()
{
	if (wallcheck(playerposition.first - 1, playerposition.second) == false)
	{
		if (playerposition.first == 0)
		{
			return;
		}
		playerposition.first--;
		updateplayer();
	}
	return;
}
void map::moveDown()
{
	if (wallcheck(playerposition.first+1, playerposition.second) == false)
	{
		if (playerposition.first == mapitems.at(mapitems.size()-1).size() -1)
		{
			return;
		}
		playerposition.first++;
		updateplayer();
	}
	return;
}

bool map::wallcheck(int i, int j)
{
	//mapitems.resize(100);
	//1 = walls
	//0= emptyspace
	//2= player position
	if (mapitems.at(i).at(j) == 1)
	{
		return true;
	}
	
	return false;
}
void map::display()
{
	for (int i = 0; i < mapitems.size(); i++)
	{
		for (int j = 0; j < mapitems.size(); j++)
		{
			cout << mapitems.at(i).at(j) << " ";
		}
		cout << endl;
	}
}