
#include "Zombie.hpp"

// dynamically allocates memory for a Zombie object on the heap, 
// initializes it with the provided name, 
// and returns a pointer to the created Zombie object. 
// This allows you to create Zombie objects with dynamic memory allocation and 
// access them outside the scope of the newZombie function.
Zombie* newZombie(std::string name) {
	// allocates memory on the heap
    Zombie* zombie = new Zombie(name);
    return zombie;
}
