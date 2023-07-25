/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:41:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 00:59:05 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>

// default constructor
Dog::Dog(): Animal() {
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog created" << std::endl;
}

// copy constructor
Dog::Dog(const Dog& src): Animal(src) {
    this->_brain = new Brain(*src._brain);
    std::cout << "Dog copied" << std::endl;
}

// destructor
Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destroyed" << std::endl;
}

// assignment operator
Dog& Dog::operator=(const Dog& src) {
    if (this != &src) {
        Animal::operator=(src);
        delete this->_brain;
        this->_brain = new Brain(*src._brain);
    }
	std::cout << "Dog's assignment operator called" << std::endl;
    return *this;
}

// funct. to make dog sound - remains unchanged
void Dog::makeSound() const {
    std::cout << "The dog barks" << std::endl;
}

// set a thought (or an idea) into the Brain object of a specific animal at a specific index
void Dog::setThought(int idx, const std::string& thought) {
    this->_brain->setIdea(idx, thought);
}

std::string Dog::getThought(int idx) const {
    return this->_brain->getIdea(idx);
}
