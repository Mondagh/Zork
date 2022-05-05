#include "pch.h"
#include "Player.h"
#include "Creature.h"
#include "Exit.h"
#include <iostream>
#include "General.h"


using namespace std;

Player::Player(string playerName, string playerDescription, Room* playerLocation)
{
	name = playerName;
	description = playerDescription;
	actualLocation = playerLocation;
	type = PLAYER;
}


Player::~Player()
{
}

bool Player::Move(const vector<string>& args)
{
	if (args.size() > 1)
	{
		Exit* exit = GetActualLocation()->FindExit(args[1]);

		if (exit == NULL)
		{
			cout << "\nYou can't move to direcion " << args[1] << "\n";
			return false;
		}
		if (exit->locked)
		{
			cout << "\nIt's locked. Find a key.\n";
			return false;

		}
		if (exit->direction == OUTSIDE)
		{
			cout << "\nYou found the exit, you are free!";
			return true;
		}
		actualLocation = exit->destination;
		cout << "\nYou move to " << GetActualLocation()->description << "\n";

	}
	return false;
}

void Player::Watch(const vector<string>& args) const
{
	if (args.size() > 1) {
		actualLocation->Watch(args[1]);
	}
	else {
		actualLocation->Watch("");
	}
}

void Player::Open(const vector<string>& args) const
{
	bool opened = false;
	if (args.size() > 1) {
		for (list<Entity*>::const_iterator cit = actualLocation->entitys.begin(); cit != actualLocation->entitys.cend(); ++cit)
		{
			if ((*cit)->type == ITEM)
			{
				Item* item = (Item*)*cit;
				if (Compare(item->name, args[1]))
				{
					opened = item->Open();
				}
			}

		}
		if (!opened)
		{
			cout << "\nYou can't open " << args[1];
		}

	}
	else {
		cout << "\nYou need to especificate what to open";
	}
}

void Player::Take(const vector<string>& args)
{
	bool taken = false;
	Item* itemTaked = NULL;
	if (args.size() > 1) {
		if (itemsTaked == maxItemsTaked)
		{
			cout << "\nYou only can take " << maxItemsTaked << " at the same time";
		}
		else {
			for (list<Entity*>::const_iterator cit = actualLocation->entitys.begin(); cit != actualLocation->entitys.cend(); ++cit)
			{
				if ((*cit)->type == ITEM)
				{
					Item* item = (Item*)*cit;
					if (Compare(item->name, args[1]) && !taken)
					{
						taken = item->Take();
						itemTaked = item;
					}
				}

			}
			if (taken)
			{
				itemsTaked++;
				actualLocation->entitys.remove(itemTaked);
				entitys.push_back(itemTaked);
			}
			else {
				cout << "\nYou can't take " << args[1];
			}
		}

	}
	else {
		cout << "\nYou need to especificate what to take";
	}
}

void Player::Drop(const vector<string>& args)
{
	bool drop = false;
	Item* itemDropped = NULL;
	if (args.size() > 1) {
		for (list<Entity*>::const_iterator cit = entitys.begin(); cit != entitys.cend(); ++cit)
		{
			if ((*cit)->type == ITEM)
			{
				Item* item = (Item*)*cit;
				if (Compare(item->name, args[1]) && !drop)
				{
					drop = item->Drop();
					itemDropped = item;
				}
			}
		}
		if (drop)
		{
			actualLocation->entitys.push_back(itemDropped);
			entitys.remove(itemDropped);
			itemsTaked--;
		}
		else {
			cout << "\nYou can't drop " << args[1];
		}

	}
	else {
		cout << "\nYou need to especificate what to drop";
	}
}

void Player::UnLock(const vector<string>& args)
{
	bool unLocked = false;
	Exit* itemDropped = NULL;
	Item* key = NULL;
	if (args.size() > 1) {
		for (list<Entity*>::const_iterator cit = entitys.begin(); cit != entitys.cend(); ++cit)
		{
			if ((*cit)->type == ITEM)
			{
				key = (Item*)*cit;

			}

		}
		if (key != NULL) {

			for (list<Entity*>::const_iterator cit = actualLocation->entitys.begin(); cit != actualLocation->entitys.cend(); ++cit)
			{
				if ((*cit)->type == EXIT)
				{
					Exit* exit = (Exit*)*cit;
					if (Compare(exit->name, args[1]) && !unLocked)
					{
						unLocked = exit->UnLock(key);
					}
				}

			}
		}
		if (!unLocked)
		{
			cout << "\nYou can't unlock " << args[1];
		}
	}
	else {
		cout << "\nYou need to especificate what to unlock";
	}

}
