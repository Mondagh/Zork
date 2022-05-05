#include "pch.h"
#include "Entity.h"



Entity::Entity() {

}

Entity::Entity(string entityName, string entityDescription)

{
	name = entityName;
	description = entityDescription;
}

Entity::~Entity()
{
}

bool Entity::Update()
{
	return false;
}

void Entity::Watch(const string args)
{
}


