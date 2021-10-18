#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include "simulation.h"
#include <unistd.h>

using namespace std;

int main()
{
	Simulation simulation;

	vector<double> pos1{0,0,0};
	vector<double> pos2{500,800, 1000};

	Entity entity1("Earth", 5.972*pow(10,24), pos1);
	Entity entity2("Moon", 7.348*pow(10,22), pos2);

    entity1.setVelocity(vector<double>{150, 0, 0});

	simulation.addEntity(entity1);
	//simulation.addEntity(entity2);


	vector<double> velocity = vector<double>{150.3,0, 0};

	try
	{
		entity1.setVelocity(velocity);
	}
	catch(const invalid_argument e)
	{
		cout << e.what() << endl;
		return 1;
	}

	cout << entity1.getName() << ": " << entity1.getMass() << "kg." << endl;
	cout << entity2.getName() << ": " << entity2.getMass() << "kg." << endl;

	simulation.start();
	sleep(1);
	simulation.stop();

    cout << entity1.getPosition()[0] << " " << entity1.getPosition()[1] << " " <<entity1.getPosition()[2] << endl;

	return 0;
}
