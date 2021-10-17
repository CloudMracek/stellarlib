#include <vector>
#include <thread>
#include "entity.h"
#include <chrono>

enum class SimulationState {Running, Stopped, Failed};

class Simulation
{
	public:
		Simulation();
		void start();
		void stop();

		void setSpeed(int speed);
		int getSpeed();

		void addEntity(Entity entity);
//		void removeEntity(Entity entity);
		void clearEntities();
		vector<Entity> getEntities();

		double getDeltaTime();

	private:
		vector<Entity> simulation_entities;
		std::chrono::milliseconds simulation_speed;
		long timescale;
		double delta_time;
		void simThread();
		std::thread simulation_thread;
		SimulationState simulation_state;


};

