/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:19:21 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 14:32:42 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice& src) : AMateria("ice") {
	std::cout << "Ice copy constructor called." << std::endl;
	*this = src;
}

Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}

Ice& Ice::operator=(const Ice& src) {
	std::cout << "Ice assignment operator called." << std::endl;
	this->_type = src._type;
	return *this;
}

AMateria* Ice::clone() const {
	// AMateria* iceClone = new Ice();
	// return iceClone;
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
