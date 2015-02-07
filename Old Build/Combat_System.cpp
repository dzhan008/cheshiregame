#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
#include "Combat_System.h"
#include "player.h"
#include "entity.h"

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

/*int promptEnemyChoice(){
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
*/

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

void Combat_System::runBattle(entity* enem){
    enemy = enem;
    int optionChoice;
    bool eChoice;
    turn = calculateTurn();
    while(play->getHP() > 0 && enemy->getHealth() > 0){
        eChoice = calculateEnemyChoice();
        if(turn == 0){
            cout << endl << "You have " << play->getHP() << "/" << play->getMaxHP() << " HP." << endl;
            cout << "Your enemy has " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " HP." << endl;
            optionChoice = promptChoices();
            if(optionChoice == 0){
                int x = calculateDamage(eChoice);
                cout << "You've hit the enemy for " << x << " damage!" << endl;
                enemy->setHealth(enemy->getHealth() - x);
            }
            if(optionChoice == 1){
                cout << "You are now defending." << endl;
            }
            if(optionChoice == 2){
                //Access inventory
                cout << "This option is not available in the prototype." << endl;
            }
            if(optionChoice == 3){
                //Prompt run away
                cout << "This option is not available in the prototype." << endl;
            }
            if(optionChoice == 2 || optionChoice == 3){
                turn = 0;
                cout << "It is still your turn." << endl;
            }
            else{
                turn = 1;
            }
        }
        else{
            cout << "It is now the enemy's turn!" << endl;
            if(!eChoice){
                int x;
                if(optionChoice == 1){
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
            turn = 0;
        }
    }
    if(play->getHP() > 0){
        play->setexp(play->getexp() + enemy->getEXP());
        cout << "You've won the battle!" << endl;
        cout << "You've gained " << enemy->getEXP() << " EXP!" << endl;
    }
    else{
        cout << "Game Over." << endl;
    }
}

/*void runBattle(vector<Monster> enemy){
    int optionChoice;
    int eChoice;
    int attack;
    int battleSize = enemy.size();
    turn = calculateTurn();
    while(player.getHP() > 0 && enemy.size() > 0){
        if(turn = 0){
            optionChoice = promptChoices();
            if(battleSize > 1){
                promptEnemyChoice();
                //Implement Multi Battle
            }
            else{
                if(optionChoice == 0){
                    
                }
            }
        }
        else{
            if(battleSize > 1){
                for(int i = 0; i < battleSize; i++){
                    
                }
            }
            else{
                
            }
        }
}*/
