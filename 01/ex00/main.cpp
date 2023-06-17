#include "Zombie.hpp"

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

	randomChump("XXX");

    return 0;
}
