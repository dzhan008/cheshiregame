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
Item::Item(const Item& origItem)
{
	this->name = origItem.name;
	this->value = origItem.value;
}
Item::Item(const Item*& origItem)
{
	this->name = origItem->name;
	this->value = origItem->value;
}
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

int Item::getSlot() const
{
	return slot_type;
}