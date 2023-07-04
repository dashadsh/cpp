/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:21:19 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// dynamically allocates memory for a Zombie obj on the heap, 
// init. it with the provided name, returns a PTR to the created Zombie obj. 

// This allows you to create Zombie obj's with dynamic memory allocation and 
// access them outside the scope of the newZombie func.

Zombie* newZombie(std::string name) {
	// allocates memory on the heap
    Zombie* zombie = new Zombie(name);
    return zombie;
}
