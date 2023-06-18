
#include "Zombie.hpp"

Zombie* zombieHorde(int N) {
	// dynamically allocates an array of N Zombie objects 
    Zombie* horde = new Zombie[N];
	// points to the first Zombie object in the dynamically allocated array
    return horde;
}
