#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <map>

using namespace std;

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


/*Relevant Output Functions*/
void Scene::next_input()
{
	std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
	_getch();
}

void Scene::output_file(std::string file_name)
{
	std::map<int, std::string> choices;
	std::string output_string;
	std::string choice_file;
	std::string output_f = "Assets/Scenes/" + file_name;
	int ID;
	int input = -1;

	fstream inFile;
	inFile.open(output_f.c_str());
	if (!inFile.is_open())
	{
		std::cout << "Error: File cannot be opened." << std::endl;
		return;
	}
	while (output_string != "<choices>" && inFile.good())
	{
		std::getline(inFile, output_string);
		if (output_string != "<choices>")
		{
			std::cout << output_string << std::endl;
		}
	}
	if (!inFile.good()) //If we reached the end of the file, just return.
	{
		return;
	}
	std::cin.ignore();
	while (inFile.good())
	{
		inFile >> ID >> choice_file;
		choices[ID] = choice_file;
	}
	if (choices.find(2) == choices.end()) //In the instance of only having one choice, we know that the 2nd ID is non-existent.
	{
		system("cls");
		output_file(choices[1]);
		return;
	}
	while (choices.find(input) == choices.end())
	{
		std::cin >> input;
		if (choices.find(input) != choices.end())
		{
			system("cls");
			output_file(choices[input]);
			return;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	
	//Push choices into maps
	//Prompt user for choice
	//Run function again based on ID
	return;
}


/*END RELEVEANT OUTPUT FUNCTIONS*/

void Scene::basic_menu(player* p)
{
	int choice = 0;

	while (choice != 9)
	{
		std::string input;
		bool option_chosen = false;
		std::cout << "\nWhat would you like to do?" << std::endl << std::endl;
		std::cout << "1. View Party" << std::endl;
		std::cout << "2. View Items" << std::endl;
		std::cout << "3. View Equipment" << std::endl;
		std::cout << "4. Use Item" << std::endl;
		std::cout << "5. Equip" << std::endl;
		std::cout << "6. View Stats" << std::endl;
		std::cout << "7. Save" << std::endl;
		std::cout << "8. Exit" << std::endl;
		std::cout << "9. Exit Game" << std::endl;

		while (!option_chosen)
		{
			std::cin >> choice;
			bool gear = true;
			system("cls");
			switch (choice)
			{
			case 1:
				p->displayInfo();
				option_chosen = true;
				break;
			case 2:
				p->display_inventory();
				option_chosen = true;
				break;
			case 3:
				option_chosen = true;
				p->display_equipment();
				break;
			case 4:
				option_chosen = true;
				std::cout << "Here are all of the consumables you own." << std::endl;
				p->display_con_inventory();
				std::cout << "Which item would you like to use? (Type back to return)" << std::endl;
				std::cin.ignore();
				while (input != "back")
				{
					std::getline(cin, input);
					if (input == "back" || input == "b")
					{
						break;
					}
					if (p->con_search(input) == NULL)
					{
							std::cout << "Invalid input. Please type it again." << std::endl;
					}
					else
					{
						p->con_search(input)->usePotion(p);
						p->remove_con(p->con_search(input)->getName());
						std::cout << "Item used!" << std::endl;
						break;
					}
				}

				//std::cout << "Who would you like to use this on?" << std::endl;
				//if(you wanna heal yourself)
				//heal yourself
				//else if(you wanna heal your party members)
				//heal them
				//Prompt if you're sure if you want to use it?
				//USE IT (call respective functions for usage)

				/*Demo Method
				1. Prompt the user to type out the name of consumable
				2. Search for it using inventory_search. If it returns a value,
				3. Do a check to see if its a consumable. How? Maybe a bool for item.
				Note: Needs a better way to do it.
				4. Check succeeded? Then heal the player.*/



				break;
			case 5:
				option_chosen = true;
				/*Demo Method
				1. Ask the user what item they want to equip
				2. Search for item using inventory_search
				3. If it returns a value, use equip_slot, where slot is the slot no. of your gear.
				4. EQUIP SUCCESSFUL SIMPLICITY FTW*/
				std::cout << "Would you like to equip a gear or weapon? (Type back to return)" << std::endl;

				while (input != "back")
				{
					std::cin >> input;
					if (input == "Weapon" || input == "weapon")
					{
						gear = false;
						input = "back";
					}
					else if (input == "Gear" || input == "gear")
					{
						gear = true;
						input = "back";
					}
					else
					{
						std::cout << "Invalid input. Please type it again." << std::endl;
					}

				}
				std::cout << "Which item would you like to equip? (Type back to return)" << std::endl;
				std::cin.ignore();
				do
				{
					std::getline(std::cin, input);
					if (gear)
					{
						if (p->gear_search(input) == NULL)
						{
							std::cout << "Invalid input. Please type it again." << std::endl;
						}
						else
						{
							p->gear_search(input)->equipGear(p->gear_search(input), p);
							std::cout << "Gear equipped!" << std::endl;
							break;
						}
					}
					else
					{
						if (p->wep_search(input) == NULL)
						{
							std::cout << "Invalid input. Please type it again." << std::endl;
						}
						else
						{
							p->wep_search(input)->equipWeapon(p->wep_search(input), p);
							std::cout << "Weapon equipped!" << std::endl;
							break;
						}
					}
				} while (input != "back");
				//Current equipped items:
				//DISPLAY EQUIPMENT HERE
				//Select the number you would like to equip.
				//Display the type of gear that is in your inventory
				//Prompt what to wear
				//Wear item/replace item that took the slot
				//Profit

				/*p->display_equipment();
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
				}*/
				break;
			case 6:
				option_chosen = true;
				std::cin.ignore(); //Clear buffer for other inputs;
				p->mod_stats();
				break;
			case 7:
				option_chosen = true;
				break;
			case 8:
				option_chosen = true;
				system("cls");
				return;
				break;
			case 9:
				option_chosen = true;
				std::cout << "Are you sure?" << std::endl;
				std::cout << "1. Yes" << std::endl;
				std::cout << "2. No" << std::endl;

				while (choice != 1)
				{
					std::cin >> choice;
					if (choice == 1)
					{
						exit(1);
					}
					if (choice == 2)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						break;
					}
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}

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

void Scene::scene_001(player* p)
{
	std::string name;
	int job = -1;

	std::cout << "You wake up dazed, seeing only blurriness around you." << std::endl;
	std::cout << "Your head is throbbing, and your mind is fogged." << std::endl;
	std::cout << "You sit up slowly, trying to recollect yourself." << std::endl;
	std::cout << "You can't seem to remember much. It is as if your mind" << std::endl;
	std::cout << "became a blank slate. You try to remember your name: ";
	std::cin >> name;
	std::cout << std::endl;
	p->setname(name);
	std::cout << "Well at least you did not forget who you were. You turn" << std::endl;
	std::cout << "around to look at your surroundings. Aside from some trees" << std::endl;
	std::cout << "and grass, something to your side catches your eye. It is:" << std::endl;
	std::cout << "1. A rusted sword." << std::endl;
	std::cout << "2. A dull dagger." << std::endl;
	std::cout << "3. A wooden staff." << std::endl;
	while (job != 1 && job != 2 && job != 3)
	{
		std::cin >> job;
		if (job == 1)
		{
			p->setjob("Swordsman");
			std::cout << "You pick up a sword that has been aged for quiet a while." << std::endl;
			std::cout << "There was no trouble holding it. In fact, it seems that you" << std::endl;
			std::cout << "have wielded one of these before." << std::endl;
			Weapon* Sword = new Weapon("Sword", "Weapon", 10, 10);
			p->equip_wep(0, Sword);
		}
		else if (job == 2)
		{
			p->setjob("Thief");
			std::cout << "You grab the dagger on the ground, examining every bit of it." << std::endl;
			std::cout << "While it may not do much, you know that it can land a kill with" << std::endl;
			std::cout << "the right strike." << std::endl;
			Weapon* Dagger = new Weapon("Dagger", "Weapon", 5, 8);
			p->equip_wep(0, Dagger);
		}
		else if (job == 3)
		{
			p->setjob("Magician");
			std::cout << "The wooden staff was light when you took it from the ground. It" << std::endl;
			std::cout << "seems to be at best good for defending, but you can sense a magical" << std::endl;
			std::cout << "presence within it." << std::endl;
			Weapon* Staff = new Weapon("Staff", "Weapon", 2, 5);
			p->equip_wep(0, Staff);
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

	}

	std::cout << "As you stand up, you hear a rustling in a bush just nearby you. " << std::endl;
	std::cout << " You look to your right and realize that a fox is pouncing at you!" << std::endl;
	std::cout << line << std::endl;
	//Initiate battle with fox
}

void Scene::scene_003(player* p)
{
	int input = 0;
	system("cls");
	std::cout << "You slay the fox whether by sheer luck or skill. There seems to be nothing " << std::endl;
	std::cout << "else around the area, so you decide to leave the forest and look for a nearby town. " << std::endl;

	std::cout << "You exit the forest and see an open trail. Since the road is the only lead " << std::endl;
	std::cout << "to what may be civilization, you follow the trail all the way to the end." << std::endl;
	std::cout << " stood a city that was like your typical first - level RPG town." << std::endl << std::endl;
	std::cout << "There was a problem though. The town was quiet. Too quiet. You walk through the entrance," << std::endl;
	std::cout << " there was no one within your view.The town seemed to be devoid of life itself.\n\n";
	std::cout << "You approach a house and find that its door is open. What do you do?\n\n";
	
	std::cout << "1.Go inside and loot the house." << std::endl;
	std::cout << "2.Yell at the house. There has to be someone in there." << std::endl;
	std::cout << "3.Leave the house and head to the town square." << std::endl;



	while (cin.fail())
	{
		std::cin >> input;
		if (input == 1)
		{
			system("cls");
			scene_003_1(p);
			return;
		}
		else if (input == 2)
		{
			system("cls");
			scene_003_2(p);
			return;
		}
		else if (input == 3)
		{
			system("cls");
			scene_003_3(p);
			return;
		}
		else if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
}

void Scene::scene_003_1(player* p)
{

	std::cout << "Having no moral bounds, you walk into the house. You" <<
		" search every nook and cranny of the place, but ";
	std::cout << "to your dismay did not find anything of interest.You did find some gold though.\n";
	std::cout << "You gained 100 gold!\n\n";
	p->setmoney(p->getmoney() + 100);
	std::cout << "As you loot the house, a voice beckons to you." << std::endl;
	std::cout << "\"Hello!\"" << std::endl;

	scene_003_4(p);
	return;
	
}

void Scene::scene_003_2(player* p)
{
	std::cout << "You yell into the house, but there is no response. You decide to holler once more, in hopes that a" << std::endl;
	std::cout << "person may come out.  \"Try again, maybe you might find someone in there.\"\n\n";
	scene_003_4(p);
	return;
}

void Scene::scene_003_3(player* p)
{
	std::cout << "You decide the house was not worth checking out, and head" << std::endl;
	std::cout << " to the town square.The middle of the city was just as empty as the place" << std::endl;
	std::cout << " you visited earlier.The only difference between the two was the fountain that" << std::endl;
	std::cout << " flowed water onto its base.Before you walk up to the fountain, a voice beckons you." << std::endl;
	std::cout << "\"Hello!\"" << std::endl;
	scene_003_4(p);
	return;
}

void Scene::scene_003_4(player* p)
{
	int input = 0;

	std::cout << "You turn around to find a man standing right behind you. He doesn't seem ";
	std::cout << " dangerous, but is" << std::endl << "strangely close to you.The man sports a jester mask that " 
		<< " covers his face. The smiling engraving " << std::endl << "on the mask complements his cheerful tone. Startled, you:\n\n";

	std::cout << "1. Attack the man with your weapon!" << std::endl;
	std::cout << "2. Ask, \"Who are you?\"" << std::endl;
	std::cout << "3. Ask, \"Where can I get a mask like that?\"" << std::endl;


	while (input != 1 || input != 2 || input != 3)
	{
		std::cin >> input;
		if (input == 1)
		{
			system("cls");
			scene_003_4_1(p);
			return;
		}
		else if (input == 2)
		{
			system("cls");
			scene_003_4_2();
			return;
		}
		else if (input == 3)
		{
			system("cls");
			scene_003_4_3();
			return;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

void Scene::scene_003_4_1(player* p)
{
	std::cout << "You take your weapon and hit him with sheer force. The man " << std::endl;
	std::cout << " shocked, but was not able to recover from your flurry of hits." << std::endl;
	std::cout << "After your tenth strike, the man is dead.You take his mask off because why not? \n\n";
	Gear* mask = new Gear("Jester Mask", 50, "Helmet", 20);
	p->add_gear(mask);
	next_input();
	scene_004(true);
	return;
}

void Scene::scene_003_4_2()
{
	std::cout << "\"The town guide!\" the man says cheerfully. \"The name's Astuce.\" " << std::endl;
	std::cout << " holds out his hand. \"Nice to meet you.\"\n\n";
	next_input();
	scene_004(false);
	return;
}

void Scene::scene_003_4_3()
{
	std::cout << "\"I may be able to give you one if you do me a favor.\" " << std::endl;
	std::cout << "He holds out his hand. \"I'm Astuce. Nice to meet you.\"\n\n";
	next_input();
	scene_004(false);
	return;
}

void Scene::scene_004(bool dead)
{
	int input = 0;
	system("cls");

	if (dead)
	{
		astuce_alive = false;

		std::cout << "Upon taking the man's mask, you search for his belongings. You come across a note. It reads: \n" << std::endl;

		std::cout << "\"Okay, I'm going to level with you. I did not expect you to actually" << std::endl;
		std::cout << "KILL Astuce, the town guide, this fast. I mean, he probably has some" << std::endl;
		std::cout << "significant role in the game, but now you'll never know because he's dead.\n" << std::endl;
		std::cout << "Did you know how much time I spent to actually create this character? " << std::endl;
		std::cout << "3 hours. All the time that was spent in making one person that was " << std::endl;
		std::cout << "supposed to make you feel like you're not alone was wasted upon his\n\n";
		std::cout << "death. Thanks. Really. So now that he's dead, you have to read through " << std::endl;
		std::cout << "all the crap I have to tell you right now.You're in a town (bet you " << std::endl;
		std::cout << "figured that out when you walked in right?), and there's going to be" << std::endl;
		std::cout << " some menu that pops up where you can interact with certain things here. \n\n";
		std::cout << "You can go through a dungeon, visit the shop, go to some inn, I don't know. " << std::endl;
		std::cout << " do what you want, because there's not much you could do without a damn" << std::endl;
		std::cout << "guide to tell you what you can or can't do. \n\n" << std::endl;
		std::cout << "-Game Creator\"\n\n";

		std::cout << "Game Creator? You ponder as you wonder whether or not some god or an angry programmer sent you this." 
			<< "What's a programmer anyway? You shrug off this thought, and decide to see what you could do in town.\n\n";
		
		next_input();
		return;
		//Open town options 
	}
	else
	{
		astuce_alive = true;
		std::cout << "You shake his hand. \"How do you like this place? Pretty nice, don't you think?\" Astuce walks around, looking at the barren city.\n\n";

		std::cout << "1. \"Uhh, there's nothing to see here. Where is everyone?\"" << std::endl;
		std::cout << "2. \"This place is fantastic! Look at all the houses and buildings that I can go in and out of!\"" << std::endl;
		while (input != 1 || input != 2)
		{
			std::cin >> input;
			if (input == 1)
			{
				system("cls");
				scene_004_1();
				return;
			}
			if (input == 2)
			{
				system("cls");
				scene_004_2();
				return;
			}
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
}

void Scene::scene_004_1()
{
	int input = 0;

	std::cout << "Astuce stares intently at you. With his mask on, you can't tell what he is thinking. He quickly \nturns his head away. \"There is a certain...incident that happened. You probably won't believe me if I told you this.\" \n\n ";
	std::cout << "He looks at you again. \"Aliens!\" \n\n";

	std::cout << "1. \"Alie- what?\"" << std::endl;
	std::cout << "2. \"NO.\"" << std::endl;
	

	while (input != 1 || input != 2)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "\"Aliens. They came over and abducted the people of our town. Every one of them. I wasn't there when this happened, but I know I saw the spaceship flying towards the city while I was heading back. I \n was planning on creating a device that can teleport me to the ship, but I am missing something.\"\n\n";
			next_input();
			system("cls");
			scene_004_3();
			return;
		}
		else if (input == 2)
		{
			std::cout << "\"YES!\" Astuce sighs. \"They abducted everyone in this town. I wasn't there at the time, but I saw a \n spaceship flying towards the city when I was heading back. I wanted to create a device that can \n teleport me to their ship, but I am missing something.\"\n\n";
			next_input();
			system("cls");
			scene_004_3();
			return;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}
void Scene::scene_004_2()
{
	int input = 0;

	std::cout << "\"I know right? If only there were some people who thought the same way.\" He looks at you. \"Hey, do \n you think you can help me out with something?\"\n\n";

	std::cout << "1.\"Sure, what is it?\"" << std::endl;
	std::cout << "2. \"Actually, I'm in a bit of bind right now.\"" << std::endl;


	while (input != 1 || input != 2)
	{
		std::cin >> input;
		if (input == 1)
		{
			std::cout << "\"That was easier than I thought,\" mumbled the jester. Astuce suddenly looks at you and laughs. \"Ah, sorry about that. I just remembered a joke I heard earlier today.\"\n\n";
			next_input();
			system("cls");
			scene_004_3();
			return;
		}
		else if (input == 2)
		{
			std::cout << "\"Lost your memory right? Not to worry, but I believe you can help us both out if you listen to my \n request.\" You look puzzled. How did he know that you lost your memory? Instead of bringing this up to Astuce, you continue to hear what he has to say. \n\n";
			next_input();
			system("cls");
			scene_004_3();
			return;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

void Scene::scene_004_3()
{
	std::cout << "\"I need you to get me a red gem inside of a dungeon. The dungeon is not too far away, but it is \n guarded by a giant monster, the Rica. I would love to go myself, but I must stay in case other \n people come into the town.\"\n\n";
	std::cout << "\"You can utilize the town itself to purchase items or sleep at the inn to heal yourself. If you feel like the Rica is too tough of a boss for you, try training in the fields outside of this city. I \n wish you luck!\"\n\n";
	next_input();
	return;
}

void Scene::scene_005()
{
	system("cls");
	std::cout << "At the end dungeon you come across a huge room. A podium stands in the middle of it. Before you walk up to grab it, something comes out from the sky! A big scaly figure drops in front of the podium \n and glares at you with its red eyes." << std::endl;
	std::cout << "Its screech fills the room, causing you to stagger. While you recover, the Rica pounces after you!" << std::endl;
}

void Scene::scene_006()
{
	int choice = 0;

	std::cout << "At the final blow, the Rica falls. It tries to stand back up, but tumbles back down at its failed \n attempt. The Rica's red eyes turn dull, and it stops breathing. With a sigh of relief, you move up the podium to take the gem. \n\n";
	if (!astuce_alive)
	{
		std::cout << "You head back to town and find a note posted on one of the houses. You take it and give it a read:" << std::endl;
		std::cout << "\"I assume you got the red gem, otherwise you wouldn't be seeing this. Good job, I guess. The demo is pretty much done from here so I hope you enjoyed every bit of it." << std::endl;
		std::cout << "-Game Creator\"" << std::endl;
	}
	else
	{
		std::cout << "You head back to town and find Astuce near the entrance. He crouches over a patch of flowers and \n plucks one off of its stem. \"Ah, look at you! You just may be the right one for what I've got in \n store for you.\"\n\n";
		std::cout << "He turns to you and stares at the gem. \"So you return safely! Congratulations!\" You hand the jester the gem, and he pockets it into his pouch.\n\n";
		std::cout << "\"You've done a good job my friend. You might be wondering what will happen next. Can you guess?\"\n\n";
		std::cout << "1. What?" << std::endl;
			std::cin >> choice;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		std::cout << "\"Well...\" Astuce begins to say some words, but you cannot hear him at all. You try to say something, but you can't hear your own words at all. Then, everything turns black. \n\n"
			<< "Something pops up on your screen. It reads:" << std::endl
			<< "'Your time has run out. Thank you for playing the demo!' \n\n"
			<< "You look in dismay as you realize the demo is finished. \n You then stare the presenters asking, 'What now?'";
		std::cin >> choice;
		exit(1);
	}
}