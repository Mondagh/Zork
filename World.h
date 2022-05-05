#pragma once
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
	bool CheckPlaying();

private:

	list<Entity*> entities;
	Player* player;
	char* verb;
public:

	bool playing;
};

