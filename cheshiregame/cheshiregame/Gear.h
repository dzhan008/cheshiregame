#ifndef GEAR_H
#define GEAR_H

#include "Player.h"
#include "Item.h"

class Gear : public Item
{
	private:
		string type;
		unsigned statBoost;
	public:
		Gear(std::string name, std::string type, int val);
		Gear(std::string name, int val, std::string type, int stat);
		~Gear();

		string getType() const;
		int getStats();
		void printItem() const;

		Gear(const Gear*&);
		bool equipGear(Gear* gear, player* p);
};

#endif
