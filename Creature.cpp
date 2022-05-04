#include "pch.h"
#include "Creature.h"
#include "Entity.h"
#include "Room.h"


Creature::Creature(string creatureName, string creatureDescription, Room* creatureLocation)
{
	name = creatureName;
	description = creatureDescription;
	actualLocation = creatureLocation;

}

Creature::Creature() {

}

Creature::~Creature()
{
}

Room * Creature::GetActualLocation() const
{
	return (Room*)actualLocation;
}
