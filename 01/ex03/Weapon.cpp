#include "Weapon.hpp"

// constructor
Weapon::Weapon(std::string someType) : type(someType) {
	// will copy passed parameter to the 'type' variable
}

Weapon::~Weapon() {}

// return weapon type
std::string Weapon::getType() {
    return type;
}

// set weapon type using new type passed as a param.
void Weapon::setType(std::string newType) {
    this->type = newType;
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
