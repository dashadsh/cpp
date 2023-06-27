#include "Zombie.hpp"

// SIC! cpp file that contains only the implementation of the class function, not the class

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
	// zombie1 is created on the STACK
    Zombie zombie1("Foo");
    zombie1.announce();

	// zombie2 is allocated on the HEAP.
    Zombie* zombie2 = newZombie("Bar");
    zombie2->announce();
	// delete keyword  - deallocate memory
    delete zombie2;

	// func. to create a Zombie obj. on a STACK
	randomChump("XXX");

    return 0;
}
