#include "entity.h"
#include <vector>

enum class SimulationState {Running, Stopped, Failed};

class Simulation
{
	public:
		Simulation();
		void start();
		void stop();

		void setSpeed(float speed);
		float getSpeed();

		void addEntity(Entity entity);
//		void removeEntity(Entity entity);
		void clearEntities();
		vector<Entity> getEntities();

		double getDeltaTime();

	private:
		vector<Entity> simulation_entities;
		float simulation_speed;
		double delta_time;
		SimulationState simulation_state;


};

