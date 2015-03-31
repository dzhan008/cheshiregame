#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*Create Entity*/

Entity::Entity()
: name("Enemy"), maxHP(10), currHP(10), level(1), numEXP(1), min_dmg(1), max_dmg(10), def(0)
{ }
Entity::Entity(string entityName, int health, int lvl, int amount, int d)
: name(entityName), maxHP(health), currHP(health), level(lvl), numEXP(amount), min_dmg(1), max_dmg(10), def(d)
{ }


//Gets the information of each individually. just in case we need to
/*Name*/
string Entity::getName()
{
	return name;
}
/*Health*/
int Entity::getHealth()
{
	return currHP;
}
int Entity::getMaxHealth(){
	return maxHP;
}
/*Level*/
int Entity::getLevel()
{
	return level;
}
/*Experience*/
int Entity::getEXP()
{
	return numEXP;
}

void Entity::setHealth(int health)
{
	currHP = health;
}

int Entity::getDef(){
	return def;
}

int Entity::randNumber(){
	return rand() % (max_dmg - min_dmg) + min_dmg;
}

int Entity::calculateDamage(player play, bool defend){
	int baseDamage = randNumber();
	int trueDamage = baseDamage - play.getDef();
	if (defend){
		trueDamage /= 5;
	}
	return trueDamage;
}

int Entity::calculateDamage(Ally* ally, bool defend){
	int baseDamage = randNumber();
	int trueDamage = baseDamage - ally->getDef();
	if (defend){
		trueDamage /= 5;
	}
	return trueDamage;
}

/*Stats*/
//Sets the stats of the entity
void Entity::setEntityStats(int str, int agi, int vit, int dex, int luk)
{
	entityStats.resize(5);
	entityStats.at(0) = str;
	entityStats.at(1) = agi;
	entityStats.at(2) = vit;
	entityStats.at(3) = dex;
	entityStats.at(4) = luk;
}

//Just displays the stats
void Entity::DisplayStats()
{
	cout << "Strength:  " << entityStats.at(0) << endl;
	cout << "Agility:   " << entityStats.at(1) << endl;
	cout << "Vitality:  " << entityStats.at(2) << endl;
	cout << "Dexterity: " << entityStats.at(3) << endl;
	cout << "Luck:      " << entityStats.at(4) << endl;
}


/*Print*/
//Prints all information about entity
void Entity::Print()
{
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "HP: " << maxHP << endl;
	cout << "Stats" << endl;

	cout << "Strength:  " << entityStats.at(0) << endl;
	cout << "Agility:   " << entityStats.at(1) << endl;
	cout << "Vitality:  " << entityStats.at(2) << endl;
	cout << "Dexterity: " << entityStats.at(3) << endl;
	cout << "Luck:      " << entityStats.at(4) << endl;

}

void Entity::add_loot(Item i)
{
	loot.push_back(i);
}

void Entity::give_loot(player p)
{
	for (int i = 0; i < loot.size(); i++)
	{
		p.add_inventory(loot.at(i));
	}
}

void Entity::print_loot()
{
	cout << name << "'s Loot: " << endl;
	for (int i = 0; i < loot.size(); i++)
	{
		loot.at(i)->printItem();
	}
}
