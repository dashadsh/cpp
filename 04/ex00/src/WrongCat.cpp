/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:47:12 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/09 21:44:41 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>

// def. constructor - sets type to "WrongCat"
WrongCat::WrongCat(): WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

// copy constructor
WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src) {
    std::cout << "WrongCat copied" << std::endl;
}

// destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

// assignment operator
WrongCat& WrongCat::operator=(const WrongCat& src) {
    if (this != &src) {
        WrongAnimal::operator=(src);
    }
	std::cout << "WrongCat's assignment operator called" << std::endl;
    return *this;
}

// func. to make WrongCat sound
void WrongCat::makeSound() const {
    std::cout << "The WrongCat makes a wrong sound" << std::endl;
}
