/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:37:49 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:50:12 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>

// ------------ CONSTR / DESTR ----------------------
Animal::Animal(): _type("Animal") {
    std::cout << "Animal created" << std::endl;
}
/* uses an initialization list to set the _type member variable directly 
when the object is created. 
Initialization lists are generally considered more efficient for initializing 
member variables, especially for non-primitive types. 
It directly assigns the value to _type, avoiding an extra function call.

Compare to: Animal::Animal() {
    std::cout << "Animal default constructor called.\n";
    this->setType("Animal");
}
*/

Animal::Animal(const Animal& src) {
    *this = src;
    std::cout << "Animal copied" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

// ------------ assignment operator ----------------------
Animal& Animal::operator=(const Animal& src) {
    if (this != &src) {
        this->_type = src._type;
    }
	std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

// ------------ member func.-------------------------------
std::string Animal::getType() const {
    return _type;
}

// void    Animal::setType(std::string type) {
//     _type = type;
// }

void Animal::makeSound() const {
    std::cout << "Animal makes no sound" << std::endl;
}