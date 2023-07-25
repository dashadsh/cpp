/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:47:12 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/25 01:50:49 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src) {
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
    if (this != &src) {
        WrongAnimal::operator=(src);
    }
	std::cout << "WrongCat's assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat makes no sound" << std::endl;
}
