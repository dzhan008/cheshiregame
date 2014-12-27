#include <iostream>
#include <vector>
#include "values.h"

using namespace std;

int main()
{
    values health;
    values health1;
    
    health.hp = 0;
    health1.hp = 5;
    
    
    cout << health.hp << endl << health1.hp << endl;
    cout << health.stats.at(0);
}