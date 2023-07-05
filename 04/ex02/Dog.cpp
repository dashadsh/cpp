/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:03:43 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:14:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

// constructor takes a name for the dog, defaults to "Dog"
Dog::Dog(const std::string& name) : AAnimal(name), _brain(new Brain()) {
    std::cout << "Dog created" << std::endl;
}

// copy constructor
Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*(other._brain))) {
    std::cout << "Dog copied" << std::endl;
}

// assignment operator
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete _brain;
        _brain = new Brain(*(other._brain));
    }
    return *this;
}

// destructor
Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

// makeSound function is specific to Dogs - outputs a "Bark!" message.
void Dog::makeSound() const {
    std::cout << name << " says: Bark!" << std::endl;
}

// Set the dog's thought
void Dog::setThought(int idx, const std::string& thought) {
    _brain->setIdea(idx, thought);
}

// Get the dog's thought
std::string Dog::getThought(int idx) const {
    return _brain->getIdea(idx);
}
