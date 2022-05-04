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
	LoadWorld();
}


World::~World()
{
}



bool World::CheckAction(vector<string>& actions)
{
	bool done = true;
	if (actions.size() > 0 && !actions[0].empty() && !actions[0]._Equal("\n"))
	{
	 

		if (Compare(actions[0], "move")){
			cout << "\nEstamos en move\n";
			player->Move(actions);
		}
		else if (Compare(actions[0], "look")) {
			cout << "\nEstamos en look\n";
			player->Watch(actions);
		}
		else if (Compare(actions[0], "take")) {
			cout << "\nEstamos en take\n";
			player->Take(actions);
		}
		else if (Compare(actions[0], "open")) {
			cout << "\nEstamos en open\n";
			player->Open(actions);
		}
		else if (Compare(actions[0], "drop")) {
			cout << "\nEstamos en drop\n";
			player->Drop(actions);
		}
		else if (Compare(actions[0], "unlock")) {
			cout << "\nEstamos en unlock\n";
			player->UnLock(actions);
		}
		else {
			return false;
		}


	}
	
	return done;
}

void World::LoadWorld()
{
	//Create all entitys
	Room* bedRoom = new Room("BedRoom", "Small bedroom");
	entities.push_back(bedRoom);
	Item* key = new Item("Key", "Description of Key 1", false, bedRoom, true, false,true);
	entities.push_back(key);
	Item* chest = new Item("Chest", "Description of chest 1", true, bedRoom, false, false,false);
	entities.push_back(chest);
	chest->entitys.push_back(key);

	Room* room2 = new Room("Room2", "Description of room 2");
	entities.push_back(room2);
	

	Exit* exit = new Exit("Door", "Description of exit1",RIGHT, bedRoom, room2,true,key);
	entities.push_back(exit);
	Exit* exit2 = new Exit("Door", "Description of exit1", LEFT, room2, bedRoom,false, NULL);
	entities.push_back(exit2);
	player = new Player("Paco", "El aventurero Paco", bedRoom);
	entities.push_back(player);
}

