#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

//Default constructor, probably will never have to use
Combat_System::Combat_System(){
    	turn = 0;
	vector<Ally*> allies;
    	player* play;
}

//Main constructor, saves the player object
Combat_System::Combat_System(player* p){
    	turn = 0;
	vector<Ally*> allies;
    	play = p;
}

Combat_System::Combat_System(player* p, vector<Ally*> ally){
	turn = 0;
	allies = ally;
	play = p;
}

int Combat_System::randNumber(){
    	return rand() % 100 + 1;
}

//True if defending
bool Combat_System::calculateEnemyChoice(Entity* enemy){
    	int x = randNumber();
    	if(enemy->getHealth() > 5){
        	if(x < 90){
            		return false;
        	}
	        else{
	            return true;
	        }
	}
	else{
	        if(x < 75){
	            return false;
	        }
	        else{
	            return true;
	        }
	}
}

bool Combat_System::calculateAllyChoice(Ally* ally){
    	int x = randNumber();
    	if(ally->getHP() > 5){
        	if(x < 90){
            		return false;
        	}
	        else{
	            return true;
	        }
	}
	else{
	        if(x < 75){
	            return false;
	        }
	        else{
	            return true;
	        }
	}
}

int Combat_System::attackChoice(int size){
	return rand() % (size + 1);
}

//Private helper function, asks player what they want to do
//Returns 0, 1, 2 or 3 depending on if they attack, defend, use an item, or run
int Combat_System::promptChoices(){
	int i = -1;
	std::string prompt;
	while(i = -1){
		cout << endl << "Enter the number of the move you want to make: "<< endl;
		cout << "1: Attack" << endl;
		cout << "2: Defend" << endl;
		cout << "3: Use an item" << endl;
		cout << "4: Run" << endl;
		cin >> prompt;
		if(prompt == "1"){
		return 0;
		}
		if(prompt == "2"){
		return 1;
		}
		if(prompt == "3"){
		return 2;
		}
		if(prompt == "4"){
		return 3;
		}
		cout << "You have not selected one of the four options." << endl;
	}
}

int Combat_System::promptEnemyChoice(vector<Entity*> enemies){
	unsigned choice;
	cout << "Which enemy number would you like to attack?: " << endl;
	for(unsigned i = 0; i < enemies.size(); i++){
		cout << "Enemy " << i+1 << ": " << enemies.at(i)->getName();
	}
	cin >> choice;
	if(choice >= 1 || choice <= enemies.size()){
		return choice - 1;
	}
	else{
		cout << "Invalid choice, please try again.";
		promptEnemyChoice(enemies);
	}
}

int Combat_System::calculateDamage(bool defend){
	if(defend){
		return randNumber() / 30;
	}
	else{
		return randNumber() / 10;
	}
}

int Combat_System::calculateTurn(){
	return 0;
}

