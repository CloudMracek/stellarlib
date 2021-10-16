#include <string>
#include <vector>

using namespace std;

class Entity
{
	public:
		Entity(string name, double mass);

		double getMass();
		string getName();

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

};

