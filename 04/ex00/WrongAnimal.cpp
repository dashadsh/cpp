/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:45:35 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:45:56 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

// default constructor  - initializes type to "WrongAnimal"
WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
    std::cout << "WrongAnimal created" << std::endl;
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    *this = src;
    std::cout << "WrongAnimal copied" << std::endl;
}

// destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

// assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

// function to make a sound (this should be overridden by subclasses)
void WrongAnimal::makeSound() const {
    std::cout << "The WrongAnimal makes a wrong sound" << std::endl;
}

// getter for the type of the wrong animal
std::string WrongAnimal::getType() const {
    return _type;
}
