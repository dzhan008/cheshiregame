#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
using namespace std;

class entity
{
    public:
    
        /*Create Entity*/
        entity();
        entity(string entityName, int health, int lvl, int amount);
        /*Health*/
        int getMaxHealth(); //gets max HP to be used in main
        
        /*Not sure if I'm supposed to do this function or the Combat person does*/ 
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
};

#endif
