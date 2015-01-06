#include <iostream>
#include <vector>
#include "player.h"
#include "demo.h"

using namespace std;

void menu();



int main()
{

    cout << "Chesire's Game" << endl;
    cout << "Prototype Version 1.0" << endl;
    cout << "Welcome to the demo!" << endl;
    menu();

    return 0;
}

void menu()
{
    int choice = 0;

    while (choice != 4)
    {
        demo player;
        cout << "Please select one of the options below: " << endl;
        cout << "1. Combat Simulation" << endl;
        cout << "2. Shop Simulation" << endl;
        cout << "3. Stats Simulation" << endl;
        cout << "4. Exit" << endl;
        cout << "Input the number for your selection: ";
        cin >> choice;
        if (choice == 1)
        {
            choice = 4;
        }
        else if (choice == 2)
        {
            choice = 4;
        }
        else if (choice == 3)
        {
            player.statprogression();
            choice = 4;
        }
        else if (choice == 4)
        {
            cout << "Thanks for playing! See you next time!";
        }
    }

}
