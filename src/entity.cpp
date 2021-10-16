#include "entity.h"
#include <string>

Entity::Entity(string name, double mass)
{
	entity_name = name;
	entity_mass = mass;
}

double Entity::getMass()
{
	return entity_mass;
}

string Entity::getName()
{
	return entity_name;
}

void Entity::setName(string name)
{
	entity_name = name;
}

void Entity::setMass(double mass)
{
	entity_mass = mass;
}
