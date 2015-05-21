#include "stdafx.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>



//Gotta move these later or fix up menu
string x = "Player 1";
string y = "Rica";
string dun_ent = "demo_dun_1_enemies.txt";
string map_t = "mapsample.txt";
string dun = "all_entity.txt";
string line = "--------------------------------------------------------------------------------";
player* play = new player(x, "Game Master", 100, 10, 1, 5, 0, 100);
player* invtest = new player(x, "Game Master", 10, 10, 1, 0, 0, 100);
Town town1 = Town(play);
Entity* enemy = new Entity(y, 10, 10, 1, 0, 5, 20);
Entity* enemy2 = new Entity("Fox", 10, 10, 5, 5, 2, 10);
Entity* enemy3 = new Entity("Ngobody", 5, 15, 5, 5, 3, 15);
Combat_System battle_demo = Combat_System(play);
Dungeon* Master_Dun = new Dungeon(dun);
Scene scene;
SaveSystem savesystem;
Game skills_list("skills.txt");

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
				stats.at(i) = 4;
			}
			play->setstats(stats);
			Consumable* potion = new Consumable("Potion", "Consumable", 20, 10);
			play->setmoney(100);
			play->add_inventory(potion);

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
			Skill s1("Rend", "P_Damage", 1.5, 0.40, 10);
			Skill s2("God's Blow", "D_Damage", 999, 2000, 100, 0);
			Skill s3("Epic Heal", "Heal", 50, 100, 0.80, 999999);
			std::cout << skills_list.get_skill(0).getName();
			play->add_skill(skills_list.get_skill(3));
			play->add_skill(s2);
			play->add_skill(s3);

			battle_demo.runBattle(enemy2);

		}
		else if (input == 4)
		{
			std::cout << "Cheshire's Game Version 3.0" << std::endl;
			std::cout << "Danny Diep - That Programmer" << std::endl;
			std::cout << "Kenta Kitada - Busy Programmer" << std::endl;
			std::cout << "Quynh Nguyen - No-Sleep Programmer" << std::endl;
			std::cout << "Michaella Sheng - Vice Raging Programmer" << std::endl;
			std::cout << "Alex Tran - Elusive Programmer" << std::endl;
			std::cout << "David Zhang - Chief Slave-driving Programmer" << std::endl;
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
			town1.run(play);
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