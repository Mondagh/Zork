#pragma once

#include <string>
#include <list>

using namespace std;


enum EntityEnum
{
	ROOM,
	EXIT,
	ITEM,
	PLAYER
};

class Entity
{
public:
	Entity();
	Entity(string entityName, string entityDescription);
	virtual ~Entity();
	virtual bool Update();
	void Watch(const string args);
public:
	EntityEnum type;
	string name;
	string description;
	list<Entity*> entitys;
};



