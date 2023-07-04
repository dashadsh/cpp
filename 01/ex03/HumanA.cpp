/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:03 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:22:04 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// ------------------------------ CONSTRUCTOR ---------------------------------------
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) { 
// HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) { // BETTER PRACTICE
	// name parameter will be copied into the name member variable of the HumanA class
	// weapon parameter will be stored as a reference to the original Weapon object passed in
}

// ------------------------------ DESTRUCTOR ---------------------------------------
HumanA::~HumanA() {}

// ------------------------------ MEMBER FUNC. ---------------------------------------
// display the human's name and the weapon type they are attacking with
void HumanA::attack() {
// void HumanA::attack() const // BETTER PRACTICE
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
