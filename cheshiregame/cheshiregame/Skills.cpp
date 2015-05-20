#include "stdafx.h"
#include <iostream>
#include <fstream>

Skill::Skill(string nam, string typ, double ex, double ac, int mp)
{ 
	name = nam;
	type = typ;
	ex_dmg = ex;
	acc = ac;
	mana_cost = mp;
}
Skill::Skill(string nam, string typ, int min, int max, double ac, int mp)
{
	name = nam;
	type = typ;
	min_dmg = min;
	max_dmg = max;
	acc = ac;
	mana_cost = mp;
}

Skill::Skill(std::string file_name)
{
	fstream inFile;


}

string Skill::getName()
{
	return name;
}

int Skill::calc_dmg(player* p)
{
	if (type == "Heal")
	{
		return randNumber();
	}
	else if (type == "P_Damage")
	{
		int curr_dmg = p->randNumber();
		int boosted_dmg = curr_dmg * ex_dmg;
		return curr_dmg + ex_dmg;
	}
	else if (type == "D_Damage")
	{
		return randNumber();
	}

}

bool Skill::isHit()
{
	int ch = rand() % 100 + 1;
	if (acc <= ch)
	{
		return true;
	}
	return false;
}

void Skill::use_skill(player* p, Entity* e)
{
	if (!isHit())
	{
		std::cout << "The skill missed!" << std::endl;
		return;
	}
	int dmg_output = calc_dmg(p);
	std::cout << "The skill hit for " << dmg_output << " damage!" << std::endl;
	p->setMP(p->getMP() - mana_cost);
 	e->setHealth(e->getHealth() - dmg_output);
}

int Skill::randNumber(){
	return (rand() % (max_dmg - min_dmg)) + min_dmg;
}