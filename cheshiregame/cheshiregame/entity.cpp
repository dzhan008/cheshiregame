#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*Create Entity*/

Entity::Entity()
	: name("Enemy"), maxHP(10), currHP(10), level(1), numEXP(1), min_dmg(1), max_dmg(10), def(0), value(0), defending(false)
{
	entityStats.resize(5);
	entityStats.at(0) = 1;
	entityStats.at(1) = 1;
	entityStats.at(2) = 1;
	entityStats.at(3) = 1;
	entityStats.at(4) = 1;
}
Entity::Entity(string entityName, int health, int mana, int lvl, int amount, int d, int val)
	: name(entityName), maxHP(health), currHP(health), maxMP(mana), currMP(mana), level(lvl), numEXP(amount), min_dmg(1), max_dmg(10), def(d), value(val), defending(false)
{
	entityStats.resize(5);
	entityStats.at(0) = 1;
	entityStats.at(1) = 1;
	entityStats.at(2) = 1;
	entityStats.at(3) = 1;
	entityStats.at(4) = 1;
	updateStats();
}

Entity::Entity(Entity*& x)
{
	name = x->getName();
	maxHP = x->getMaxHealth();
	currHP = x->getMaxHealth();
	maxMP = x->getMaxMana();
	currMP = x->getMaxMana();
	numEXP = x->getEXP();
	level = x->getLevel();
	value = x->getVal();
	min_dmg = 1;
	max_dmg = 10;
	def = x->getDef();
	defending = false;
	entityStats.resize(5);
	entityStats = x->getStats();
}
Entity::~Entity()
{
	for (int i = 0; i < loot.size(); i++)
	{
		loot.at(i) = 0;
	}
}

vector<int> Entity::getStats()
{
	return entityStats;
}
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

/*Mana*/
int Entity::getMaxMana()
{
	return maxMP;
}
void Entity::setMana(int m)
{
	currMP = m;
}
int Entity::getMana()
{
	return currMP;
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

int Entity::getVal() //For gold
{
	return value;
}

int Entity::randNumber(){
	if (max_dmg == min_dmg){
		return max_dmg;
	}
	return rand() % (max_dmg - min_dmg) + min_dmg;
}

int Entity::calculateDamage(player play, bool defend){
	int baseDamage = randNumber();
	int trueDamage = baseDamage - play.getDef();
	if (defend){
		trueDamage /= 5;
	}
	if (trueDamage <= 0){
		trueDamage = 1;
	}
	return trueDamage;
}

int Entity::calculateDamage(Ally* ally, bool defend){
	int baseDamage = randNumber();
	int trueDamage = baseDamage - ally->getDef();
	if (defend){
		trueDamage /= 5;
	}
	if (trueDamage <= 0){
		trueDamage = 1;
	}
	return trueDamage;
}

int Entity::tRand(){
	return rand() % 100 + 1;
}

bool Entity::calculateCrit(){
	double temp = 2 + (entityStats.at(4) * .13);
	int x = tRand();
	if (x < temp){
		return true;
	}
	return false;
}

bool Entity::calculateAccuracy(player* p){ //FIX
	vector<int> pStats = p->getStats();
	double temp = entityStats.at(3) / pStats.at(1) * 100;
	if (temp < 10){
		temp = 10;
	}
	int x = tRand();
	if (x < temp){
		return true;
	}
	else{
		return false;
	}
}

bool Entity::calculateAccuracy(Ally* a){
	vector<int> aStats = a->getStats();
	double temp = entityStats.at(1) / aStats.at(3) * 100;
	int x = randNumber();
	if (temp < 10){
		temp = 10;
	}
	if (x < temp){
		return true;
	}
	else{
		return false;
	}
}

bool Entity::isDefending(){
	return defending;
}

void Entity::setDefending(bool b){
	defending = b;
}

bool Entity::empty_loot()
{
	if (loot.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Entity::add_spells(Spells* s)
{
	entity_spells.push_back(s);
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

void Entity::updateStats()
{
	min_dmg += entityStats.at(0) / 2;
	max_dmg += entityStats.at(0) / 2;
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
	print_loot();
	print_spells();

}

void Entity::add_loot(Item* i)
{
	loot.push_back(i);
}

void Entity::give_loot(player*& p)
{
	for (int i = 0; i < loot.size(); i++)
	{
		p->add_inventory(loot.at(i));
	}
}

void Entity::give_gold(player* &p)
{
	p->setmoney(p->getmoney() + value);
}

void Entity::print_loot()
{
	for (int i = 0; i < loot.size(); i++)
	{
		loot.at(i)->printItem();
	}
}
void Entity::print_spells()
{
	for (int i = 0; i < entity_spells.size(); i++)
	{
		entity_spells.at(i)->printSpell();
	}
}