#pragma once
#include "Entity.h"
#include "Room.h"
class Creature :
	public Entity
{
public:
	Creature(string creatureName, string creatureDescription, Room* creatureLocation);
	Creature();
	~Creature();
	Room* GetActualLocation() const;
public:
	Room* actualLocation;
};

