/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:43:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 00:13:32 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>

Cat::Cat(): Animal() {
    this->_type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src) {
    std::cout << "Cat copied" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
    if (this != &src) {
        Animal::operator=(src);
    }
	std::cout << "Cat's assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "The cat meows" << std::endl;
}
