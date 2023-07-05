/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:37:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:43:38 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

// ------------ CONSTR / DESTR ----------------------
// default constructor - initializes type to "Animal"
Animal::Animal(): _type("Animal") {
    std::cout << "Animal created" << std::endl;
}

// copy constructor
// This constructor performs a deep copy of the object.
Animal::Animal(const Animal& src) {
    *this = src;
    std::cout << "Animal copied" << std::endl;
}

// destructor
Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

// ------------ assignment operator ----------------------
// assignment operator
// This operator performs a deep copy of the object.
Animal& Animal::operator=(const Animal& src) {
    if (this != &src) {
        this->_type = src._type;
    }
	std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

// ------------ member func.-------------------------------
// func. to make sound (this should be overridden by sub-class!)
void Animal::makeSound() const {
    std::cout << "The animal makes a sound" << std::endl;
}

// getter - get type of animal
std::string Animal::getType() const {
    return _type;
}
