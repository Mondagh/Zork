#include "pch.h"
#include "Item.h"
#include <iostream>
#include "General.h"


using namespace std;

Item::Item()
{
}


Item::~Item()
{
}

Item::Item(string itemName, string itemDescription, bool isVisible, Room* starterLocation, bool isOpened, bool isTaken ,bool posibleTaken)
{
	name = itemName;
	description = itemDescription;
	visible = isVisible;
	location = starterLocation;
	open = isOpened;
	taked = isTaken;
	taken = posibleTaken;
	type = ITEM;
	starterLocation->entitys.push_back(this);
}

bool Item::Watch(string args)
{
	bool see = true;
	if (visible)
	{
		if (!args.empty())
		{
			if (!Compare(name, args))
			{
				see = false;
			}
		}
		if (see)
		{
			cout << "\nYou see a " << name << "\n" << description;
		}
		return see;
	}
	
}

bool Item::Open()
{
	bool opened = false;
	if (visible)
	{
		if (open)
		{
			cout << "\n" << name << " has alredy been opened";
		}
		else {
			open = true;
			for (list<Entity*>::const_iterator cit = entitys.begin(); cit != entitys.cend(); ++cit) {
				if ((*cit)->type == ITEM)
				{

					Item* item = (Item*)*cit;
					item->visible = true;
				}
			}
			cout << "\nYou open the " << name;
			opened = true;
		}
	}
	return opened;
}

bool Item::Take()
{
	bool isTaken = false;
	if (visible && taken)
	{
		if (taked)
		{
			cout << "\n" << name << " has alredy been taken";
		}
		else {
			isTaken = true;
			cout << "\nYou take the " << name;
			taked = true;
		}

	}
	return isTaken;
}

bool Item::Drop()
{
	bool isDropped = false;
	if (visible)
	{
		if (!taked)
		{
			cout << "\n" + name << " has alredy been droped";
		}
		else {
			isDropped = true;
			cout << "\nYou drop the " << name;
			taked = false;
		}

	}
	return isDropped;
}
