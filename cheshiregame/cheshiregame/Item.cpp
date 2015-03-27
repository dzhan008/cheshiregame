#include "stdafx.h"
#include "Item.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Item::Item()
	:value(0)
{}
Item::Item(const string name)
    :name(name), value(0)
{}
Item::Item(const string name, const int val)
    :name(name), value(val)
{}
void Item::printItem() const
{
    cout << "Name: " << name << endl;
    cout << "Value: " << value << endl;
}

string Item::getName() const
{
	return name;
}

int Item::getValue() const
{
	return value;
}
