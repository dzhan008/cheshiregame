#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
using namespace std;

class entity
{
    public:
    
    /*Health*/
    void setHealth(int health); //sets max HP
    int getHealth(); //gets max HP to be used in main
    
    /*Not sure if I'm supposed to do this function or the Combat person does*/ 
    //void updatedHealth(); updates HP of entity when attacked
    //int updatedHealth(); gets the updated HP to be used in main
    
    /*Name*/ 
    void setName(string entityName); //set name
    string getName(); //gets name to be used in main
    
    /*Level*/
    void setLevel(int lvl); //sets the level
    int getLevel(); //gets the level to be used in main
    
    /*Stats*/
    void setEntityStats(int str, int agi, int vit, int dex, int luk); 
    void DisplayStats(); //displays the stats of the entity to be used in main
    
    /*Experience*/
    void setEXP(int amount); //sets the amount of EXP the entity has
    int getEXP(); //gets the amount of EXP to be used in main
    
    /*Print*/
    void Print(); //prints all information about entity
    
    private:
    string name;
    int maxHP;
    int currHP;
    int level;
    vector<int> entityStats;
    int numEXP;
    
    
};

#endif
