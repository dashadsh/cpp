/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:12:53 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/11 22:21:25 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() : _type("unknown") {
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& src) : _type(src._type) {
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "AMateria type constructor called." << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& src) {
	std::cout << "AMateria assignment operator overload called." << std::endl;
	if (this != &src) {
		this->_type = src._type;
	}
	return *this;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* An unknown materia is being used against "
		<< target.getName() << " *" << std::endl;
}

const std::string& AMateria::getType() const {
	return this->_type;
}

