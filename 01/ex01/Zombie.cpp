#include <iostream>
#include "Zombie.hpp"

// ------------------------------ CONSTRUCTOR ---------------------------------------
Zombie::Zombie() {}

// ------------------------------ DESTRUCTOR ---------------------------------------
Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

// ------------------------------ MEMBER FUNC. ---------------------------------------
// member function takes a std::string parameter name and sets the name of the Zombie object to the provided value
void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
