#pragma once


#include <string>
#include <vector>
#include "Entity.h"
#include "Exit.h"

class Exit;

class Room :
	public Entity
{
public:
	Room();
	Room(string roomName, string roomDescription);
	~Room();
	Exit* FindExit(const string& direction) const;
	void Watch(const string args);
};

