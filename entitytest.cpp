#include <iostream>
#include <vector>
#include "entity.h"

using namespace std;

int main()
{
    
    entity monster1; //object monster1
    entity monster2;
    
    cout << "Monster 1: " << endl;
    monster1.createEntity("Baron", 200, 1, 100);
    monster1.setEntityStats(2, 3 ,4 ,5 ,6);
    monster1.Print();
    
    cout << endl;
    cout << "Monster 2: " << endl;
    monster2.createEntity("Nashor", 300, 2, 200);
    monster2.setEntityStats(12, 23, 52, 34, 26);
    monster2.Print();
    
    /*
    This is another way to access the entity information individually
    cout << monster1.getName() << endl;
    cout << monster1.getHealth() << endl;
    cout << monster1.getLevel() << endl;
    cout << monster1.DisplayStats() << endl;
    cout << "You gained " << monster1.getEXP() << " EXP!" << endl;
    */
    
    return 0;
    
}
