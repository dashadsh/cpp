
#include <iostream>
#include "Zombie.hpp"

// constructor
Zombie::Zombie() {}

// member function takes a std::string parameter name and sets the name of the Zombie object to the provided value
void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}
