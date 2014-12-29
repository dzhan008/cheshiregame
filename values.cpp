#include <iostream>
#include <vector>
#include <string>
#include "values.h"

using namespace std;

//Does health even need to be here? We could probably just encorporate it in player/monster class

void values::statprogression() //Adding stats
{
    int remainingStats = 0; //Figure out how to add more points here. Maybe make a parameter?
    int points = 0;
    
    string stat;
    
    playerstats.resize(5); //5 Stats
    
    while(remainingStats > 0)
    {
        cout << "Strength:  " << playerstats.at(0) << endl;
        cout << "Agility:   " << playerstats.at(1) << endl;
        cout << "Vitality:  " << playerstats.at(2) << endl;
        cout << "Dexterity: " << playerstats.at(3) << endl;
        cout << "Luck:      " << playerstats.at(4) << endl;
        cout << "You have " << remainingStats << " stat points remaining." << endl;
        cout << "Stat: ";
        cin >> stat;
        if (stat == "Str" || stat == "Strength" || stat == "str" || stat == "strength") //Add points to appropriate stat
        {
            cout << "Points: ";
            cin >> points;
            playerstats.at(0) += points;
        }
        else if (stat == "Agi" || stat == "Agility" || stat == "agi" || stat == "agility")
        {
            cout << "Points: ";
            cin >> points;
            playerstats.at(1) += points;
        }
        else if (stat == "Vit" || stat == "Vitality" || stat == "vit" || stat == "vitality")
        {
            cout << "Points: ";
            cin >> points;            
            playerstats.at(2) += points;
        }
        else if (stat == "Dex" || stat == "Dexterity" || stat == "dex" || stat == "dexterity")
        {
            cout << "Points: ";
            cin >> points;            
            playerstats.at(3) += points;
        }
        else if (stat == "Luk" || stat == "Luck" || stat == "luk" || stat == "luck")
        {
            cout << "Points: ";
            cin >> points;            
            playerstats.at(4) += points;
        }
        else
        {
            cout << "Invalid stat type." << endl;
        }
        remainingStats -= points;
    }
}

/*
Looking at each cell in order:
0 = Strength
1 = Agility
2 = Vitality
3 = Dexterity
4 = Luck
*/