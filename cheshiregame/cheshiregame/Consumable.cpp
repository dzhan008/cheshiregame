#include "stdafx.h"
#include "Consumable.h"
#include "Player.h"

#include <iostream>

using namespace std;

Consumable::Consumable(std::string name, std:: string type, unsigned boost, int val)
{
	this->name = name;
	this->value = val;
	this->type = type;
	this->rarity = 0;
	this->boost = boost;
}
void Consumable::usePotion(player* p) //I don't think we need a bool function
{
	if (p->getHP() + boost > p->getMaxHP()) //100 assumed to be max health for now
	{
		p->setHP(p->getMaxHP());
	}
	else
	{
		p->setHP(p->getHP() + boost);
	}
}
/*Consumable::~Consumable()
{
	delete this;
}*/
string Consumable::getType() const
{
	return "Consumable";
}