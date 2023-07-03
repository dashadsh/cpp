#include "Weapon.hpp"

// ------------------------------ CONSTRUCTOR ---------------------------------------
Weapon::Weapon(std::string someType) : type(someType) {
// Weapon::Weapon(const std::string& type) : type(type) { // BETTER PRACTICE
	// will copy passed parameter to the 'type' variable
}

// ------------------------------ DESTRUCTOR ---------------------------------------
Weapon::~Weapon() {}


// ------------------------------ MEMBER FUNC. ---------------------------------------
// return weapon type
std::string Weapon::getType() {
// const std::string& Weapon::getType() const { // BETTER PRACTICE
    return type;
}

// set weapon type using new type passed as a param.
void Weapon::setType(std::string newType) {
// void Weapon::setType(const std::string& newType) { // BETTER PRACTICE
    this->type = newType;
}
