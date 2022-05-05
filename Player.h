#pragma once

#include "Creature.h"
class Player :
	public Creature
{
public:
	Player(string playerName, string playerDescription, Room* playerLocation);
	~Player();
	bool Move(const vector<string>& args);
	void Watch(const vector<string>& args) const;
	void Open(const vector<string>& args) const;
	void Take(const vector<string>& args);
	void Drop(const vector<string>& args);
	void UnLock(const vector<string>& args);

public:
	int itemsTaked;
	const int maxItemsTaked = 2;
};

