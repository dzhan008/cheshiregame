#ifndef TIME_H
#define TIME_H

#include "stdafx.h"
#include <string>

using namespace std;

class Time
{

private:
	int day;
	int hour;
	int minute;
	char suffix;

	int time_hour; //how many hours player has left
	int time_minute; //how many minutes player has left

	void display_remain(); //just displays the remaining time.
	void convert(); //fixes the time if hours are over 12 or minutes over 60
	void reset_day(); //resets the time stuff and adds a day.

public:
	Time();
	Time(int, int, int, char);
	void display_time(); //displays day, time, and remaining points
	bool time_empty(); //returns T if time points is empty

	/*  update_time function updates the time and remaining time points a player has
	a string is passed in to represent what action the player did
	i.e p.update_time(quest);
	*/
	void update_time(string); //updates the time and remaining time points player has
};

#endif
