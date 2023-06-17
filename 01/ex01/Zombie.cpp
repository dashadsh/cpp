
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}
