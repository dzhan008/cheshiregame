#ifndef DUNGEON_H
#define DUNGEON_H

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

class Dungeon
{
	//data fields
private:
	vector<Entity*> entity_group;
	string dungeon_name;
	string dungeon_difficulty;
	vector<Item*> dungeon_loot; //stores all the loot that all entities have in this dungeon

public:
	Dungeon(const string &text_file); //constructor for first dungeon
	~Dungeon(); //destructor
	void change_dungeon(const string &text_file); //changes dungeon
	const void display_dungeon(); //displays monsters in dungeon
	int size(); //returns number of monsters in dungeon
	Entity* rand_monster(); //returns a random entity in the dungeon

	//helper functions
private:
	void fill_dungeon(const string &text_file); //helper func for constructor
	void clear_dun(); //clears the dungeon_loot vector when you change dungeons
};

#endif