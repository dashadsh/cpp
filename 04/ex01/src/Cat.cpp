/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:43:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/09 21:46:49 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>

// default constructor - sets type to "Cat"
Cat::Cat(): Animal() {
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat created" << std::endl;
}
// // OLD VERSION
// Cat::Cat(): Animal() {
//     this->_type = "Cat";
//     std::cout << "Cat created" << std::endl;
// }

// copy constructor
Cat::Cat(const Cat& src): Animal(src) {
    this->_brain = new Brain(*src._brain);
    std::cout << "Cat copied" << std::endl;
}
// // OLD VERSION
// Cat::Cat(const Cat& src): Animal(src) {
//     std::cout << "Cat copied" << std::endl;
// }

// destructor
Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destroyed" << std::endl;
}
// // OLD VERSION
// Cat::~Cat() {
//     std::cout << "Cat destroyed" << std::endl;
// }

// assignment operator
Cat& Cat::operator=(const Cat& src) {
    if (this != &src) {
        Animal::operator=(src);
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
	std::cout << "Cat's assignment operator called" << std::endl;
    return *this;
}
// // OLD VRESION
// Cat& Cat::operator=(const Cat& src) {
//     if (this != &src) {
//         Animal::operator=(src);
//     }
//     return *this;
// }

// function to make cat sounds - UNCHANGED
void Cat::makeSound() const {
    std::cout << "The cat meows" << std::endl;
}

// void Cat::think(int idx, const std::string& thought) {
//     this->_brain->setIdea(idx, thought);
// }

// by renaming think to setThought - becomes more apparent that this method 
// is used to set a thought (or an idea) into the Brain object of a specific animal, 
// at a specific index
void Cat::setThought(int idx, const std::string& thought) {
    this->_brain->setIdea(idx, thought);
}

std::string Cat::getThought(int idx) const {
    return this->_brain->getIdea(idx);
}