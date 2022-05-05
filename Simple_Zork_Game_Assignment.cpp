

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "General.h"
#include "World.h"


using namespace std;  


int main()
{
	char key;
	string player_input;
	vector<string> action;
	action.reserve(10);
	

	cout <<  "Welcome to MyZore Game!" ;
	cout << "\nYou have to excape from the prision\n";

	World world;

	while (world.CheckPlaying())
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			if (key == '\b') 
			{
				if (player_input.length() > 0)
				{
					player_input.pop_back();
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			else if (key != '\r') 
			{
				player_input += key;
				cout << key;
			}
			else
		   Tokenize(player_input, action);
		if (action.size() > 0 && action[0]._Equal("quit"))
			break;

		}
		if (world.CheckAction(action) == false)
			cout << "\nSorry, I do not understand your command.\n";
		if (action.size() > 0)
		{
			action.clear();
			player_input = "";
			cout << "\n> ";
		}
	}
	return 0;
}

