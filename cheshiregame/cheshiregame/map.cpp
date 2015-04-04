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
	for (int i = 0; i < 10; ++i) {
		mapitems.push_back(vector<int>(10));
	}
	//creates 10 * 10 map
	playerposition.first = 0; // row
	playerposition.second = 0;// column
	goal.first = 9;
	goal.second = 9;
	mapitems.at(playerposition.first).at(playerposition.second) = 2;
	mapitems.at(goal.first).at(goal.second) = 3;
	goalmap = mapitems;
	
}
//constructs map based on premade txt file
map::map(int sz, string& file)
{
	ifstream mapfile;
	mapfile.open(file.c_str());
	//change the open function later to be more versatile
	if (!mapfile.is_open())
	{
		std::cout << "Error mapfile not open. " << std::endl;
	}
	int blocks;
	//blocks are the spaces that make up the map
	vector<int> row;
	//to push back a vector of vectors I cant push back one element but rather one vector.
	while (mapfile >> blocks)
	{
		//cout << "Pushing " << blocks << endl;
		row.push_back(blocks);
		if (row.size() == sz)
		{
			mapitems.push_back(row);
			row.resize(0);
		}
	}
	for (int i = 0; i < mapitems.size(); i++)
	{
		for (int j = 0; j < mapitems.size(); j++)
		{
			if (mapitems.at(i).at(j) == 3)
			{
				goal.first = i;
				goal.second = j;
				mapitems.at(goal.first).at(goal.second) = 3;
			}
			else if (mapitems.at(i).at(j) == 2)
			{
				playerposition.first = i;
				playerposition.second = j;
				//cout << "Player coordinates: " << playerposition.first << " " << playerposition.second << endl;
				mapitems.at(playerposition.first).at(playerposition.second) = 2;
				goalmap = mapitems;
				return;
			}
		}
	}
}
map::map(int size)
{
	for (int i = 0; i < size; ++i) {
		mapitems.push_back(vector<int>(size));
	}
	for (int i = 1; i < mapitems.size(); i++)
	{
		for (int j = 1; j < mapitems.at(i).size(); j++)
		{
			mapitems.at(i).at(j) = rand() % 2;
		}
	}
	playerposition.first = 0; 
	playerposition.second = 0;
	goal.first = rand() % 10;
	goal.second = rand()% 10;
	mapitems.at(playerposition.first).at(playerposition.second) = 2;
	mapitems.at(goal.first).at(goal.second) = 3;
	goalmap = mapitems;

}
//updates player position after moving
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
				//cout << "Player coordinates: " << playerposition.first << " " << playerposition.second << endl;
				
				mapitems.at(playerposition.first).at(playerposition.second) = 2;
				mapitems.at(x).at(y) = 0;
				return;
			}
		}
		
	}
}
void map::moveLeft()
{
	if (playerposition.second == 0)
	{
		return;
	}
	if (wallcheck(playerposition.first, playerposition.second - 1) == false)
	{
		playerposition.second--;
		updateplayer();
	}
	else
	{
		cout << "There is  a wall. " << endl;
		wallBreak();
	}
	return;
	
}
void map::moveRight()
{
	if (playerposition.second == mapitems.at(0).size() - 1)
	{
		return;
	}
	if (wallcheck(playerposition.first, playerposition.second + 1) == false)
	{
		//cout << "There is no wall. " << endl;
		//cout << "Player coordinates: " << playerposition.first << " " << playerposition.second << endl;
		//cout << "Edge: " << mapitems.at(0).size() - 1 << endl;
		playerposition.second++;
		updateplayer();

	}
	else
	{
		cout << "There is a wall. " << endl;
		wallBreak();
	}
	return;
}
void map::moveUp()
{
	if (playerposition.first == 0)
	{
		return;
	}
	if (wallcheck(playerposition.first - 1, playerposition.second) == false)
	{
		playerposition.first--;
		updateplayer();
	}
	else
	{
		cout << "There is a wall. " << endl;
		wallBreak();
	}
	return;
}
void map::moveDown()
{
	if (playerposition.first == mapitems.at(mapitems.size() - 1).size() - 1)
	{
		return;
	}
	if (wallcheck(playerposition.first+1, playerposition.second) == false)
	{
		//cout << "Moving down:" << endl;
		playerposition.first++;
		updateplayer();
	}
	else
	{
		cout << "There is a wall. " << endl;
		wallBreak();
	}
	
	return;
}

bool map::wallcheck(int i, int j)
{
	//1 = walls
	//0= emptyspace
	//2= player position
	//3= Goal
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
		for (int j = 0; j < mapitems.at(i).size(); j++)
		{
			cout << mapitems.at(i).at(j) << " ";
		}
		cout << endl;
	}
}
bool map::run(player*& p, Dungeon* d, Combat_System c)
{
	string input;
	while (true)
	{
		cout << endl;
		display();
		cout << "Enter direction (up down left right) q to quit " << endl;
		cin >> input; 
		if (input == "up")
		{
			moveUp();
			display();
		}
		else if (input == "down")
		{
			moveDown();
			display();
		}
		else if (input == "left")
		{
			moveLeft();
			display();
		}
		else if (input == "right")
		{
			moveRight();
			display();
		}
		else if (input == "q")
		{
			return false;
		}
		if ((playerposition.first == goal.first) && (playerposition.second == goal.second))
		{
			cout << "Map Cleared. " << endl;
			return true;
		}
		if ((rand() % 4 + 1) == 1)
		{
			c.runBattle(d->rand_monster());
		}
		if (p->getHP() <= 0)
		{
			return false;
		}
	}
	return false;
}
void map::wallBreak()
{
	//changes all spaces next to the player into 0
	//do not use next to the goal
	//only use on randomly generated maps when walls block off the goal
	string input;
	cout << "Would you like to destroy this wall?" << endl;
	cin >> input;
	if (input == "yes")
	{
		if (playerposition.second != 0)
		{
		
			mapitems.at(playerposition.first).at(playerposition.second-1) = 0;
		}
		if (playerposition.second != mapitems.at(0).size() - 1)
		{
			mapitems.at(playerposition.first).at(playerposition.second+1) = 0;
		}
		if (playerposition.first != 0)
		{
			mapitems.at(playerposition.first-1).at(playerposition.second) = 0;
		}
		if (playerposition.first != mapitems.at(mapitems.size() - 1).size() - 1)
		{
			mapitems.at(playerposition.first + 1).at(playerposition.second) = 0;
		}
	}
	else if (input == "no")
	{
		return;
	}
}
//recursive function
//currently incomplete
//may not be used at all idk
/*void map::runStage()
{
	if (run() == false)
	{
		return;
	}
	else if (run() == true)
	{
		runStage();
	}
}*/