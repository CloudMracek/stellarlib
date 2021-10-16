#include <iostream>
#include "entity.h"
#include <cmath>
using namespace std;

int main()
{
	Entity entity1("Earth", 5.972*pow(10,24));
	Entity entity2("Moon", 7.348*pow(10,22));

	cout << entity1.getName() << ": " << entity1.getMass() << "kg." << endl;
	cout << entity2.getName() << ": " << entity2.getMass() << "kg." << endl;
	return 0;
}
