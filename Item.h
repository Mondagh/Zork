#pragma once
#include "Entity.h"
#include "Room.h"
#include <string>


class Room;
class Item :
	public Entity
{
public:
	Item();
	~Item();
	Item(string itemName, string itemDescription, bool isVisible, Room* starterLocation, bool isOpened, bool isTaken, bool posibleTaken);
	bool Watch(const string args);
	bool Open();
	bool Take();
	bool Drop();

public:
	bool visible;
	Room* location;
	bool taked;
	bool open;
	bool taken;


};

