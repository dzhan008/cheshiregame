#include "stdafx.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>



//Gotta move these later or fix up menu ugh
Shop demo_shop;
string x = "Player 1";
string y = "Enemy 1";
string line = "--------------------------------------------------------------------------------";
player* play = new player(x, 10, 1, 0, 0);
entity* enemy = new entity(y, 10, 1, 0);
Combat_System battle_demo = Combat_System(play);


using namespace std;

int menu();
string getFileContents (std::ifstream& File)
{
    string Lines = "";        //All lines

    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    string TempLine;                  //Temp line
	    getline (File , TempLine);        //Get temp line
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
    string inputName = "title2.txt";
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

    cout << "                                1. New Game \n";
    cout << "                                2. Load Game \n";
    cout << "                                3. Options \n";
    cout << "                                4. Credits \n";
    int input = 0;
    cin >> input;
    if (input == 1)
    {
        for (int i = 1; i <= 18; i ++)
        {
            cout << endl;
        }

        menu();
    }



    //cout << "Chesire's Game" << endl;
    //cout << "Prototype Version 1.0" << endl;
    //cout << "Welcome to the demo!" << endl;


    return 0;
}

int menu()
{
    int decision = 0;

    while (decision != 4)
    {

        cout << "Please select one of the options below: " << endl;
        cout << "1. Combat Simulation" << endl;
        cout << "2. Shop Simulation" << endl;
        cout << "3. Stats Simulation" << endl;
        cout << "4. Exit" << endl;
        cout << "Input the number for your selection: ";
        cin >> decision;

        if (decision == 1)
        {
            cout << line << endl;
            battle_demo.runBattle(enemy);
        }
        else if (decision == 2)
        {
            cout << line << endl;
            demo_shop.Store();
        }
        else if (decision == 3)
        {
			stats stat_demo; //Make sure that this object is reset or else the vector won't reset
            cout << line << endl;
            stat_demo.statProgression(play);
			play->displayInfo();
        }
        else if (decision == 4)
        {
            cout << "Thanks for playing!" << endl;
			exit(0);
        }
        cout << "The simulation has ended. Returning to main menu..." << endl;
        cout << line << endl;
        menu();
    }


}
