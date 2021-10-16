#include "simulation.h"
#include <vector>

Simulation::Simulation()
{
	//simulation_entities = {};
	Simulation::simulation_state = SimulationState::Stopped;
}

void Simulation::start()
{
	Simulation::simulation_state = SimulationState::Running;
}

void Simulation::stop()
{
	Simulation::simulation_state = SimulationState::Stopped;
}

void Simulation::setSpeed(float speed)
{
	simulation_speed = speed;
}

float Simulation::getSpeed()
{
	return simulation_speed;
}

void Simulation::addEntity(Entity entity)
{
	simulation_entities.push_back(entity);
}

/* Maybe later

void removeEntity(Entity entity)
{
	int i = 0;
	for (Entity e : simulation_entities)
	{
		if(e == entity)
		{
			simulation_entites.erase(i);
		}
		i++;
	}
}

*/

void Simulation::clearEntities()
{
	//simulation_entities = {};
}

vector<Entity> Simulation::getEntities()
{
	return simulation_entities;
}

double Simulation::getDeltaTime()
{
	return delta_time;
}
