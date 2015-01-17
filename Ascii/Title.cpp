#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

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
void title()
{
    string inputName = "title2.txt";
    //cout << "Enter name of input file: ";
    //cin >> inputName;
    cout << endl;
    //cout << "Enter name of output

    ifstream file;
    file.open(inputName.c_str());

    //ofstream fout(outputName.c_st
    if (!file.is_open())
    {
        cout << "Error opening " << inputName << endl;
        //return 1;
    }
    string Art = getFileContents(file);
    cout << Art << endl;

    cout << "                                1. New Game \n";
    cout << "                                2. Load Game \n";
    cout << "                                3. Options \n";
    cout << "                                4. Credits \n";

    //if (!fout.is_open())
    //{
    //    cout << "Error opening " << outputName << endl;
    //    exit(0);
    //}
}

