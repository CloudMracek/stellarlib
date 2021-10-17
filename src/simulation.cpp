#include "simulation.h"
#include <vector>
#include <iostream>
#include <thread>
#include <time.h>
#include <chrono>

Simulation::Simulation()
{
	//simulation_entities = {};
	simulation_speed = std::chrono::milliseconds(16);
	Simulation::simulation_state = SimulationState::Stopped;
}

void Simulation::start()
{
	Simulation::simulation_state = SimulationState::Running;
	Simulation::simulation_thread = std::thread(&Simulation::simThread, this);
}

void Simulation::stop()
{
	Simulation::simulation_state = SimulationState::Stopped;
	simulation_thread.join();
}

void Simulation::simThread()
{

	while(simulation_state == SimulationState::Running)
	{
		auto start = std::chrono::system_clock::now();
		// Stuff
		auto end = std::chrono::system_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::this_thread::sleep_for(simulation_speed - elapsed);
	}

}



void Simulation::setSpeed(int fps)
{
	simulation_speed = std::chrono::milliseconds((1/fps)*1000);
}

int Simulation::getSpeed()
{
	return (int) simulation_speed.count();
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
