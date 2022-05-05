#pragma once

#include "Entity.h"
#include <string>
#include "Room.h"
#include "Item.h"

class Room;
class Item;

enum ExitEnum {
	RIGHT,
	LEFT,
	OUTSIDE,
	UP,
	WRONG
};
class Exit :
	public Entity
{
public:
	Exit();
	Exit(string exitName, string exitDescription, ExitEnum exitDirection, Room* exitSource, Room* exitDestination,bool isLocked, Item* exitKey);
	~Exit();
	ExitEnum GetDireccion(const string& direction);
	string GetDireccion(ExitEnum direcionEnum);
	bool Watch(const string args);
	bool UnLock(Item* unLockItem);
public:
	ExitEnum direction;
	Room* source;
	Room* destination;
	bool locked;
	Item* key;
};


