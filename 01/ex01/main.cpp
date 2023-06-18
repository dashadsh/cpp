#include "Zombie.hpp"

Zombie* zombieHorde(int N);

int main() {
    int N = 5;
	// dynamically allocates an array of N Zombie objects 
    // points to the first Zombie object in the dynamically allocated array
	Zombie* horde = zombieHorde(N);

    for (int i = 0; i < N; i++) {
		// Constructs a name for each zombie using the value of i. 
		// First zombie's name will be "Zombie0", 
		// the second zombie's name will be "Zombie1" etc. 
        std::string name = "Zombie" + std::to_string(i);
        horde[i].setName(name);
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
