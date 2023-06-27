/////////////////////////////////////////////////////////////////////////////////////
// REF to Weapon: 
// In the HumanA class, a reference to Weapon is used because HumanA will always be armed. 
// The reference is initialized in the constructor and cannot be changed afterwards. 
//
// Using a reference ensures that HumanA objects always have a valid weapon 
// and simplifies the code by avoiding null checks.
//
// SIC! using a reference assumes that the referenced object will exist for the 
// entire lifetime of the object that holds the reference.
// If there's a possibility that the referenced object can be destroyed or changed 
// during the lifetime of the object, a PTR/smart PTR should be used instead.
/////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "HumanA.hpp"

// constructor 
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	// name parameter will be copied into the name member variable of the HumanA class
	// weapon parameter will be stored as a reference to the original Weapon object passed in
}

HumanA::~HumanA() {}

// display the human's name and the weapon type they are attacking with
void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

//---------------------------------------------------------------------------------------------
// HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {
//     // constructor
// }

// HumanA::~HumanA() {
// }

// void HumanA::attack() const {
//     std::cout << name << " attacks with their " << weapon.getType() << std::endl;
//     // Display the human's name and the weapon type they are attacking with
// }
