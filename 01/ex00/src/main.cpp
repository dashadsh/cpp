/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:21:09 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 15:42:53 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

// SIC! .cppfile contains only implementation of class function, not the class

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

int main() {
	// zombie1 is created on the STACK
    Zombie zombie1("Foo");
    zombie1.announce();

	// check newZombie.cpp:
	// zombie2 is allocated on the HEAP.
	// memory is allocated with 'new' keyword
    Zombie* zombie2 = newZombie("Bar");
    zombie2->announce();
    delete zombie2; // delete keyword  - deallocate memory


	// check randomChump.cpp:
	// func. to create a Zombie obj. on a STACK
	randomChump("XXX");

    return 0;
}
