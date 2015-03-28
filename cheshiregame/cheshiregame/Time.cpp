#include "stdafx.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include <string>

using namespace std;

/*----------Private Helper Functions----------*/
void Time::display_remain()
{
	cout << setfill('0');
	cout << "Remaining Time: " << time_hour << " hours, ";
	cout << setw(2) << time_minute << " minutes. " << endl;
}

void Time::convert()
{
	if (minute >= 60)
	{
		hour = hour + minute / 60;
		minute = minute % 60;
	}

	if (hour >= 24)
	{
		hour = hour % 24;
	}

	if (hour >= 0 && hour <= 11)
	{
		suffix = 'A';
	}

	else
	{
		suffix = 'P';
	}

}

void Time::reset_day()
{
	day += 1;
	hour = 8;
	minute = 0;
	suffix = 'A';
	time_hour = 16;
	time_minute = 0;
}

/*----------Public Member Functions----------*/
Time::Time()
	: day(1), hour(12), minute(0), suffix('A'), time_hour(16), time_minute(0)
{ }

Time::Time(int d, int h, int m, char s)
	: day(d), hour(h), minute(m), suffix(s), time_hour(16), time_minute(0)
{ }

void Time::display_time()
{
	int temp_hour = hour;
	cout << setfill('0');
	cout << "Day " << day << endl;
	cout << "Time: ";
	if (temp_hour == 0) //in mil time, when time is 0, its midnight
	{
		temp_hour = 12;
	}
	else if (temp_hour > 12)
	{
		temp_hour = temp_hour - 12;
	}
	cout << temp_hour << ":";
	cout << setw(2) << minute << ' ' << suffix << "M" << endl;
	cout << "Remaining Time: " << time_hour << " hours, ";
	cout << setw(2) << time_minute << " minutes. " << endl;

}


bool Time::time_empty()
{
	if (time_hour <= 0 && time_minute <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Time::update_time(string s)
{
	/*not sure what stuff the player does that will take up time but these are the things
	I'm taking into account:
	1. Quests (two hours)
	2. Dungeons (three hours)
	3. Crafting (two hours)
	4. Traveling to other Towns (one hour) actually might depend on the town's distance
	5. Talking to a NPC (5 minutes)
	6. Sleeping (resets stuff) doesn't cost time
	The player is going to have a total of 16 hours to do stuff. 8 AM the day starts and
	sleep at midnight.
	*/
	if (time_empty() && s != "sleep")
	{
		cout << "Cannot do that. You ran out of time! Time to sleep..." << endl;
		reset_day();
		return;
	}

	else if (s == "sleep")
	{
		reset_day();
	}

	else if (s == "quest")
	{
		if (time_hour - 2 < 0)
		{
			cout << "Cannot do a quest. Not enough time." << endl;
			display_remain();
			return;
		}
		else
		{
			time_hour -= 2;
			hour += 2;
			convert();
		}
	}

	else if (s == "dungeon")
	{
		if (time_hour - 3 < 0)
		{
			cout << "Cannot do a dungeon run. Not enough time." << endl;
			display_remain();
			return;
		}

		else
		{
			time_hour -= 3;
			hour += 3;
			convert();
		}
	}

	else if (s == "craft")
	{
		if (time_hour - 2 < 0)
		{
			cout << "Cannot craft. Not enough time." << endl;
			display_remain();
			return;
		}

		else
		{
			time_hour -= 2;
			hour += 2;
			convert();
		}
	}

	else if (s == "travel")
	{
		if (time_hour - 1 < 0)
		{
			cout << "Cannot travel to another town. Not enough time." << endl;
			display_remain();
			return;
		}

		else
		{
			time_hour -= 1;
			hour += 1;
			convert();
		}
	}

	//will work on NPC later. Minutes are confusing.
	// 	else if (s == "npc")
	// 	{

	// 	    if (time_minute - 5 <= 0 )
	// 	    {
	// 	        time_minute = 55;
	// 	        if (hour - 1 < 0)
	// 	        {
	// 	            cout << "Cannot talk to NPC. Not enough time." << endl;
	// 	        }
	// 	        time_hour -= 1;
	// 	    }

	// 	    else
	// 	    {
	// 	        time_minute -= 5;
	// 	        minute += 5;
	// 	        convert();
	// 	    }
	// 	}


}