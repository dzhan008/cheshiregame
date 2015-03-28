#ifndef DUNGEON_H
#define DUNGEON_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Entity.h"

using namespace std;

class Dungeon
{
	//data fields
private:
	vector<Entity> entity_group;
	string dungeon_name;
	string dungeon_difficulty;
	vector<Item> dungeon_loot; //loot specific for that dungeon

public:
	Dungeon(const string &text_file, const string &dun_loot); //constructor for first dungeon
	void change_dungeon(const string &text_file, const string &dun_loot); //changes dungeon
	const void display_dungeon(); //displays monsters in dungeon
	int size(); //returns number of monsters in dungeon
	const Entity rand_monster(); //returns a random entity in the dungeon

	//helper functions
private:
	void fill_dungeon(const string &text_file); //helper func for constructor
	const Item rand_loot(); //returns a random loot from the vector to add to speicifc entity
};

#endif