/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:15 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 12:39:59 by dgoremyk         ###   ########.fr       */
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
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name; // Name of the human
    Weapon* weapon; // Pointer to the weapon held by the human
	//  This pointer is initialized as nullptr in the constructor for HumanB:
	// HumanB::HumanB(std::string name) : name(name), weapon(nullptr)
	//
	// Later in setWeapon method for the HumanB class:
	// void HumanB::setWeapon(Weapon& weapon) {this->weapon = &weapon;}
	// This method takes a reference to a Weapon object and sets the weapon pointer 
	// in the HumanB object to point to this Weapon. 
	// After this method is called, the weapon pointer will no longer be nullptr, 
	// it will be pointing to the passed Weapon object.

public:
    HumanB(std::string name); // Constructor to initialize the human's name
//	HumanB(const std::string& name); // BETTER PRACTICE
	~HumanB();
	
    void setWeapon(Weapon& weapon); // Member function to set the weapon for the human
    void attack(); // Member function for the human to attack
//	void attack() const; // BETTER PRACTICE
};

#endif

