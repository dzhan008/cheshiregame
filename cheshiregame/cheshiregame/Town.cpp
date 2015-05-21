#include "stdafx.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Town.h"
#include "Store.h"
/*
Town fileformat will be as follows:
   
   <townname>
   <store_filename>
   <# of people>
   <person 1's name>
   <person 1 dialog>
   <person 2's name>
   <person 2's dialog>
   <continued>
*/
using namespace std;

void Town::fill_town(const std::string &text_file) {
    std::string townname;
	std::string store_filename = "all_items.txt";
    int people_count;

    std::ifstream inFS;
    inFS.open(text_file.c_str());
    if (!inFS.is_open()) {
        std::cerr << "Error: Cannot open Town file" << std::endl;
        return;
    }
    std::getline(inFS, townname);
    this->townname = townname;
    std::getline(inFS, store_filename);
    Store s;
    // TODO: Make a sample store?
    this->s = s;
    string p;
    std::getline(inFS, p);
    stringstream ss(p);
    ss >> people_count;
    //inFS >> people_count;
    //std::cout << store_filename << std::endl;
    std::string name;
    std::string dialog;
    for (int i = 0; i < people_count; ++i) {
    //    std::cout << i << std::endl;
        std::getline(inFS, name);
        std::getline(inFS, dialog);
    //    std::cout << name << ": " << dialog << std::endl;
        people.push_back(
            std::make_pair(name, dialog));
    }
    inFS.close();
}

Town::Town(player* p) {
	//dungeon1 = new Dungeon("demo_dun_1.txt");
	//dungeon2 = new Dungeon("demo_dun_2.txt");
   // fill_town("sample_town.txt");
	string dun_ent;
	string map_t;
	string dun;

	dun_ent = "dungeon_easy.txt";
	map_t = "map_1.txt";
	dun = "all_entity.txt";
	d = new Dungeon(dun);
	d->fill_dungeon(dun_ent, map_t);

	p->set_condition("boss_1", false); //Boss conditions
	p->set_condition("boss_2", false);
	p->set_condition("boss_3", false);

	std::string store_filename = "all_items.txt";
	s.fillStore(store_filename); //Change later to work for ANY STORE
	createAllies(p);
	skills.fill_skills("skills.txt");
}

Town::Town(std::string filename) {
    //fill_town(filename);
}

void Town::display_options()
{
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Visit Inn" << std::endl
		<< "2. Go shopping" << std::endl
		<< "3. Go to the blacksmith" << std::endl
		<< "4. Go to the tavern" << std::endl
		<< "5. Go to mystic" << std::endl
		<< "6. Go talk to the townspeople" << std::endl
		<< "7. Go to a dungeon" << std::endl
		<< "8. Menu" << std::endl;
		//<< "8. Save Game" << std::endl;
}

