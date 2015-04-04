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

public:
	Dungeon(const string &text_file); //constructor for first dungeon
	void change_dungeon(const string &text_file); //changes dungeon
	const void display_dungeon(); //displays monsters in dungeon
	int size(); //returns number of monsters in dungeon
	Entity* rand_monster(); //returns a random entity in the dungeon

	//helper functions
private:
	void fill_dungeon(const string &text_file); //helper func for constructor
};

#endif