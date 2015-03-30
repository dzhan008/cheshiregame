#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <vector>


using namespace std;

//Default constructor, probably will never have to use
Combat_System::Combat_System(){
    turn = 0;
    //vector<entity> enemies;
    entity enemy;
    player play;
}

//Main constructor, saves the player object
Combat_System::Combat_System(player* p){
    turn = 0;
    //vector<entity> enemies;
    entity enemy;
    play = p;
}

int Combat_System::randNumber(){
    return rand() % 100 + 1;
}

//True if defending
bool Combat_System::calculateEnemyChoice(){
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

//Private helper function, asks player what they want to do
//Returns 0, 1, 2 or 3 depending on if they attack, defend, use an item, or run
int Combat_System::promptChoices(){
    int i = -1;
    int prompt;
    while(i = -1){
        cout << endl << "Enter the number of the move you want to make: "<< endl;
        cout << "1: Attack" << endl;
        cout << "2: Defend" << endl;
        cout << "3: Use an item" << endl;
        cout << "4: Run" << endl;
        cin >> prompt;
        if(prompt == 1){
            return 0;
        }
        if(prompt == 2){
            return 1;
        }
        if(prompt == 3){
            return 2;
        }
        if(prompt == 4){
            return 3;
        }
        cout << "You have not selected one of the four options." << endl;
    }
}

int promptEnemyChoice(){
    int choice;
    cout << "Which enemy number would you like to attack?: " << endl;
    for(int i = 0; i < enemies.size(); i++){
        cout << "Enemy " << i+1 << ": " << enemies.at(i).getName();
    }
    cin >> choice;
    if(choice >= 1 || choice <= enemies.size()){
        return choice - 1;
    }
    else{
        cout << "Invalid choice, please try again.";
        promptEnemyChoice();
    }
}

double Combat_System::calculateAccuracy(){
    return 0;
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

void Combat_System::runBattle(Entity* enemy){
	int optionChoice;
	bool eChoice = enemy->isDefending();
	turn = calculateTurn();
	while (play->getHP() > 0 && enemy->getHealth() > 0){
		if (turn == 0){
		    	play->setDefending(false);
			cout << endl << "It is currently your turn." << endl;
			cout << "You have " << play->getHP() << "/" << play->getMaxHP() << " HP." << endl;
			cout << "Your enemy has " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " HP." << endl;
			optionChoice = promptChoices();
			if (optionChoice == 0){
				int x = play->calculateDamage(*enemy, eChoice);
				cout << "You've hit the enemy for " << x << " damage!" << endl;
				enemy->setHealth(enemy->getHealth() - x);
			}
			if (optionChoice == 1){
			    play->setDefending(true);
				cout << "You are now defending." << endl;
			}
			if (optionChoice == 2){
				//Access inventory
				cout << "This option is not available in the prototype." << endl;
			}
			if (optionChoice == 3){
				//Prompt run away
				cout << "This option is not available in the prototype." << endl;
			}
			if (optionChoice == 2 || optionChoice == 3){
				turn = 0;
				cout << "It is still your turn." << endl;
			}
			else{
				turn = 1;
			}
		}
		else if (turn == 1){
			for (int i = 0; i < allies.size(); i++){
			    allies.at(i)->setDefending(false);
				cout << "It is now " << allies.at(i)->getname() << "'s turn." << endl;
				bool decision = calculateAllyChoice(allies.at(i));
				if (!decision){
					int damage = allies.at(i)->calculateDamage(*enemy, eChoice);
					enemy->setHealth(enemy->getHealth() - damage);
					cout << allies.at(i)->getname() << " has hit the enemy for " << damage << " damage." << endl;
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
					x = enemy->calculateDamage(*play, play->isDefending());
					play->setHP(play->getHP() - x);
					if (optionChoice == 1){
						cout << "You reduced the amount of damage you have taken by defending..." << endl;
					}
				}
				else{
					int eAttack = attackChoice();
					if (eAttack == allies.size() + 1){
						x = enemy->calculateDamage(*play, play->isDefending());
						play->setHP(play->getHP() - x);
						if (play->isDefending()){
							cout << "You reduced the amount of damage you have taken by defending..." << endl;
						}
					}
					else{
			                        x = enemy->calculateDamage(allies.at(eAttack), allies.at(eAttack)->isDefending());
			                        allies.at(eAttack)->setHP(allies->getHP() - x);
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
		play->setexp(play->getexp() + enemy->getEXP());
		cout << "You've won the battle!" << endl;
		cout << "You've gained " << enemy->getEXP() << " EXP!" << endl;
	}
	else{
		cout << "Game Over." << endl;
	}
}

void Combat_System::runBattle(vector<Entity*> enemy){
	int optionChoice;
	int damage;
	int enemyOptionChoice;
	bool eChoice;
	int attack;
	int battleSize = enemy.size();
	turn = calculateTurn();
	while (play->getHP() > 0 && enemy.size() > 0){
		if (turn = 0){
			play->setDefending(false);
			cout << endl << "It is currently your turn." << endl;
			cout << "You have " << play->getHP() << "/" << play->getMaxHP() << " HP." << endl;
			cout << "Your enemy has " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " HP." << endl;
			optionChoice = promptChoices();
			if (optionChoice == 0){
				enemyOptionChoice = promptEnemyChoice(enemy);
				eChoice = enemy.at(enemyOptionChoice)->isDefending();
				damage = play->calculateDamage(enemy.at(enemyOptionChoice), eChoice);
				cout << "You've hit enemy " << enemyOptionChoice + 1 << " for " << damage << " damage!" << endl;
				if (x > enemy.at(enemyOptionChoice)->getHealth()){
					enemy.erase(enemy.begin() + enemyOptionChoice);
					cout << "You've killed enemy " << eChoice << "!" << endl;
				}
				else{
					enemy.at(enemyOptionChoice)->setHealth(enemy.at(enemyOptionChoice)->getHealth() - damage);
				}
			}
			if (optionChoice == 1){
				play->setDefending(true);
				cout << "You are now defending." << endl;
			}
			if (optionChoice == 2){
				//Access inventory
				cout << "This option is not available in the prototype." << endl;
			}
			if (optionChoice == 3){
				int x = randNumber();
				if(x > 50){
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
			for (int i = 0; i < allies.size(); i++){
			    allies.at(i)->setDefending(false);
				cout << "It is now " << allies.at(i)->getname() << "'s turn." << endl;
				bool decision = calculateAllyChoice(allies.at(i));
				if (!decision){
					int damage = allies.at(i)->calculateDamage(*enemy, eChoice);
					enemy->setHealth(enemy->getHealth() - damage);
					cout << allies.at(i)->getname() << " has hit the enemy for " << damage << " damage." << endl;
				}
				else{
					cout << allies.at(i)->getname() << " is defending..." << endl;
					allies.at(i)->setDefending(true);
				}
			}
			turn = 2;
		}
		else if(turn == 2){
			for (int i = 0; i < battleSize; i++){
				if (i != enemyOptionChoice){
					eChoice = calculateEnemyChoice(enemy.at(enemyOptionChoice));
					if (!eChoice){
						int x;
						if (optionChoice == 1){
							x = calculateDamage(true);
							play->setHP(play->getHP() - x);
							cout << "The enemy has hit you for " << x << " damage!" << endl;
							cout << "You reduced the amount of damage you have taken by defending..." << endl;
						}
						else{
							x = calculateDamage(false);
							play->setHP(play->getHP() - x);
							cout << "The enemy has hit you for " << x << " damage!" << endl;
						}
					}
					else{
						cout << "The enemy is defending..." << endl;
					}
				}
			}
		}
	}
}
