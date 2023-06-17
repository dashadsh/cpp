#include "Zombie.hpp"

Zombie* zombieHorde(int N);

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N);

    for (int i = 0; i < N; i++) {
        std::string name = "Zombie" + std::to_string(i);
        horde[i].setName(name);
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
