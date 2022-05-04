#include "pch.h"
#include "Room.h"
#include "Exit.h"
#include "General.h"
#include <iostream>
#include "Item.h"

using namespace std;


class Item;
class Exit;

Room::Room() {

}

Room::Room(string roomName, string roomDescription)
{
	name = roomName;
	description = roomDescription;
	type = ROOM;
}


Room::~Room()
{
}

Exit * Room::FindExit(const string& direction) const
{
	for (list<Entity*>::const_iterator cit = entitys.begin(); cit != entitys.cend(); ++cit)
	{
		if ((*cit)->type == EXIT)
		{
			Exit* ex = (Exit*)*cit;
			if (ex->direction == ex->GetDireccion(direction))
				return ex;

		}
	}
	return NULL;
}

void Room::Watch(const string args)
{
	
	if (args.empty())
	{
		cout << "\n" << name << "\n" << description;
	}
	bool see = false;

	for (list<Entity*>::const_iterator cit = entitys.begin(); cit != entitys.cend(); ++cit)
	{
		if ((*cit)->type == ITEM)
		{
			Item* item = (Item*)*cit;
			if (args.empty())
			{
				item->Watch(args);
			}
			else if (!see)
			{
				see = item->Watch(args);
			}
		}
		else if ((*cit)->type == EXIT)
		{
			Exit* exit = (Exit*)*cit;
			if (args.empty())
			{
				exit->Watch(args);
			}
			else if (!see)
			{
				see = exit->Watch(args);
			}
			
		}
	}
}


