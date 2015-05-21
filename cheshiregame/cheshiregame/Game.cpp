#include "stdafx.h"

#include <iostream>
#include <fstream>

Game::Game()
{}

Game::Game(std::string file_name)
{
	fstream inFile;
	std::string name;
	std::string type;
	double ex_dmg;
	double acc;
	int min_dmg;
	int max_dmg;
	int mp;
	std::string  skill_file = "Assets/Skills/" + file_name;
	inFile.open(skill_file.c_str());
	if (!inFile.is_open())
	{
		std::cout << "File cannot be opened.";
	}

	while (inFile.good())
	{
		getline(inFile, name);
		inFile >> type;
		if (type == "P_Damage")
		{
			inFile >> ex_dmg >> acc >> mp;
			Skill temp(name, type, ex_dmg, acc, mp);
			skills.push_back(temp);
		}
		else if (type == "D_Damage" || type == "Heal")
		{
			inFile >> min_dmg >> max_dmg >> acc >> mp;
			Skill temp(name, type, min_dmg, max_dmg, acc, mp);
			skills.push_back(temp);
		}
		inFile.ignore();
	}
}

void Game::fill_skills(std::string file_name)
{
	fstream inFile;
	std::string name;
	std::string type;
	double ex_dmg;
	double acc;
	int min_dmg;
	int max_dmg;
	int mp;
	std::string  skill_file = "Assets/Skills/" + file_name;
	inFile.open(skill_file.c_str());
	if (!inFile.is_open())
	{
		std::cout << "File cannot be opened.";
	}

	while (inFile.good())
	{
		getline(inFile, name);
		inFile >> type;
		if (type == "P_Damage")
		{
			inFile >> ex_dmg >> acc >> mp;
			Skill temp(name, type, ex_dmg, acc, mp);
			skills.push_back(temp);
		}
		else if (type == "D_Damage" || type == "Heal")
		{
			inFile >> min_dmg >> max_dmg >> acc >> mp;
			Skill temp(name, type, min_dmg, max_dmg, acc, mp);
			skills.push_back(temp);
		}
		inFile.ignore();
	}
}

Skill Game::get_skill(int index)
{
	return skills.at(index); //Not accouting for out of range.
}

void Game::intialize() const
{
	//Initialize anything needed for the game here.
}

