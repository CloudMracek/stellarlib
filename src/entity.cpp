#include "entity.h"
#include <string>
#include <vector>
#include <stdexcept>

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

void Entity::setVelocity(vector<double> velocity)
{
	if(velocity.size() != 3)
		throw std::invalid_argument("Vector must be 3 dimensional.");
	entity_velocity = velocity;
}

vector<double> Entity::getVelocity()
{
	return entity_velocity;
}

void Entity::setAcceleration(vector<double> acceleration)
{
	if(acceleration.size() != 3)
		throw std::invalid_argument("Vector must be 3 dimensional.");
	entity_acceleration = acceleration;
}

vector<double> Entity::getAcceleration()
{
	return entity_acceleration;
}
