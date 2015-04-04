#include "stdafx.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>



//Gotta move these later or fix up menu
//Shop demo_shop;
string x = "Player 1";
string y = "Rica";
string line = "--------------------------------------------------------------------------------";
player* play = new player(x, "Game Master", 300, 1, 0, 0);
player* invtest = new player(x, "Game Master", 10, 1, 0, 0);
map* map1 = new map(10);
Town town1 = Town();
Entity* enemy = new Entity(y, 10, 1, 0, 5, 20);
Entity* enemy2 = new Entity("Fox", 10, 1, 0, 2, 10);
Combat_System battle_demo = Combat_System(play);
Scene scene;


using namespace std;

int menu();
string getFileContents (std::ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character

	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}

int main()
{

    srand(time(0));
    string inputName = "title2.txt";
    cout << endl;
    ifstream file;
    file.open(inputName.c_str());
    if (!file.is_open())
    {
        cout << "Error opening " << inputName << endl;
        return 1;
    }
    string Art = getFileContents(file);
    cout << Art << endl;

    cout << "                                1. New Game \n";
    cout << "                                2. Load Game \n";
    cout << "                                3. Options \n";
    cout << "                                4. Credits \n";
    int input = 0;
    cin >> input;
    if (input == 1)
    {
		std::cout << "\n\n\n";
		Consumable* potion = new Consumable("Potion", "Potion", 20, 10);
		play->add_con(potion);
		play->set_min_dmg(20);
		play->set_max_dmg(90);
		play->setmoney(500);
		scene.scene_001(play);
		battle_demo.runBattle(enemy2);
		scene.scene_002(play);
		scene.scene_003(play);
		town1.run(play);
		//menu();
    }
	else if (input == 2)
	{
		//map1->run(play,);
		Store s;
		string file = "all_items.txt";
		s.fillStore(file);
		//s.run(play);
	}
    return 0;
}

int menu()
{
    int decision = 0;

    while (decision != 4)
    {


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
			scene.basic_menu(play);
        }
        else if (decision == 3)
        {
			stats stat_demo; //Make sure that this object is reset or else the vector won't reset
            cout << line << endl;
            stat_demo.statProgression(play);
			play->displayInfo();
        }
        else if (decision == 4)
        {
            cout << "Thanks for playing!" << endl;
			exit(0);
        }
		else if (decision == 5) //FIX FUNCTIONS FOR PLAYER POINTERS
		{
			Item* a = new Item("Potion", 10);
			Weapon* b = new Weapon("Sword of Gods", "Sword", 999, 1);
			Item* c = new Item("Mana Potion", 20);
			Weapon* d = new Weapon("Dagger of Shadows", "Dagger", 776, 3);
			Gear* e = new Gear("Clothes", "Chest", 500);
			Gear* f = new Gear("Helmet", "Helmet", 500);
			Consumable* g = new Consumable("Potion", "Potion", 20, 10);		

			std::cout << "Testing add_inventory..." << std::endl;
			
			invtest->add_inventory(c);
			invtest->add_wep(b);
			invtest->add_wep(d);
			invtest->add_gear(e);
			invtest->add_gear(f);
			invtest->add_con(g);

			invtest->display_inventory();

			std::cout << "Testing adding equipments..." << std::endl;

			invtest->equip_wep(0, b);
			invtest->equip_gear(1, e);
			invtest->display_inventory();
			invtest->display_equipment();

			scene.basic_menu(invtest);
			invtest->displayInfo();

			std::cout << "Testing equipment replacement..." << std::endl;

			invtest->equip_wep(0, d);
			invtest->display_inventory();
			invtest->display_equipment();

			std::cout << "Testing equipment removal..." << std::endl;
			invtest->remove_wep(0);
			invtest->display_inventory();
			invtest->display_equipment();

		}
        cout << "The simulation has ended. Returning to main menu..." << endl;
        cout << line << endl;
        menu();
    }
}