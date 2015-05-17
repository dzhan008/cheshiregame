#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Dun_Map.h"
#include "Entity.h"
#include "Item.h"

using namespace std;

class Dungeon
{
	//data fields
private:
	dun_map* dungeon_map;
	vector<Entity*> entity_group;
	string dungeon_name;
	string dungeon_difficulty;
	vector<Item*> dungeon_loot; //stores all the loot that all entities have in this dungeon

public:
	Dungeon();
	Dungeon(const string &text_file, const string &map_file); //constructor for first dungeon
	~Dungeon(); //destructor
	void change_dungeon(const string &text_file, const string &map_file); //changes dungeon
	const void display_dungeon(); //displays monsters in dungeon
	int size(); //returns number of monsters in dungeon
	const string get_dun_name(); //returns dungeon name
	Entity* rand_monster(); //returns a random entity in the dungeon
	Entity* get_boss(); //returns the boss
	bool run_dungeon(player*& p, Combat_System c);


	//helper functions
private:
	void fill_dungeon(const string &text_file, const string &map_file); //helper func for constructor
	void clear_dun(); //clears the dungeon_loot vector when you change dungeons
};

#endif