#include "stdafx.h"

#include <iostream>
#include <vector>


// Output choices given from place
// Starts from 1 to sz - 1;
void Scene::output_options() {
    for (unsigned i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " <<  options.at(i) << std::endl;
    }
}

// Sets options to scene
void Scene::set_options(Town &t) {
    //options = t.get_options();
}

void Scene::basic_menu(player* p)
{
	int choice = 0;

	while (choice != 7)
	{
		std::string input;
		bool option_chosen = false;

		std::cout << "What would you like to do?" << std::endl << std::endl;
		std::cout << "1. View Party" << std::endl;
		std::cout << "2. View Items" << std::endl;
		std::cout << "3. Use Item" << std::endl;
		std::cout << "4. Equip" << std::endl;
		std::cout << "5. View Stats" << std::endl;
		std::cout << "6. Save" << std::endl;
		std::cout << "7. Exit" << std::endl;

		while (!option_chosen)
		{
			std::cin >> choice;

			switch (choice)
			{
			case 1:
				std::cout << "Not implemented." << std::endl;
				option_chosen = true;
				break;
			case 2:
				p->display_inventory();
				option_chosen = true;
				break;
			case 3:
				option_chosen = true;
				std::cout << "Here are all of the consumables you own." << std::endl;
				//Search for all consumables
				std::cout << "Which one would you like to use?" << std::endl;
				std::cin.ignore();
				getline(cin, input);
				//if(Input is actually a potion)
				std::cout << "Who would you like to use this on?" << std::endl;
				//if(you wanna heal yourself)
				//heal yourself
				//else if(you wanna heal your party members)
				//heal them
				//Prompt if you're sure if you want to use it?
				//USE IT (call respective functions for usage)
				break;
			case 4:
				option_chosen = true;
				p->display_equipment();
				std::cout << "Which type of gear would you like to equip? (Type back to return.)" << std::endl;
				while (input != "back")
				{
					int slot = -1;
					std::cin.ignore();
					getline(cin, input);

					if (input == "back")
					{
						break;
					}
					else if (p->find_slot(input) == -1)
					{
						std::cout << "Invalid input. Please type it in again." << std::endl;
					}
					else
					{
						slot = p->find_slot(input);
						std::cout << std::endl;
						//When implemented, add in the function to search for all the equipment of said type and cout it
						//I think we need a type ID for equipment.
						std::cout << "Which item would you like to equip?" << std::endl;
						//options: 1.store each name of type of gear in player's inventory into a vector
						//		   2.somehow find a way to check if the item's type ID is the same as slot
						do
						{
							std::cin >> input;
							if (p->inventory_search(input)->getSlot() == slot) //This should pass in slot_type
							{
								p->equip_slot(slot, p->inventory_search(input));
							}
							else
							{
								std::cout << "Invalid input." << std::endl;
							}
						} while (p->inventory_search(input)->getSlot == slot);
					}
				}
				
				//Current equipped items:
				//DISPLAY EQUIPMENT HERE
				//Select the number you would like to equip.
				//Display the type of gear that is in your inventory
				//Prompt what to wear
				//Wear item/replace item that took the slot
				//Profit
				break;
			case 5:
				p->mod_stats();
				option_chosen = true;
				break;
			case 6:
				option_chosen = true;
				break;
			case 7:
				option_chosen = true;
				return;
				break;
			default:
				std::cout << "Invalid choice. Please input your choice again." << std::endl << std::endl;
				break;
			}
		}
	}
}


// Gets user input, may be unnecessary
int user_input() {
    int i;
    std::cout << "> ";
    std::cin >> i;
    return i;
}

/*Scenario to replace instead of this:
You wake up dazed, seeing only blurriness around you.
Your head is throbbing, and your mind is fogged.
You sit up slowly, trying to recollect yourself.
You can't seem to remember much. It is as if your mind
become a blank slate. You try to remember your name:
(after player enters name)
Well at least you did not forget who you were. You turn
around to look at your surroundings. Beside you lies:
1. A rusted sword.
2. A dull dagger.
3. A wooden staff.
(depending on the choice, there will be something said about the player's job)
-You pick up the item and realize you're in the middle of the forest. You then
try to find your way to town.*/

void Scene::scene_001()
{
	std::cout << "You wake up dazed, seeing only blurriness around you." << std::endl;
	std::cout << "" << std::endl;
}