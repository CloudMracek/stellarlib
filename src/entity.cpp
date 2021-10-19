#include "entity.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cmath>
#define G 6.67428*pow(10, -11)

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
    entity_acceleration = vector<double>{0,0,0};
}

void Entity::tick(vector<std::reference_wrapper<Entity>> e, double delta)
{
    for(Entity& e : e)
    {

        if(e.getName() == getName()) continue;
        vector<double> newAccel =  compAccel(e);
        entity_acceleration[0] += newAccel[0]/entity_mass;
        entity_acceleration[1] += newAccel[1]/entity_mass;
        entity_acceleration[2] += newAccel[2]/entity_mass;
    }

    entity_velocity[0] += entity_acceleration[0]*delta;
    entity_velocity[1] += entity_acceleration[1]*delta;
    entity_velocity[2] += entity_acceleration[2]*delta;

    x += entity_velocity[0];
	y += entity_velocity[1];
	z += entity_velocity[2];

    std::cout << getName() << " " << entity_velocity[0] << " " << entity_velocity[1] << " " << entity_velocity[2] << std::endl;
    entity_acceleration = vector<double>{0,0,0};


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

vector<double> Entity::compAccel(Entity e2)
{
    double massA = getMass();
    double massB = e2.getMass();

    vector<double> posA = getPosition();
    vector<double> posB = e2.getPosition();

    double deltaX = posA[0] - posB[0];
    double deltaY = posA[1] - posB[1];
    double deltaZ = posA[2] - posB[2];

    double realDistance = sqrt(pow(posA[0] - posB[0],2) + pow(posA[1] - posB[1],2) + pow(posA[2] - posB[2],2));

    double ForceX = ((G*massA*massB)/(pow(realDistance, 3)))*deltaX;
    double ForceY = ((G*massA*massB)/(pow(realDistance, 3)))*deltaY;
    double ForceZ = ((G*massA*massB)/(pow(realDistance, 3)))*deltaZ;

    //std::cout << ForceX << " " << ForceY << " " << ForceZ<< std::endl;

    return vector<double>{ForceX, ForceY, ForceZ};
}
