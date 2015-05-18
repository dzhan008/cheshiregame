#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>


typedef int ID;

template<typename Type>
item_list::item_list(std::string file_name)
{
	fstream inFile;
	std::string file_name;

	int counter = 0;
	int boost;
	int val;

	inFile.open(file_name.c_str())
	
	if (!inFile.is_open())
	{
		std::cout << "Error: Cannot open file.";
		return;
	}

	if (file_name == "items.txt")
	{
		while (std::getline(inFile, item_name) != "<End>")
		{
			inFile >> val;
			Item* temp = new Item(item_name, val);
			list[counter] = temp;
			counter++;
		}
	}
	else if (file_name == "consumable.txt")
	{
		while (std::getline(inFile, item_name) != "<End>")
		{
			inFile >> boost >> val;
			Consumable* temp = new Consumable(item_name, "Consumable", boost, val);
			list[counter] = temp;
			counter++;
		}
	}
	else if (file_name == "gear.txt")
	{

	}
	else if (file_name == "weapon.txt")
	{

	}
}
template<typename Type>
Type item_list::find(int item_ID)
{
	return *list[item_ID];
}
template < typename Type >
void item_list::populate_vector(int beg, int end, std::vector<Type>& temp)
{
	std::vector<Type> temp;

	for (int i = beg; i < end; ++i)
	{
		temp.push_back(list[i]);
	}
	
	return temp;
}
template < typename Type >
void item_list::populate_vector(std::string file_name, std::vector<Type>& temp)
{
	fstream inFile;
	int item_ID;

	inFile.open(file_name.c_str());

	if (!inFile.is_open())
	{
		std::cout << "Error: Cannot open file.";
		return;
	}
	
	while (inFile >> item_ID)
	{
		if (list.find(item_ID) == list.end())
		{
			std::cout << "Error: Non-existant ID entered! Aborting insert...\n"
			return;
		}
		temp.push_back(list[item_ID]);
	}

	return;

}
template < typename Type >
void item_list::populate_map(int beg, int end, std::map<ID, Type>& temp)
{
	for (int i = beg; i < end; ++i)
	{
		temp[i] = list[i];
	}
	return;
}
template < typename Type >
void item_list::populate_map(std::string file_name, std::map<ID, Type>& temp)
{
	fstream inFile;
	int item_ID;

	inFile.open(file_name.c_str());

	if (!inFile.is_open())
	{
		std::cout << "Error: Cannot open file.";
		return;
	}

	while (inFile >> item_ID)
	{
		if (list.find(item_ID) == list.end())
		{
			std::cout << "Error: Non-existant ID entered! Aborting insert...\n";
			return;
		}
		temp[item_ID] = list[item_ID];
	}
	return;
}