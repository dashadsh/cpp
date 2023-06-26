#include <iostream>
#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");

    for (int i = 0; i < N; i++) {
        std::string name = "Zombie" + std::to_string(i);
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
