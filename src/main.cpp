#include <iostream>
#include "entity.h"
#include <cmath>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
	Entity entity1("Earth", 5.972*pow(10,24));
	Entity entity2("Moon", 7.348*pow(10,22));

	vector<double> velocity = vector<double>{150.3, 150.8, 220.6, 22.8};

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
	return 0;
}
