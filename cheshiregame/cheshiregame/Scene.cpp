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
				break;
			case 4:
				option_chosen = true;
				break;
			case 5:
				p->mod_stats();
				option_chosen = true;
				break;
			case 6:
				option_chosen = true;
				return;
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