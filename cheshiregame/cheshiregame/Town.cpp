#include "stdafx.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

Town::Town() {
	//dungeon1 = new Dungeon("demo_dun_1.txt");
	//dungeon2 = new Dungeon("demo_dun_2.txt");
   // fill_town("sample_town.txt");
	Scene sc;
	std::string store_filename = "all_items.txt";
	s.fillStore(store_filename); //Change later to work for ANY STORE
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
		<< "5. Go talk to the townspeople" << std::endl
		<< "6. Go to a dungeon" << std::endl
		<< "7. Menu" << std::endl;
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
            else if (choice == 5) {
				system("cls");
                talk();
				system("cls");
				display_options();
            }
            else if (choice == 6) {
				system("cls");
                dungeon_select(p);
				system("cls");
				display_options();
            }
            else if (choice == 7) {
				Scene sc;
				sc.basic_menu(p);
            }
            else if (choice == 0) {
				break;
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

				std::cout << "I can refine your weapon for a price. However, I may fail." << std::endl;
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
					std::cout << "The blacksmiths hammers down your weapon, tempering it with fine skill." << std::endl;
					std::cout << "\"Here you go.\" The blacksmith hands you your weapon, looking better than ever." << std::endl;
					dynamic_cast<Weapon*>(p->inventory_search(wep))->add_dmg((rand() % 10 + 1));
					return;
				}
				else
				{
					std::cout << "The blacksmith clanks your weapon with his hammer, but breaks with his next strike." << std::endl;
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
		std::cout << i << ". " << allies.at(i)->getname() << " , Cost: " << allies.at(i)->getMaxHP()
		<< " , Defense: " << allies.at(i)->getDef() << std::endl;
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
	createAllies(p);

	int input = 0;
    std::cout << "Welcome to the newly built tavern! I'm the innkeeper, how can I help you?\n";
	displayTavernMenu();
	cin >> input; 

	while (input != 2)
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
		if (input == 3)
		{
			std::cout << "Goodbye!\n";
			return;
		}
	}

	std::cout << "There are several people here waiting for you, friend! Choose who you want!\n";
	displayAllies();
	cin >> input;
	while (input != 4)
	{
		if (allies.empty())
		{
			std::cout << "You've got all the allies here! See you later you cheap ass drunk!";
			return;
		}
		while (cin.fail())
		{
			std::cout << "You're drunk aren't you. Try a different input.\n";
			displayAllies();
		}
		if (input < 0 || input > 4)
		{
			std::cout << "Ally does not exist. Try another number.\n";
			displayAllies();
			cin >> input;
		}
		if (input == 0)
		{
			if (p->getmoney() < allies.at(input)->getMaxHP())
			{
				std::cout << "You can't afford the toddler. Why don't you try having your own baby?\n";
				displayAllies();
				cin >> input;
			}
			p->add_member(allies.at(input));
			std::cout << "You have a new ally! This should help you in battle now.\n";
			allies.erase(allies.begin()+input);
			displayAllies();
			cin >> input;
		}
		if (input == 1)
		{
			if (p->getmoney() < allies.at(input)->getMaxHP())
			{
				std::cout << "You don't have enough money.\n";
				displayAllies();
				cin >> input;
			}
			p->add_member(allies.at(input));
			std::cout << "You have a new ally! This should help you in battle now.\n";
			allies.erase(allies.begin() + input);
			displayAllies();
			cin >> input;
		}
		if (input == 2)
		{
			if (p->getmoney() < allies.at(input)->getMaxHP())
			{
				std::cout << "You don't have enough money. *sad neigh* \n";
				cin >> input;
			}
			p->add_member(allies.at(input));
			std::cout << "You have a new ally! This should help you in battle now.\n";
			allies.erase(allies.begin() + input);
			displayAllies();
			cin >> input;
		}
		if (input == 3)
		{
			if (p->getmoney() < allies.at(input)->getMaxHP())
			{
				std::cout << "You don't have enough money.\n";
				displayAllies();
				cin >> input;
			}
			p->add_member(allies.at(input));
			std::cout << "You have a new ally! This should help you in battle now.\n";
			allies.erase(allies.begin() + input);
			displayAllies();
			cin >> input;
		}
	}
    return;
}

void Town::store(player* p) {
    s.run(p);
    return;
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

void Town::dungeon_select(player* p)
{

	string input;
	string dun_ent;
	string map_t;
	string dun;

	std::cout << "Which dungeon would you like to go to?" << std::endl;
	std::cout << "1. Mild Fields" << std::endl;
	std::cout << "2. Kind of Mild Dungeon" << std::endl;
	std::cout << "3. Devil's Lair" << std::endl;
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
				return;
			}
			else if (input == "2")
			{
				return;
			}
			else if (input == "3")
			{
				dun_ent = "demo_dun_1_enemies.txt";
				map_t = "mapsample.txt";
				dun = "demo_dun_1.txt";
				Dungeon* d = new Dungeon(dun);
				d->fill_dungeon(dun_ent, map_t);
				Combat_System cs(p, p->get_party());
				d->run_dungeon(p, cs);
				Scene sc;
				sc.scene_005();
				cs.runBattle(d->get_boss());
				if (p->getHP() < 0)
				{
					sc.scene_006();
					return;
				}
				return;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
	}





	/*FOR DEMO ONLY*/

}

