/////////////////////////////////////////////////////////////////////////////////////
// Reference to Weapon: 
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
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name; // Name of the human
    Weapon& weapon; // Reference to the weapon held by the human

public:
    HumanA(std::string name, Weapon& weapon); // Constructor to init. the human's name & weapon
//	HumanA(const std::string& name, Weapon& weapon); // BETTER PRACTICE

	~HumanA();
	
    void attack(); // Member function for the human to attack
//	void attack() const; // BETTER PRACTICE
};

#endif

