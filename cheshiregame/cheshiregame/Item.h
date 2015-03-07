#ifndef Item_H
#define Item_H
#include <string>

using namespace std;

class Item
{
    public:
        Item();
        Item(const string);
        Item(const string, const int val);
        void printItem() const;
    private:
        string name;
        int value;
};
class Equip:public Item
{
    public:
        bool equipPlayer(string item);
};
class Potion:public Item
{
    public:
        bool usePotion();
};
class Quest:public Item
{
    public:
        void triggerItem();
};

#endif
