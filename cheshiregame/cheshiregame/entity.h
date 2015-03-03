#ifndef ENTITY_H
#define ENTITY_H

#include "stdafx.h"
#include <string>
#include <vector>


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
	Entity(string entityName, int health, int lvl, int amount);
	/*Health*/
	int getMaxHealth(); //gets max HP to be used in main

	void setHealth(int health); // updates HP of entity when attacked
	int getHealth(); // gets the updated HP to be used in main

	string getName(); //gets name to be used in main
	int getLevel(); //gets the level to be used in main
	int getEXP(); //gets the amount of EXP to be used in main

	/*Stats*/
	void setEntityStats(int str, int agi, int vit, int dex, int luk);
	void DisplayStats(); //displays the stats of the entity to be used in main



	/*Print*/
	void Print(); //prints all information about entity

private:
	string name;
	int maxHP;
	int currHP;
	int level;
	vector<int> entityStats;
	int numEXP;
	//int components;
};

#endif