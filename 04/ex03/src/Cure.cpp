/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 14:36:45 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure& src) : AMateria("cure") {
	std::cout << "Cure copy constructor called." << std::endl;
	*this = src;
}

Cure::~Cure() {
	std::cout << "Cure destructor called." << std::endl;
}

Cure& Cure::operator=(const Cure& src) {
	std::cout << "Cure assignment operator called." << std::endl;
	this->_type = src._type;
	return *this;
}

AMateria* Cure::clone() const {
	// AMateria* cureClone = new Cure();
	// return cureClone;
	return new Cure(*this);
}
// new Cure object is created using the default constructor, 
// meaning that member variables are initialized to their default values 
// (if any) and any dynamic memory allocated in the original Cure object 
// is not copied to the new object.
// -------------
// BETTER:
// new Cure object is created as an exact copy of the current Cure object. 
// all member variables and their values, as well as any dynamic memory allocated 
// in the original Cure object, are duplicated in the new object.

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
