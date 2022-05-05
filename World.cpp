#include "pch.h"
#include <iostream>
#include "World.h"
#include "General.h"
#include "Creature.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include <string>
#include <algorithm>
#include "Item.h"



using namespace std;

World::World()
{
	playing = true;
	LoadWorld();
}


World::~World()
{
}

/*

	This checks the action of the player
*/
bool World::CheckAction(vector<string>& actions)
{
	bool done = false;
	if (actions.size() > 0 && !actions[0].empty() && !actions[0]._Equal("\n"))
	{
		if (Compare(actions[0], "move")) {
			done = player->Move(actions);
			if (done)
			{
				playing = false;
			}
		}
		else if (Compare(actions[0], "look")) {
			player->Watch(actions);
		}
		else if (Compare(actions[0], "take")) {
			player->Take(actions);
		}
		else if (Compare(actions[0], "open")) {
			player->Open(actions);
		}
		else if (Compare(actions[0], "drop")) {
			player->Drop(actions);
		}
		else if (Compare(actions[0], "unlock")) {
			player->UnLock(actions);
		}
		else {
			return false;
		}
	}

	return true;
}

void World::LoadWorld()
{
	//Create all entitys

	//Rooms

	Room* cell = new Room("Cell", "It's a small cell with a bad smell");
	entities.push_back(cell);

	Room* guardRoom = new Room("Guards Room", "It's room when guards play and eat.");
	entities.push_back(guardRoom);


	Room* stairs = new Room("Stairs", "Whood stairs");
	entities.push_back(stairs);

	Room* entrance = new Room("Entrance", "Seems the entrance of this prision");
	entities.push_back(entrance);

	//Items

	//cell items

	Item* bone = new Item("Bone", "Small elongated bone", true, cell, true, false, true);
	entities.push_back(bone);
	Item* skull = new Item("Skull", "Maybe another prisoner", true, cell, true, false, true);
	entities.push_back(skull);

	//guardRoom items
	Item* table = new Item("Table", "A whood table", true, guardRoom, true, false, false);
	entities.push_back(table);
	Item* chair = new Item("Chair", "A slightly broken chair", true, guardRoom, true, false, true);
	entities.push_back(chair);
	Item* key = new Item("Key", "A little metalic key", true, guardRoom, true, false, true);
	entities.push_back(key);

	//entrance items	
	Item* chest = new Item("Chest", "Small chest", true, entrance, false, false, true);
	entities.push_back(chest);
	Item* diamont = new Item("Diamont", "A precios diamond as big as your hand", false, entrance, true, false, true);
	entities.push_back(diamont);
	chest->entitys.push_back(diamont);

	//Exits

	Exit* cellDoorR = new Exit("Door", "Simple cell door", RIGHT, cell, guardRoom, true, bone);
	entities.push_back(cellDoorR);
	Exit* cellDoorL = new Exit("Door", "Simple cell door", LEFT, guardRoom, cell, false, NULL);
	entities.push_back(cellDoorL);

	Exit* guardRoomDoorR = new Exit("Door", "Whood door", RIGHT, guardRoom, stairs, false, NULL);
	entities.push_back(guardRoomDoorR);
	Exit* guardRoomDoorL = new Exit("Door", "Whood door", LEFT, stairs, guardRoom, false, NULL);
	entities.push_back(guardRoomDoorL);

	Exit* stairsR = new Exit("Door", "Whood door", RIGHT, stairs, entrance, false, NULL);
	entities.push_back(stairsR);
	Exit* stairsL = new Exit("Door", "Whood door", LEFT, entrance, stairs, false, NULL);
	entities.push_back(stairsL);

	Exit* entranceExit = new Exit("Door", "Simple cell door", OUTSIDE, entrance, cell, true, key);
	entities.push_back(entranceExit);


	player = new Player("Player", "A player", cell);
	entities.push_back(player);
}

bool World::CheckPlaying()
{
	return playing;
}
