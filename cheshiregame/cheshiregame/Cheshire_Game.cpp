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
string dun_ent = "demo_dun_1_enemies.txt";
string map_t = "mapsample.txt";
string dun = "demo_dun_1.txt";
string line = "--------------------------------------------------------------------------------";
player* play = new player(x, "Game Master", 300, 1, 5, 0, 100);
player* invtest = new player(x, "Game Master", 10, 1, 0, 0, 100);
Town town1 = Town();
Entity* enemy = new Entity(y, 10, 10, 1, 0, 5, 20);
Entity* enemy2 = new Entity("Fox", 100, 10, 1, 0, 2, 10);
Combat_System battle_demo = Combat_System(play);
Dungeon* Master_Dun = new Dungeon(dun);
Scene scene;
SaveSystem savesystem;

using namespace std;

int debug();

string getFileContents(std::ifstream& File)
{
	string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			string TempLine;                  //Temp line
			getline(File, TempLine);        //Get temp line
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
	Master_Dun->fill_dungeon(dun_ent, map_t);
	srand(time(0));
	string inputName = "Assets/Title/title2.txt";
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

	while (1)
	{
		cout << "                                1. New Game \n";
		cout << "                                2. Load Game \n";
		cout << "                                3. Options \n";
		cout << "                                4. Credits \n";
        cout << "                                5. Exit \n";

		int input = 0;
		cin >> input;
		if (input == 1)
		{
			vector<int> stats(5);
			for (int i = 0; i < 5; ++i)
			{
				stats.at(i) = 5;
			}
			stats.at(3) = 50;
			play->setstats(stats);
			play->set_min_dmg(30);
			play->set_max_dmg(80);
			play->update_player();
			std::cout << "\n\n\n";
			Consumable* potion = new Consumable("Potion", "Potion", 20, 10);

			play->setmoney(500);
			play->add_con(potion);

			system("cls");

			scene.scene_001(play);
			battle_demo.runBattle(enemy2);
			scene.scene_003(play);
			town1.run(play);
			return 0;
		}
		else if (input == 2)
		{
			savesystem.loadSave();
			*play = savesystem.p;
			//town1 = savesystem.s.t;
			town1.run(play);
		}
		else if (input == 3)
		{
		
		}
		else if (input == 4)
		{
			std::cout << "Cheshire's Game Version 3.0" << std::endl;
			std::cout << "Danny Diep - That Programmer" << std::endl;
			std::cout << "Kenta Kitada - Busy Programmer" << std::endl;
			std::cout << "Quynh Nguyen - No-Sleep Programmer" << std::endl;
			std::cout << "Michaella Sheng - Vice Hater" << std::endl;
			std::cout << "Alex Tran - Elusive Programmer" << std::endl;
			std::cout << "David Zhang - :D" << std::endl;
			std::cout << "1 Rica was harmed in the making of this game." << std::endl;
			std::cout << "\n\n\n\n\n" << std::endl;
		}
        else if (input == 5) {
			exit(1);
			/*Ally* dummy = new Ally;
			play->add_member(dummy);
			Combat_System combat_test(play, play->get_party());
			combat_test.runBattle(enemy2);*/
			//scene.basic_menu(play);
			//town1.run(play);
			/*std::string scene_file = "test_scene.txt";
			scene.output_file(scene_file);*/
			Store s;
			s.fillStore("all_items.txt");
			s.run(play);


        }
	}
	return 0;
}

int debug()
{
	//DEBUG STUFF HERE
	return 1;
}