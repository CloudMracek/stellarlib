#include "entity.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

Entity::Entity(string name, double mass, vector<double> position)
{
    if(position.size() != 3)
        throw std::invalid_argument("Vector must be 3 dimensional.");

	entity_name = name;
	entity_mass = mass;
	x = position[0];
	y = position[1];
	z = position[2];

    entity_velocity = vector<double>{0,0,0};
}

void Entity::tick(vector<std::reference_wrapper<Entity>> e, double delta)
{
    x += entity_velocity[0]*delta;
	y += entity_velocity[1]*delta;
	z += entity_velocity[2]*delta;
}

vector<double> Entity::getPosition()
{
	return std::vector<double>{x,y,z};
}

void Entity::setPosition(vector<double> pos)
{
    if(pos.size() != 3)
        throw std::invalid_argument("Vector must be 3 dimensional.");
	x = pos[0];
	y = pos[1];
	z = pos[2];
}

double Entity::getMass()
{
	return entity_mass;
}

void Entity::setMass(double mass)
{
	entity_mass = mass;
}

string Entity::getName()
{
	return entity_name;
}

void Entity::setName(string name)
{
	entity_name = name;
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
