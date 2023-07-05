/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:43:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:44:24 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

// default constructor - sets type to "Cat"
Cat::Cat(): Animal() {
    this->_type = "Cat";
    std::cout << "Cat created" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& src): Animal(src) {
    std::cout << "Cat copied" << std::endl;
}

// destructor
Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

// assignment operator
Cat& Cat::operator=(const Cat& src) {
    if (this != &src) {
        Animal::operator=(src);
    }
	std::cout << "Cat's assignment operator called" << std::endl;
    return *this;
}

// function to make cat sounds
void Cat::makeSound() const {
    std::cout << "The cat meows" << std::endl;
}