void Combat_System::runBattle(Entity* e){
	Entity* enemy = new Entity(e);
	int optionChoice;
	bool eChoice = enemy->isDefending();
	turn = calculateTurn();
	cout << endl << "You encounter a wild " << enemy->getName() << "!" << endl;
	while (play->getHP() > 0 && enemy->getHealth() > 0){
		if (turn == 0){
		    play->setDefending(false);
			cout << "It is currently your turn." << endl;
			cout << "You have " << play->getHP() << "/" << play->getMaxHP() << " HP." << endl;
			cout << enemy->getName() << " has " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " HP." << endl;
			optionChoice = promptChoices();
			if (optionChoice == 0){
				if (play->calculateAccuracy(e)){
					int x = play->calculateDamage(*enemy, eChoice);
					if (play->calculateCrit()){
						x *= 1.4;
						cout << "You've hit a crit!" << endl;
					}
					cout << "You've hit the enemy for " << x << " damage!" << endl;
					enemy->setHealth(enemy->getHealth() - x);
				}
				else{
					cout << "You missed!" << endl;
				}
			}
			if (optionChoice == 1){
			    play->setDefending(true);
				cout << "You are now defending." << endl;
			}
			if (optionChoice == 2){
				string input;
				std::cout << "Here are all of the consumables you own." << std::endl;
				//Search for all consumables
				std::cout << "Which item would you like to use? (Type back to return)" << std::endl;
				while (input != "back")
				{
					std::cin.ignore();
					getline(cin, input);
					if (play->con_search(input) == NULL)
					{
						std::cout << "Invalid input. Please type it again." << std::endl;
					}
					else
					{
						play->con_search(input)->usePotion(play);
						play->remove_con(play->con_search(input)->getName());
						std::cout << "Item used!" << std::endl;
						break;
					}
				}
			}
			if (optionChoice == 3){
				int temp = randNumber();
				if(temp > 50){
					cout << "You've successfully ran away!" << endl;
				}
				else{
					cout << "You've failed to run away..." << endl;
					turn = 2;
				}
			}
			if (optionChoice == 2){
				turn = 0;
				cout << "It is still your turn." << endl;
			}
			else{
				turn = 1;
			}
		}
		else if (turn == 1){
			for (unsigned i = 0; i < allies.size(); i++){
			    allies.at(i)->setDefending(false);
				cout << "It is now " << allies.at(i)->getname() << "'s turn." << endl;
				bool decision = calculateAllyChoice(allies.at(i));
				if (!decision){
					if (allies.at(i)->calculateAccuracy(e)){
						int damage = allies.at(i)->calculateDamage(*enemy, eChoice);
						if (allies.at(i)->calculateCrit()){
							damage *= 1.4;
							cout << allies.at(i)->getname() << " has hit a crit!" << endl;
						}
						enemy->setHealth(enemy->getHealth() - damage);
						cout << allies.at(i)->getname() << " has hit the enemy for " << damage << " damage." << endl;
					}
					else{
						cout << allies.at(i)->getname() << " missed the enemy!" << endl;
					}
				}
				else{
					cout << allies.at(i)->getname() << " is defending..." << endl;
					allies.at(i)->setDefending(true);
				}
			}
			turn = 2;
		}
		else if (turn == 2){
			enemy->setDefending(false);
			eChoice = calculateEnemyChoice(enemy);
			cout << "It is now the enemy's turn!" << endl;
			if (!eChoice){
				int x;
				if (allies.size() == 0){
					if (enemy->calculateAccuracy(play)){
						x = enemy->calculateDamage(*play, play->isDefending());
						if (enemy->calculateCrit()){
							x *= 1.4;
							cout << "The enemy has hit a crit!" << endl;
						}
						play->setHP(play->getHP() - x);
						if (optionChoice == 1){
							cout << "You reduced the amount of damage you have taken by defending..." << endl;
							cout << "You've taken " << x << " damage.";
						}
						cout << "You've taken " << x << " damage.";
					}
					else{
						cout << "The enemy has missed!" << endl;
					}
				}
				else{
					int eAttack = attackChoice(allies.size());
					if (eAttack == allies.size() + 1){
						x = enemy->calculateDamage(*play, play->isDefending());
						play->setHP(play->getHP() - x);
						if (play->isDefending()){
							cout << "You reduced the amount of damage you have taken by defending..." << endl;
							cout << "You've taken " << x << " damage.";
						}
						cout << "You've taken " << x << " damage.";
					}
					else{
						x = enemy->calculateDamage(allies.at(eAttack), allies.at(eAttack)->isDefending());
			            allies.at(eAttack)->setHP(allies.at(eAttack)->getHP() - x);
			            if(allies.at(eAttack)->isDefending()){
							cout << allies.at(eAttack) << " has reduced the amount of damage by defending..." << endl;
			            }
					}
				}
			}
			else{
				cout << "The enemy is defending..." << endl;
				enemy->setDefending(true);
			}
			turn = 0;
		}
	}
	if (play->getHP() > 0){
		int EXP = enemy->getEXP();
		if(allies.size() > 0){
			EXP /= allies.size() + 1;
		}
		for(unsigned i = 0; i < allies.size(); i++){
			allies.at(i)->setexp(allies.at(i)->getexp() + EXP);
		}
		play->setmoney(play->getmoney() + enemy->getVal());
		e->give_loot(play);

		cout << "You've won the battle!" << endl;
		cout << "You've gained " << enemy->getEXP() << " EXP and ";
		cout << enemy->getVal() << " gold!\n\n";

		if (play->add_exp(EXP))
		{
			std::cout << "You have leveled up! You are now level " << play->getlevel() << ".\n\n";
		}

		if (!e->empty_loot())
		{
			cout << "Drops: " << endl << endl;
			e->print_loot();
		}
	}
	else{
		cout << "Game Over." << endl;
		return;
	}
}

