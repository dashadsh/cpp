/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:22:18 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 15:51:26 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"
#include "../inc/Weapon.hpp"


// QUESTION - if i comment out jim.setWeapon(club); - 
// should club.setType("some other type of club"); still work??

int main() {
	{
    	Weapon club = Weapon("crude spiked club");
    	HumanA bob("Bob", club);
    	bob.attack();
    	club.setType("some other type of club");
    	bob.attack(); 
	} 

	{
		Weapon  club = Weapon("crude spiked club");
		HumanB jim("Jim");
	// setWeapon() func. takes a REF to a Weapon obj & assigns it to the weapon PTR,
	// this allows the HumanB obj. to be armed with specified weapon & perform attacks correctly
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack(); 
	}

return 0;

}