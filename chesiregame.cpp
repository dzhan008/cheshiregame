#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "demo.h"
#include "entity.h"
#include "Combat_System.h"
#include "Shop.h"

using namespace std;

int menu();

int main()
{
    srand(time(0));

    cout << "Chesire's Game" << endl;
    cout << "Prototype Version 1.0" << endl;
    cout << "Welcome to the demo!" << endl;
    menu();

    return 0;
}

int menu()
{
    int decision = 0;

    while (decision != 4)
    {

        demo stat_demo;
        Shop demo_shop;
        string x = "Player 1";
        string y = "Enemy 1";
        string line = "--------------------------------------------------------------------------------";
        player* play = new player(x, 10, 1, 0);
        entity* enemy = new entity(y, 10, 1, 0);
        Combat_System battle_demo = Combat_System(play);


        cout << "Please select one of the options below: " << endl;
        cout << "1. Combat Simulation" << endl;
        cout << "2. Shop Simulation" << endl;
        cout << "3. Stats Simulation" << endl;
        cout << "4. Exit" << endl;
        cout << "Input the number for your selection: ";
        cin >> decision;

        if (decision == 1)
        {
            cout << line << endl;
            battle_demo.runBattle(enemy);
        }
        else if (decision == 2)
        {
            cout << line << endl;
            demo_shop.Store();
        }
        else if (decision == 3)
        {
            cout << line << endl;
            stat_demo.statProgression();
        }
        else if (decision == 4)
        {
            cout << "Thanks for playing!" << endl;
            return 0;
        }
        cout << "The simulation has ended. Returning to main menu..." << endl;
        cout << line << endl;
        menu();
    }


}
