#include <string>
#include <vector>
#include <functional>

using namespace std;

class Entity
{
	public:
		Entity(string name, double mass, vector<double> position);

		double getMass();
		string getName();

		void tick(vector<std::reference_wrapper<Entity>> entities, double delta);

		vector<double> getPosition();
		void setPosition(vector<double>);

		void setMass(double mass);
		void setName(string name);

		void setVelocity(vector<double> speed);
		vector<double> getVelocity();

		void setAcceleration(vector<double> acceleration);
		vector<double> getAcceleration();

	private:
		string entity_name;
		double entity_mass;
		vector<double> entity_velocity;
		vector<double> entity_acceleration;
		double x;
		double y;
		double z;
        vector<double> compAccel(Entity e1, Entity e2);

};

