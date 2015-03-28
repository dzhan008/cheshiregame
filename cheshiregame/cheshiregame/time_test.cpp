#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time test(1, 8, 0, 'A'); //starts day 1 at 8 AM
	test.display_time();

	string s;

	while (s != "exit")
	{
		cout << "What do you want to do? ";
		cout << "(quest/dungeon/craft/travel/sleep/exit): ";
		cin >> s;
		test.update_time(s);
		test.display_time();
		cout << endl;
	}

	return 0;
}