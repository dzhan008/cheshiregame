#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Ally.h"
#include "Item.h"
#include "Consumable.h"

/*Dependencies*/
class Ally;

using namespace std;

struct Spells
{
	string spell_name;
	string spell_type;
	int spell_dmg;
	int spell_cost;
	Spells(string s, string t, int d, int cost)
		:spell_name(s), spell_type(t), spell_dmg(d), spell_cost(cost){}
	void printSpell()
	{
		cout << "Spell Name: " << spell_name << endl;
		cout << "Spell Type: " << spell_type << endl;
		cout << "Spell Damage: " << spell_dmg << endl;
		cout << "Mana Cost: " << spell_cost << endl;
	}
	string get_spellname() { return spell_name; }
	string get_spelltype() { return spell_type; }
	int get_spelldmg() { return spell_dmg; }
	int get_spellcost() { return spell_cost; }
};

class Entity
{
public:
	/*Create Entity*/
	Entity();
	Entity(string entityName, int health, int mana, int lvl, int amount, int d, int val);
	Entity(Entity*& x);
	~Entity();
	/*Health*/
	int getMaxHealth(); //gets max HP to be used in main
	void setHealth(int health); // updates HP of entity when attacked
	int getHealth(); // gets the updated HP to be used in main

	int getMaxMana();
	void setMana(int m);
	int getMana();

	string getName(); //gets name to be used in main
	int getLevel(); //gets the level to be used in main
	int getEXP(); //gets the amount of EXP to be used in main
	int getDef();
	int getVal();
	int tRand();
	vector<int> getStats();

	/*Stats*/
	void setEntityStats(int str, int agi, int vit, int dex, int luk);
	void DisplayStats(); //displays the stats of the entity to be used in main
	void updateStats(); //Particularly updates how much damage the enemy can do based on STR (for now).
	/*Loot*/
	void add_loot(Item* i); //adds one item to vector of loot
	void give_loot(player*& p); //adds loot to player inventory
	void give_gold(player*& p); //adds gold to player

	/*Print*/
	void Print(); //prints all information about entity
	void print_loot(); //prints all the loot 
	void print_spells(); //prints all the spells


	int calculateDamage(player play, bool defend);
	int calculateDamage(Ally* ally, bool defend);
	bool calculateCrit();
	bool calculateAccuracy(Ally* a);
	bool calculateAccuracy(player* p);

	bool isDefending();
	void setDefending(bool b);

	bool empty_loot(); //returns true if loot is empty
	bool empty_pots(); //returns true if pots is empty

	void add_spells(Spells* s);
	void add_pots(Consumable* p);
	void give_pots(player* &p);
	void print_pots();

private:
	string name;
	int maxHP;
	int currHP;
	int maxMP;
	int currMP;
	int level;
	int value;
	int min_dmg;
	int max_dmg;
	int def;
	bool defending;
	vector<int> entityStats;
	int numEXP;
	//int components;
	vector<Spells*> entity_spells;
	vector<Item*> loot;
	vector<Consumable*> pots;
	int randNumber();
};

#endif