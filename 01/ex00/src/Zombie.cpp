/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 15:43:08 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Zombie.hpp"

// ------------------------------ CONSTRUCTOR ---------------------------------------
// constructor that creates a Zombie object with the given name.
// : name(name) - is the initializer list. 
// It initializes the name member of the Zombie object with the value 
// provided in the constructor parameter name. 
// It uses a technique called member initialization, 
// where the constructor parameters are directly assigned to the corresponding members.
Zombie::Zombie(std::string name) : name(name) {}

// ------------------------------ MEMBER FUNC. ---------------------------------------
// Function that announces the zombie by printing
void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// ------------------------------ DESTRUCTOR ---------------------------------------
// destructor
Zombie::~Zombie() {
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}