void Town::run(player* p) {
    // Main function? I guess.
    //std::cout << "Welcome to " << townname << std::endl;
	if (p->getHP() < 0)
	{
		return;
	}
	int choice = -1;
	int dun_counter = 0;
	system("cls");
	std::cout << "You are currently in an unknown city!" << std::endl;
	display_options();
    while (choice != -2) //Fix for exit
    {
        std::cout << "> ";
        cin >> choice;
        if (cin.good()) {

            if (choice == 1) {
				system("cls");
                inn(p);
				system("cls");
				display_options();
            }
            else if (choice == 2) {
				system("cls");
                store(p);
				system("cls");
				display_options();
            }
            else if (choice == 3) {
				system("cls");
                blacksmith(p);
				system("cls");
				display_options();
            }
            else if (choice == 4) {
				system("cls");
                tavern(p);
				system("cls");
				display_options();
            }
			else if (choice == 5)
			{
				system("cls");
				mystic(p);
				system("cls");
				display_options();
			}
            else if (choice == 6) {
				system("cls");
                talk();
				system("cls");
				display_options();
            }
            else if (choice == 7) {
				system("cls");
                dungeon_select(p, dun_counter);
				system("cls");
				if (dun_counter == 3)
				{
					sc->scene_006(p);
				}
				display_options();
            }
            else if (choice == 8) {
				sc->basic_menu(p);
				system("cls");
				display_options();
            }
            else if (choice == 0) {
                //savesystem.p = *p;
                //savesystem.saveSave();
            }
            else {
                cout << "Invalid input." << std::endl;
            }
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
	}
    return;
}

void Town::inn(player* p) {

	int choice = -1;
	std::string input;
    

	while (choice != 3)
	{
		std::cout << "Welcome to the inn." << std::endl;
		std::cout << "1. Rest" << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cout << ">";
		std::cin >> choice;
        if (cin.good()) {
            if (choice == 1) {
                std::cout << "It will cost you 50 gold. Are you sure?" << std::endl;
				std::cout << "You have " << p->getmoney() << " gold." << std::endl;
                std::cout << "1. Yes" << std::endl;
                std::cout << "2. No" << std::endl;
                std::cin >> choice;
                if (choice == 1)
                {
                    if (p->getmoney() < 50)
                    {
                        std::cout << "What do you think this is, a charity house? Get lost!" << std::endl;
                        return;
                    }
                    else
                    {
                        p->setmoney(p->getmoney() - 50);
                        p->setHP(p->getMaxHP());
                        std::cout << "Hope you enjoyed your stay!" << std::endl;
                        return;
                    }
                }
                else if (choice == 2)
                {
                    return;
                }
            }
            else if (choice == 2) {
                return;
            }
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Bad input, try again." << endl;
	}
    return;
}

void Town::blacksmith(player* p) {
    
	int choice = -1;

	std::cout << "Welcome to the blacksmith." << std::endl;
	std::cout << "1. Upgrade Weapon." << std::endl;
	std::cout << "2. Exit." << std::endl;
	while (choice != 2)
	{
		std::cin >> choice; 
		if (cin.good())
		{
			if (choice == 1)
			{
				std::string wep;

				std::cout << "I can refine your weapon for a price. However, there is a chance I may break it." << std::endl;
				std::cout << "The price to refine your weapon is 100 gold." << std::endl;
				if (p->getmoney() < 100)
				{
					std::cout << "Sorry pal, you don't have enough gold." << std::endl;
					return;
				}
				std::cout << "Which weapon would you like me to refine? (Type q to quit)" << std::endl;
				std::cin.ignore();
				getline(std::cin, wep);
				if (wep == "q")
				{
					return;
				}
				while (p->inventory_search(wep) == NULL)
				{
					std::cout << "You do not have this weapon. Please enter it again." << std::endl;
					getline(std::cin, wep);
					if (wep == "q")
					{
						return;
					}
				}
				std::cout << "Alright, here goes!" << std::endl;
				if ((rand() % 3 + 1) == 1)
				{
					std::cout << "The blacksmith hammers down your weapon, tempering it skillfully." << std::endl;
					std::cout << "\"Here you go.\" The blacksmith hands you your weapon, which looks better than ever." << std::endl;
					dynamic_cast<Weapon*>(p->inventory_search(wep))->add_dmg((rand() % 10 + 1));
					return;
				}
				else
				{
					std::cout << "The blacksmith clanks your weapon with his hammer, but breaks it with his next strike." << std::endl;
					std::cout << "\"Curses! My hand slipped.\" He frowns, and apologetically hands you your broken weapon." << std::endl;
					p->remove_inventory(wep);
					return;
				}

			}
			if (choice == 2)
			{
				return;
			}
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Bad input, try again." << endl;
	}

    return;
}
void Town::displayAllies()
{
	for (int i = 0; i < allies.size(); ++i)
	{
		std::cout << i << ". " << allies.at(i)->getname() << " , Cost: " << allies.at(i)->getMaxHP() << std::endl;
	}
	std::cout << "4.Exit\n";
}
void Town::displayTavernMenu()
{
	std::cout << "1. Get me some drinks!\n";
	std::cout << "2. I need to recruit allies.\n";
	std::cout << "3. Exit.\n";
}
void Town::createAllies(player* p)
{
	//Will generalize later
	Ally* baby = new Ally("Angry Toddler", "Thief", 10, 1, 0);
	allies.push_back(baby);
	Ally* recruit = new Ally("Overly Eager Recruit", "Swordsman", 50, p->getlevel(), p->getexp());
	allies.push_back(recruit);
	Ally* horse = new Ally("Horsey", "Thief", 100, p->getlevel(), p->getexp());
	allies.push_back(horse);
	Ally* mage = new Ally("Sorceror's Apprentice", "Sorceror", p->getMaxHP(), p->getlevel(), p->getexp());
	allies.push_back(mage);

}
void Town::tavern(player* p) {
	int input = 0;
	std::cout << "Welcome to the newly built tavern! I'm the innkeeper, how can I help you?\n";
	displayTavernMenu();
	cin >> input;

	while (input != 3)
	{
		while (cin.fail())
		{
			std::cout << "You're drunk aren't you. Try a different input.";
			cin >> input;
		}
		if (input == 1)
		{
			std::cout << "Hey wait I know you...you're that deadbeat who doesn't pay up.\n";
			std::cout << "I'm not giving you any drinks anytime soon.\n";
			displayTavernMenu();
			cin >> input;
		}
		else if (input == 2)
		{
			if (allies.empty())
			{
				system("cls");
				std::cout << "You've got all the allies here! See you later you cheap ass drunk!";
				_getch();
				return;
			}
			int index;
			std::cout << "There are several people here waiting for you, friend! Choose who you want!\n";
			displayAllies();
			std::cout << "You have " << p->getmoney() << " gold remaining.\n";
			cin >> index;
			if (index < 0 || index >= allies.size())
			{
				system("cls");
				std::cout << "Ally does not exist. Try another number.\n";
				displayAllies();
				cin >> index;
			}
			if (p->getmoney() < allies.at(index)->getMaxHP())
			{
				system("cls");
				std::cout << "You are too poor.\n";
				displayAllies();
				cin >> input;
			}
			else
			{
				p->add_member(allies.at(index));

				int totalGold = p->getmoney() - allies.at(index)->getMaxHP();
				p->setmoney(totalGold);
				std::cout << "You have " << totalGold << " remaining.\n";
				p->set_min_dmg(allies.at(index)->getDef());

				system("cls");

				std::cout << allies.at(index)->getname() << " is now part of your team! This should help in battle.\n";
				allies.erase(allies.begin() + index);

				displayTavernMenu();
				cin >> input;
			}
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	std::cout << "Goodbye!\n";
	_getch();
	return;
}

void Town::store(player* p) {
    s.run(p);
    return;
}

void Town::mystic(player* p)
{
	std::cout << "Let me provide you with a set of skills...They will help you on your journey." << std::endl;
	p->add_skill(skills.get_skill(0));
	p->add_skill(skills.get_skill(3));
	_getch();
}

void Town::talk() {
	int input;
	std::cout << "Who would you like to talk to?." << std::endl;
	std::cout << "1. Astuce" << std::endl;
	return;
    /*srand(time(NULL));
    int random = rand() % this->people.size();
    std::cout << people.at(random).first << " says: " <<
    people.at(random).second << std::endl;*/
}

void Town::dungeon_select(player* p, int & dun_counter)
{

	string input;
	string dun_ent;
	string map_t;
	string dun;
	Combat_System cs(p, p->get_party());
	std::cout << "Which dungeon would you like to go to?" << std::endl;
	std::cout << "1. Elka's Hatchery" << std::endl;
	std::cout << "2. Calescent Chamber " << std::endl;
	std::cout << "3. Frostfang Cavern" << std::endl;
	//Output dungeons
	while (input != "back" && input != "b")
			{
			std::cin >> input;
			if (input == "back" && "b")
			{
				return;
			}
			else if (input == "1")
			{	
				dun_ent = "dungeon_easy.txt";
				map_t = "map_1.txt";

				d->change_dungeon(dun_ent, map_t);
				if (!d->run_dungeon(p, cs))
				{
					std::cout << "You have died... returning to town..." << std::endl;
					_getch();
					p->setHP(10);
					return;
				}
				system("cls");
				sc->output_file("boss_001.txt");
				cs.runBattle(d->get_boss());
				sc->output_file("boss_001_1.txt");
				if (p->getHP() <= 0)
				{
					std::cout << "You have died... returning to town..." << std::endl;
					_getch();
					p->setHP(10);
					return;
				}
				if (p->check_condition("boss_1"))
				{
					return;
				}
				p->set_condition("boss_1", true);
				dun_counter++;
				return;
			}
			else if (input == "2")
			{
				dun_ent = "dungeon_med.txt";
				map_t = "map_2.txt";

				d->change_dungeon(dun_ent, map_t);
				if (!d->run_dungeon(p, cs))
				{
					std::cout << "You have died... returning to town..." << std::endl;
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
					_getch();
					p->setHP(10);
					return;
				}
				system("cls");
				sc->output_file("boss_002.txt");
				cs.runBattle(d->get_boss());
				sc->output_file("boss_002_1.txt");
				if (p->getHP() <= 0)
				{
					std::cout << "You have died... returning to town..." << std::endl;
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
					_getch();
					p->setHP(10);
					return;
				}
				if (p->check_condition("boss_2"))
				{
					return;
				}
				p->set_condition("boss_2", true);
				dun_counter++;
				return;
			}
			else if (input == "3")
			{

				dun_ent = "dungeon_hard.txt";
				map_t = "map_3.txt";

				d->change_dungeon(dun_ent, map_t);
				if (!d->run_dungeon(p, cs))
				{
					std::cout << "You have died... returning to town..." << std::endl;
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
					_getch();
					p->setHP(10);
					return;
				}
				system("cls");
				sc->output_file("boss_003.txt");
				cs.runBattle(d->get_boss());
				sc->output_file("boss_003_1.txt");
				if (p->getHP() <= 0)
				{
					std::cout << "You have died... returning to town..." << std::endl;
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
					_getch();
					p->setHP(10);
					return;
				}
				if (p->check_condition("boss_3"))
				{
					return;
				}
				p->set_condition("boss_3", true);
				dun_counter++;
				return;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
	}





	/*FOR DEMO ONLY*/

}

