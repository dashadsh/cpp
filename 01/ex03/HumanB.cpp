/////////////////////////////////////////////////////////////////////////////////////
// PTR to Weapon: 
// In the HumanB class, a pointer to Weapon is used bc HumanB may not always have a weapon. 
// By using a pointer, the weapon can be assigned dynamically and be set to nullptr 
// when the HumanB object is unarmed. 
//
// This allows for flexibility in assigning and changing the weapon during the obj's lifetime.
//
// SIC! using a reference assumes that the referenced object will exist for the 
// entire lifetime of the object that holds the reference.
// If there's a possibility that the referenced object can be destroyed or changed 
// during the lifetime of the object, a PTR/smart PTR should be used instead.
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "HumanB.hpp"

// weapon PTR is initialized to nullptr, so
// it doesn't currently point to any valid memory address.
HumanB::HumanB(std::string name) : name(std::move(name)), weapon(nullptr) {
    // constructor
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon; // Set the weapon pointer to the address of the passed weapon object
}

// usage of nullptr is important because it allows us to check if the HumanB obj.
// is currently unarmed. 
// There is a condition that checks if the weapon 
// PTR is nullptr before attempting to access the weapon:
void HumanB::attack() {
	// By checking if the weapon pointer is nullptr, 
	// we can determine if the HumanB object has a valid weapon assigned to it or if it is unarmed. 
    if (weapon != nullptr) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        // Display the human's name and the weapon type they are attacking with
    } else {
        std::cout << name << " is unarmed and cannot attack!" << std::endl;
        // Display a message indicating that the human is unarmed
		// If the weapon pointer is nullptr, 
		// we display a message indicating that the HumanB object is unarmed and cannot attack.
    }
}
// Later in the main() function, 
// after creating the HumanB object jim, a weapon is assigned to it using the setWeapon() function.


// --------------------------------------------------------------------------------------------
// HumanB::HumanB(const std::string& name) : name(name), weapon(nullptr) {
//     // Constructor implementation
// }

// HumanB::~HumanB() {
// }

// void HumanB::setWeapon(Weapon& weapon) {
//     this->weapon = &weapon; // Set the weapon pointer to the address of the passed weapon object
// }

// void HumanB::attack() const {
//     if (weapon != nullptr) {
//         std::cout << name << " attacks with their " << weapon->getType() << std::endl;
//         // Display the human's name and the weapon type they are attacking with
//     } else {
//         std::cout << name << " is unarmed and cannot attack!" << std::endl;
//         // Display a message indicating that the human is unarmed
//     }
// }
