/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:41:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 00:12:23 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
    this->_type = "Dog";
    std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src) {
    std::cout << "Dog copied" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
    if (this != &src) {
        Animal::operator=(src);
    }
	std::cout << "Dog's assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "The dog barks" << std::endl;
}
