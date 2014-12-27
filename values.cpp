#include <iostream>
#include <vector>
#include "values.h"

using namespace std;

//Does health even need to be here? We could probably just encorporate it in player/monster class

void values::statprogression()
{
    int remainingStats = 0;
    int points;
    
    string stat;
    
    stats.resize(5);
    
    while(remainingStats > 0)
    {
        cout << "Strength:  " << stats.at(0) << endl;
        cout << "Agility:   " << stats.at(1) << endl;
        cout << "Vitality:  " << stats.at(2) << endl;
        cout << "Dexterity: " << stats.at(3) << endl;
        cout << "Luck:      " << stats.at(4) << endl;
        cout << "You have " << remainingStats << "stat points remaining." << endl;
        cout << "Stat: ";
        cin >> stat;
        cout << "Points: ";
        cin >> points;
        if (stat == "Str" || "Strength" || "str" || "strength")
        {
            stats.at(0) += points;
        }
        else if (stat == "Agi" || "Agility" || "agi" || "agility")
        {
            stats.at(1) += points;
        }
        else if (stat == "Vit" || "Vitality" || "vit" || "vitality")
        {
            stats.at(2) += points;
        }
        else if (stat == "Dex" || "Dexterity" || "dex" || "dexterity")
        {
            stats.at(3) += points;
        }
        else if (stat == "Luk" || "Luck" || "luk" || "luck")
        {
            stats.at(4) += points;
        }
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