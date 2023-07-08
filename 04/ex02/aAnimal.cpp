/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:59:39 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/06 16:52:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

/*
 * SIC! there is no implementation for the makeSound function,
 * bc it is a pure virtual function. 
 * 
 * It must be implemented in each subclass of AAnimal !!!
 */

// Default constructor
AAnimal::AAnimal() : name("Animal") {
    std::cout << "An abstract animal is conceptualized." << std::endl;
}

// Parameterized constructor
AAnimal::AAnimal(const std::string& name) : name(name) {
    std::cout << "An abstract animal called " << name << " is conceptualized." << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) : name(other.name) {
    std::cout << "An abstract animal called " << other.name << " is conceptualized from another." << std::endl;
}

// Assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
    if (this != &other) {
        name = other.name;
    }
    std::cout << "An abstract animal changed its form to be like " << other.name << std::endl;
    return *this;
}

// Destructor
AAnimal::~AAnimal() {
    std::cout << "The abstract concept of the animal " << name << " fades away." << std::endl;
}

// Getter for name
std::string AAnimal::getName() const {
    return name;
}

// Setter for name
void AAnimal::setName(const std::string& name) {
    std::cout << "The abstract animal changes its name from " << this->name << " to " << name << std::endl;
    this->name = name;
}
