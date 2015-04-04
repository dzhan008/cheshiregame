#ifndef ENTITY_H
#define ENTITY_H

#include "stdafx.h"
#include <string>
#include <vector>


/*Dependencies*/

class Ally;

using namespace std;

/*
struct Spells
{
string spell_name;
int spell_dmg;
};
*/

class Entity
{
public:
	/*
	enum E_COMPONENTS
	{
	WATER = 0X0001,
	FIRE = 0X0010,
	EARTH = 0X0100,
	AIR = 0X1000
	};
	*/


	/*Create Entity*/
	Entity();
	Entity(string entityName, int health, int lvl, int amount, int d, int val);
	~Entity();
	/*Health*/
	int getMaxHealth(); //gets max HP to be used in main
	void setHealth(int health); // updates HP of entity when attacked
	int getHealth(); // gets the updated HP to be used in main

	string getName(); //gets name to be used in main
	int getLevel(); //gets the level to be used in main
	int getEXP(); //gets the amount of EXP to be used in main
	int getDef();
	int getVal();
	/*Stats*/
	void setEntityStats(int str, int agi, int vit, int dex, int luk);
	void DisplayStats(); //displays the stats of the entity to be used in main

	/*Loot*/
	void add_loot(Item* i); //adds one item to vector of loot
	void give_loot(player*& p); //adds loot to player inventory
	void give_gold(player*& p); //adds gold to player

	/*Print*/
	void Print(); //prints all information about entity
	void print_loot(); //prints all the loot 

	int calculateDamage(player play, bool defend);
	int calculateDamage(Ally* ally, bool defend);

	bool isDefending();
	void setDefending(bool b);

private:
	string name;
	int maxHP;
	int currHP;
	int level;
	int value;
	int min_dmg;
	int max_dmg;
	int def;
	bool defending;
	vector<int> entityStats;
	int numEXP;
	//int components;

	vector<Item*> loot;

	int randNumber();
};

#endif
