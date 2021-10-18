#include <vector>
#include <thread>
#include "entity.h"
#include <chrono>
#include <functional>

enum class SimulationState {Running, Stopped, Failed};

class Simulation
{
	public:
		Simulation();
		void start();
		void stop();

		void setSpeed(int speed);
		int getSpeed();

		void addEntity(Entity& entity);
//		void removeEntity(Entity entity);
		void clearEntities();
        vector<std::reference_wrapper<Entity>> getEntities();

		double getDeltaTime();

	private:
		vector<std::reference_wrapper<Entity>> simulation_entities;
		std::chrono::milliseconds simulation_speed;
		long timescale;
		double delta_time;
		void simThread();
		std::thread simulation_thread;
		SimulationState simulation_state;


};

