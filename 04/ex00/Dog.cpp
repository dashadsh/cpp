/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:41:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:05 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

// default constructor - sets type to "Dog"
Dog::Dog(): Animal() {
    this->_type = "Dog";
    std::cout << "Dog created" << std::endl;
}

// copy constructor
Dog::Dog(const Dog& src): Animal(src) {
    std::cout << "Dog copied" << std::endl;
}

// destructor
Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

// assignment operator
Dog& Dog::operator=(const Dog& src) {
    if (this != &src) {
        Animal::operator=(src);
    }
	std::cout << "Dog's assignment operator called" << std::endl;
    return *this;
}

// funct. to make dog sound
void Dog::makeSound() const {
    std::cout << "The dog barks" << std::endl;
}
