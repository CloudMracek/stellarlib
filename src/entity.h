#include <string>
using namespace std;

class Entity
{
	public:
		Entity(string name, double mass);

		double getMass();
		string getName();

		void setMass(double mass);
		void setName(string name);

	private:
		string entity_name;
		double entity_mass;

};

