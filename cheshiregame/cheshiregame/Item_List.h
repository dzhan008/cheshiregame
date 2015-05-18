#ifndef _ITEM_LIST_H_
#define _ITEM_LIST_H_

#include <iostream>
#include <vector>
#include <map>


typedef int ID;

template <typename Type>
class item_list
{
private:
	std::map<ID, Type*> list;
public:
	item_list(std::string file_name);

	Type* find(int item_ID); //Finds a specific item and returns it.
	void populate_vector(int beg, int end, std::vector<Type>& temp); //Populates a vector with specific items ranging in a list.
	void populate_vecotr(std::string file_name, std::vector<Type>& temp); //Populates a vector with specific items in a file.
	void populate_map(int beg, int end, std::map<ID, Type>& temp); //Same as above but makes a map instead.
	void populate_map(std::string file_name, std::map<ID, Type>& temp);
};
#endif