void Combat_System::runBattle(vector<Entity*> enemy){
	int optionChoice;
	int damage;
	int enemyOptionChoice;
	bool eChoice;
	int battleSize = enemy.size();
	int totalXP = 0;
	int totalGold = 0;
	turn = calculateTurn();
	while (play->getHP() > 0 && enemy.size() > 0){
		if (turn = 0){
			play->setDefending(false);
			cout << endl << "It is currently your turn." << endl;
			cout << "You have " << play->getHP() << "/" << play->getMaxHP() << " HP." << endl;
			for (unsigned i = 0; i < enemy.size(); i++){
				cout << "Enemy" << i << " has " << enemy.at(i)->getHealth() << " / " << enemy.at(i)->getMaxHealth() << " HP." << endl;
			}
			optionChoice = promptChoices();
			if (optionChoice == 0){
				enemyOptionChoice = promptEnemyChoice(enemy);
				if (play->calculateAccuracy(enemy.at(enemyOptionChoice))){
					eChoice = enemy.at(enemyOptionChoice)->isDefending();
					damage = play->calculateDamage(*enemy.at(enemyOptionChoice), eChoice);
					if (play->calculateCrit()){
						damage *= 1.4;
						cout << "You hit a crit!" << endl;
					}
					cout << "You've hit enemy " << enemyOptionChoice + 1 << " for " << damage << " damage!" << endl;
					if (damage > enemy.at(enemyOptionChoice)->getHealth()){
						totalXP += enemy.at(enemyOptionChoice)->getEXP();
						totalGold += enemy.at(enemyOptionChoice)->getVal();
						enemy.erase(enemy.begin() + enemyOptionChoice);
						cout << "You've killed enemy " << eChoice << "!" << endl;
					}
					else{
						enemy.at(enemyOptionChoice)->setHealth(enemy.at(enemyOptionChoice)->getHealth() - damage);
					}
				}
				else{
					cout << "You missed!" << endl;
				}
			}
			if (optionChoice == 1){
				play->setDefending(true);
				cout << "You are now defending." << endl;
			}
			if (optionChoice == 2){
				string input;
				std::cout << "Here are all of the consumables you own." << std::endl;
				//Search for all consumables
				std::cout << "Which item would you like to use? (Type back to return)" << std::endl;
				while (input != "back")
				{
					std::cin.ignore();
					getline(cin, input);
					if (play->con_search(input) == NULL)
					{
						std::cout << "Invalid input. Please type it again." << std::endl;
					}
					else
					{
						play->con_search(input)->usePotion(play);
						play->remove_con(play->con_search(input)->getName());
						std::cout << "Item used!" << std::endl;
						break;
					}
				}
			}
			if (optionChoice == 3){
				int temp = randNumber();
				if(temp > 50){
					cout << "You've successfully ran away!" << endl;
				}
				else{
					cout << "You've failed to run away..." << endl;
					turn = 2;
				}
			}
			if (optionChoice == 2){
				turn = 0;
				cout << "It is still your turn." << endl;
			}
			else{
				turn = 1;
			}
		}
		else if(turn == 1){
			for (unsigned i = 0; i < allies.size(); i++){
				allies.at(i)->setDefending(false);
				cout << "It is now " << allies.at(i)->getname() << "'s turn." << endl;
				bool decision = calculateAllyChoice(allies.at(i));
				if (!decision){
					int attacked = attackChoice(enemy.size());
					if (allies.at(i)->calculateAccuracy(enemy.at(attacked))){
						int damage = allies.at(i)->calculateDamage(*enemy.at(attacked), enemy.at(attacked)->isDefending());
						if (allies.at(i)->calculateCrit()){
							damage *= 1.4;
							cout << allies.at(i)->getname() << " has hit a crit!" << endl;
						}
						enemy.at(attacked)->setHealth(enemy.at(attacked)->getHealth() - damage);
						if (damage > enemy.at(attacked)->getHealth()){
							totalXP += enemy.at(attacked)->getEXP();
							totalGold += enemy.at(attacked)->getVal();
							enemy.erase(enemy.begin() + attacked);
							cout << "Your ally has killed the " << enemy.at(attacked)->getName() << "!" << endl;
						}
						else{
							enemy.at(attacked)->setHealth(enemy.at(attacked)->getHealth() - damage);
							cout << allies.at(i)->getname() << " has hit enemy " << attacked << " for " << damage << " damage." << endl;
						}
					}
					else{
						cout << allies.at(i)->getname() << " has missed!" << endl;
					}
				}
				else{
					cout << allies.at(i)->getname() << " is defending..." << endl;
					allies.at(i)->setDefending(true);
				}
			}
			turn = 2;
		}
		else if(turn == 2){
			for(unsigned i = 0; i < enemy.size(); i++){
				int eAttack = attackChoice(allies.size());
					if (eAttack == allies.size() + 1){
						if (enemy.at(i)->calculateAccuracy(play)){
							int damage = enemy.at(i)->calculateDamage(*play, play->isDefending());
							if (enemy.at(i)->calculateCrit()){
								damage *= 1.4;
								cout << enemy.at(i)->getName() << "has hit a crit!" << endl;
							}
							play->setHP(play->getHP() - damage);
							if (play->isDefending()){
								cout << "You reduced the amount of damage you have taken by defending..." << endl;
							}
						}
						else{
							cout << enemy.at(i)->getName() << "has missed!" << endl;
						}
					}
					else{
						if (enemy.at(i)->calculateAccuracy(allies.at(eAttack))){
							int damage = enemy.at(i)->calculateDamage(allies.at(eAttack), allies.at(eAttack)->isDefending());
							if (enemy.at(i)->calculateCrit()){
								damage *= 1.4;
								cout << enemy.at(i)->getName() << "has hit a crit!" << endl;
							}
							allies.at(eAttack)->setHP(allies.at(eAttack)->getHP() - damage);
							if (allies.at(eAttack)->isDefending()){
								cout << allies.at(eAttack) << " has reduced the amount of damage by defending..." << endl;
							}
						}
						else{
							cout << enemy.at(i)->getName() << " has missed!" << endl;
						}
					}
			}
		}
	}
	if (play->getHP() > 0){
		if(allies.size() > 0){
			totalXP /= allies.size() + 1;
		}
		for(unsigned i = 0; i < allies.size(); i++){
			allies.at(i)->setexp(allies.at(i)->getexp() + totalXP);
		}
		play->setmoney(play->getmoney() + totalGold);
		cout << "You've won the battle!" << endl;
		cout << "You've gained " << totalXP << " EXP!" << endl;
		if (play->add_exp(totalXP))
		{
			std::cout << "You have leveled up! You are now level " << play->getlevel() << ".\n\n";
		}
	}
	else{
		cout << "Game Over." << endl;
	}
}
