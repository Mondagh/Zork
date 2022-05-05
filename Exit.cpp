#include "pch.h"
#include "Exit.h"
#include "Room.h"
#include "General.h"
#include <string>
#include <iostream>

using namespace std;

Exit::Exit()
{
}

Exit::Exit(string exitName, string exitDescription, ExitEnum exitDirection, Room* exitSource, Room* exitDestination, bool isLocked, Item* exitKey)
{
	name = exitName;
	description = exitDescription;
	direction = exitDirection;
	source = exitSource;
	destination = exitDestination;
	locked = true;
	key = exitKey;
	locked = isLocked;
	type = EXIT;
	exitSource->entitys.push_back(this);
}


Exit::~Exit()
{
}

ExitEnum Exit::GetDireccion(const string & direction)
{
	if (Compare(direction, "RIGHT")) return RIGHT;
	else if (Compare(direction, "LEFT")) return LEFT;
	else if (Compare(direction, "OUTSIDE")) return OUTSIDE;
	else if (Compare(direction, "UP")) return UP;

	return WRONG;
}

string Exit::GetDireccion(ExitEnum direcionEnum)
{
	switch (direction)
	{
	case RIGHT:
		return "Right";
		break;
	case LEFT:
		return "Left";
		break;
	case OUTSIDE:
		return "Outside";
		break;

	case UP:
		return "Up";
	default:
		break;
	}
	return string();
}

bool Exit::Watch(const string args)
{
	bool see = true;

	if (!args.empty())
	{
		if (!Compare(name, args))
		{
			cout << "\nYou can't see a " << args;
			see = false;
		}
	}
	if (see)
	{
		cout << "\nYou see a " << name << ". " << description << ". Direction " << GetDireccion(direction);
	}
	return see;
}
bool Exit::UnLock(Item* unLockItem)
{
	bool unLock = false;
	if (locked)
	{
		if (Compare(key->name, unLockItem->name))
		{
			locked = false;
			cout << "\nYou unlock the " << name << " with a " + unLockItem->name;
			unLock = true;
		}
		else
		{
			cout << "\nYou can't unlock the " << name + " with a " << unLockItem->name;
		}

	}
	else
	{
		cout << "\n" << name << " is unlocked";
	}
	return unLock;
}