#include "Zombie.hpp"

void randomChump(std::string name) {
    // create a Zombie object on a STACK
	Zombie zombie(name);
    zombie.announce();
}
