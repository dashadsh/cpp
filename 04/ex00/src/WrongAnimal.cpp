/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:45:35 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:50:38 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): _type("WrongAnimal") {
    std::cout << "WrongAnimal created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    *this = src;
    std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
    if (this != &src) {
        this->_type = src._type;
    }
	std::cout << "WrongAnimal's assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes no sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}

// void    WrongAnimal::setType(std::string type) {
//     _type = type;
// }
