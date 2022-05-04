#pragma once
//#ifndef __World__
//#define __World__

#include <string>
#include <list>
#include <vector>



using namespace std;

class Entity;
class Player;

class World
{
public:

	World();
	~World();

	bool CheckAction(vector<string>& actions);
	void LoadWorld();

private:

	list<Entity*> entities;
	Player* player;
	char* verb;
};

//#endif //__World__
