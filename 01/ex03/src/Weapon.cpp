/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:26 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/09 22:26:03 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

// ------------------------------ CONSTRUCTOR ---------------------------------------
Weapon::Weapon(std::string someType) : type(someType) {
// Weapon::Weapon(const std::string& type) : type(type) { // BETTER PRACTICE
	// will copy passed parameter to the 'type' variable
}

// ------------------------------ DESTRUCTOR ---------------------------------------
Weapon::~Weapon() {}


// ------------------------------ MEMBER FUNC. ---------------------------------------
// return weapon type
const std::string& Weapon::getType() const {
    return type;
}

// set weapon type using new type passed as a param.
void Weapon::setType(std::string newType) {
// void Weapon::setType(const std::string& newType) { // BETTER PRACTICE
    this->type = newType;
}
