/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:02:22 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/05 15:15:41 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Constructor takes a name for the cat, defaults to "Cat"
Cat::Cat(const std::string& name) : AAnimal(name), _brain(new Brain()) {
    std::cout << "Cat created" << std::endl;
}

// copy constructor
Cat::Cat(const Cat& other) : AAnimal(other), _brain(new Brain(*(other._brain))) {
    std::cout << "Cat copied" << std::endl;
}

// assignment operator
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete _brain;
        _brain = new Brain(*(other._brain));
    }
    return *this;
}

// destructor
Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}

// makeSound function is specific to Cats - outputs a "Meow!" message
void Cat::makeSound() const {
    std::cout << name << " says: Meow!" << std::endl;
}

// Set the cat's thought
void Cat::setThought(int idx, const std::string& thought) {
    _brain->setIdea(idx, thought);
}

// Get the cat's thought
std::string Cat::getThought(int idx) const {
    return _brain->getIdea(idx);
}