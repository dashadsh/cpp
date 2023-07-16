/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/11 22:22:00 by dgoremyk         ###   ########.fr       */
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
	AMateria* cureClone = new Cure();
	return cureClone;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
