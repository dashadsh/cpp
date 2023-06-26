#include "Weapon.hpp"

// constructor
Weapon::Weapon(std::string type) : type(std::move(type)) {}

Weapon::~Weapon() {}

// Return the weapon type
std::string Weapon::getType() {
    return type;
}

// Set the weapon type using the new type passed as a parameter
void Weapon::setType(std::string newType) {
    type = std::move(newType);
}

//---------------------------------------------------------------------------------------------
// Weapon::Weapon(const std::string& type) : type(type) {
// }

// Weapon::~Weapon() {
// }

// const std::string& Weapon::getType() const {
//     return type; // Return a const reference to the weapon type
// }

// void Weapon::setType(const std::string& newType) {
//     type = newType; // Set the weapon type using the new type passed as a parameter
// }
