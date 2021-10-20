# stellarlib
A simple C++ library which ~~simulates~~ hopefully will simulate astrodynamics.

This is my personal science project in which I try to connect my love for programming with my love for science.
It's still nowhere near done or usable though I highly don't recommend anyone to use this library unless you know what you're doing (I certainly don't)

At the moment it can do these things:
- Create Entites in a sensible object
- Assign these entities to a Simulation instance
- Apply velocities to their positions consistently based on the simulation speed and it's delta time.

This project is my first attempt to do something usable with C++ and it most likely violates every unwritten rule of C++ programming.
If that is the case I would love you to correct my mistakes in the Issues section for me to correct them. Please keep in mind that I
don't merge pull requests. I take this thing as my personal project to learn C++. Sorry to disappoint...

Yes I'm aware that it's not really a library yet since it creates a binary.

Here is a short code example
```cpp
Simulation simulation; // Create a Simulation instance

vector<double> pos1{0,0,0};           // Default positons of the 2 entities we're going to create
vector<double> pos2{500,800, 1000};   //

Entity entity1("Earth", 5.972*pow(10,24), pos1); // Creating 2 instances of the Entity class
Entity entity2("Moon", 7.348*pow(10,22), pos2);  // Name, Mass (doesn't do anything yet), default position

simulation.addEntity(entity1); // Adding theese entites to the simulation
simulation.addEntity(entity2); // Note that preventing the entities from being in two simulations at once is not yet implemented


vector<double> velocity1 = vector<double>{150.3, 0, 0}; // Preparing the velocities
vector<double> velocity2 = vector<double>(0, 0, 70);    //

entity1.setVelocity(velocity1); // Setting the velocities
entity2.setVelocity(velocity2)  //

simulation.start(); // Starting the simulation
sleep(1);           // Letting it run for 1 second
simulation.stop();  // Stopping the simulation

cout << entity1.getPosition()[0] << " " << entity1.getPosition()[1] << " " <<entity1.getPosition()[2] << endl;  // Printing the results
cout << entity2.getPosition()[0] << " " << entity2.getPosition()[1] << " " <<entity2.getPosition()[2] << endl;  //
```

## Building
```
make
```

## To-do
- Newton's law of universal gravitation
- Newton's 3 laws of motion
- The above will hopefully make Kepler's astrodynamics work

## Thanks
Special thanks goes to [Kurzgesagt](https://www.youtube.com/c/inanutshell) - the channel which ignited my love for science after our school system dumped a bucket of water on it.
