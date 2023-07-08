/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:11 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 20:30:44 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "../inc/HumanB.hpp"

// ------------------------------ CONSTRUCTOR ---------------------------------------
// weapon PTR is initialized to nullptr, so
// it doesn't currently point to any valid memory address.
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
// HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) // BETTER PRACTICE
// name parameter will be copied into the name member variable of the HumanB class
}

// ------------------------------ DESTRUCTOR ---------------------------------------
HumanB::~HumanB() {}

// ------------------------------ MEMBER FUNC. ---------------------------------------
void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon; // set the weapon pointer to the address of the passed weapon object
}

// nullptr - allows us to check if the HumanB obj. is currently unarmed. 
// condition checks if the weapon PTR is nullptr before attempting to access the weapon:
void HumanB::attack() {
// void HumanB::attack() const // BETTER PRACTICE
// checking if the weapon pointer is nullptr =>
// we can determine if the HumanB object has a valid weapon assigned/is unarmed. 
    if (weapon != NULL) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        // display human's name + weapon type they are attacking with
    } else {
        std::cout << name << " is unarmed and cannot attack!" << std::endl;
		// If the weapon PTR is nullptr =>
		// display a mssg that the HumanB obj is unarmed & cannot attack.
    }
}
// later in the main(), after creating the HumanB object jim, 
// a weapon is assigned to it using the setWeapon() func.

