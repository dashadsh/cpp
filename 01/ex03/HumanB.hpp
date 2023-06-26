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
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name; // Name of the human
    Weapon* weapon; // Pointer to the weapon held by the human

public:
    HumanB(std::string name); // Constructor to initialize the human's name
	~HumanB();
	
    void setWeapon(Weapon& weapon); // Member function to set the weapon for the human
    void attack(); // Member function for the human to attack
};




//---------------------------------------------------------------------------------------------
// class HumanB {
// private:
//     std::string name; // Name of the human
//     Weapon* weapon; // Pointer to the weapon held by the human

// public:
//     HumanB(const std::string& name); // Constructor to initialize the human's name
// 	~HumanB();

//     void setWeapon(Weapon& weapon); // Member function to set the weapon for the human
//     void attack() const; // Member function for the human to attack
// };

#endif

