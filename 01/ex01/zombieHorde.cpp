#include "Zombie.hpp"

// dynamically allocates an array of N Zombie objects 
// points to the first Zombie object in the dynamically allocated array
Zombie* zombieHorde(int N, std::string name) {

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i].setName(name + std::to_string(i));
    }

    return horde;
}
