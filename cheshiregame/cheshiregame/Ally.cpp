#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

Ally::Ally(){
	allyname = "Default Ally";
	allyjob = "Beginner";

	maxHP = 10;
	currHP = 10;
	level = 1;
	exp = 0;
	min_dmg = 1;
	max_dmg = 10;
	def = 0;
	defending = false;

	allystats.resize(5);
	equipment.resize(6);

	allystats.at(0) = 1;
	allystats.at(1) = 1;
	allystats.at(2) = 1;
	allystats.at(3) = 1;
	allystats.at(4) = 1;
}

Ally::Ally(string aName, string aJob, int health, int lvl, int xp){
	allyname = aName;
	allyjob = aJob;

	maxHP = health;
	currHP = health;
	level = lvl;
	exp = xp;
	min_dmg = 1;
	max_dmg = 10;
	def = 0;
	defending = false;
	
	allystats.resize(5);
	equipment.resize(6);

	allystats.at(0) = 1;
	allystats.at(1) = 1;
	allystats.at(2) = 1;
	allystats.at(3) = 1;
	allystats.at(4) = 1;
}

int Ally::getMaxHP(){
	return maxHP;
}

int Ally::getHP(){
	return currHP;
}

int Ally::getlevel(){
	return level;
}

int Ally::getexp(){
	return exp;
}

int Ally::getDef(){
	return def;
}

vector<int> Ally::getStats(){
	return allystats;
}

int Ally::tRand(){
	return rand() % 100 + 1;
}

bool Ally::calculateAccuracy(Entity* e){
	vector<int> eStats = e->getStats();
	double temp = allystats.at(1) / eStats.at(3) * 100;
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

bool Ally::calculateCrit(){
	double temp = 2 + (allystats.at(4) * .13);
	int x = tRand();
	if (x < temp){
		return true;
	}
	return false;
}

bool Ally::isDefending(){
	return defending;
}
int Ally::randNumber(){
	return rand() % (max_dmg-min_dmg) + min_dmg;
}

int Ally::calculateDamage(Entity enemy, bool defend){
	int baseDamage = randNumber();
	int trueDamage = baseDamage - enemy.getDef();
	if (defend){
		trueDamage /= 5;
	}
	if (trueDamage <= 0){
		trueDamage = 1;
	}
	return trueDamage;
}

string Ally::getname(){
	return allyname;
}

void Ally::setHP(int health){
	currHP = health;
}

void Ally::setlevel(int lvl){
	level = lvl;
}

void Ally::setexp(int expx1){
	exp = expx1;
}

void Ally::setstats(vector<int>& stats){
	allystats.at(0) += stats.at(0);
	allystats.at(1) += stats.at(1);
	allystats.at(2) += stats.at(2);
	allystats.at(3) += stats.at(3);
	allystats.at(4) += stats.at(4);
}

void Ally::set_min_dmg(int dmg){
	min_dmg = dmg;
}

void Ally::set_max_dmg(int dmg){
	max_dmg = dmg;
}

void Ally::set_def(int idef){
	def = idef;
}

void Ally::setDefending(bool b){
	defending = b;
}

void Ally::setname(string name){
	allyname = name;
}

void Ally::setjob(string job){
	allyjob = job;
}

void Ally::displayInfo(){
	cout << allyname << endl;
	cout << "Health: " << currHP << "/" << maxHP << endl;
	cout << "Stats" << endl;
	cout << "Strength:  " << allystats.at(0) << endl;
	cout << "Agility:   " << allystats.at(1) << endl;
	cout << "Vitality:  " << allystats.at(2) << endl;
	cout << "Dexterity: " << allystats.at(3) << endl;
	cout << "Luck:      " << allystats.at(4) << endl;
}

void Ally::display_equipment(){
	for (unsigned i = 0; i < equipment.size(); ++i)
	{
		std::cout << equipment.at(i).getName() << std::endl;
	}
}
