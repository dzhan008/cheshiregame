#include <iostream>
#include <vector>
#include <string>
#include "entity.h"

using namespace std;

/*Create Entity*/
void entity::createEntity(string entityName, int health, int lvl, int amount)
{
    name = entityName;
    maxHP = health;
    level  = lvl;
    numEXP = amount;
}


//Gets the information of each individually. just in case we need to 
/*Name*/
string entity::getName()
{
    return name;
}
/*Health*/
int entity::getHealth()
{
    return maxHP;
}
/*Level*/
int entity::getLevel()
{
    return level;
}
/*Experience*/
int entity::getEXP()
{
    return numEXP;
}

/*Stats*/
//Sets the stats of the entity
void entity::setEntityStats(int str, int agi, int vit, int dex, int luk)
{
    entityStats.resize(5);
    entityStats.at(0) = str;
    entityStats.at(1) = agi;
    entityStats.at(2) = vit;
    entityStats.at(3) = dex;
    entityStats.at(4) = luk;
}

//Just displays the stats
void entity::DisplayStats()
{
    cout << "Strength:  " << entityStats.at(0) << endl;
    cout << "Agility:   " << entityStats.at(1) << endl;
    cout << "Vitality:  " << entityStats.at(2) << endl;
    cout << "Dexterity: " << entityStats.at(3) << endl;
    cout << "Luck:      " << entityStats.at(4) << endl;
}


/*Print*/
//Prints all information about entity
void entity::Print()
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
