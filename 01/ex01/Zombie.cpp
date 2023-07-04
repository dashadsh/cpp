/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:21:42 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// ------------------------------ CONSTRUCTOR ---------------------------------------
Zombie::Zombie() {}

// ------------------------------ DESTRUCTOR ---------------------------------------
Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

// ------------------------------ MEMBER FUNC. ---------------------------------------
// member function takes a std::string parameter name and sets the name of the Zombie object to the provided value
void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
