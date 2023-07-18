/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:24:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 11:53:03 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main (void) 
{
    ClapTrap clap("CLAPPY");
    ClapTrap trap("TRAPPY");
    clap.setAttackDamage(1);
    trap.setAttackDamage(4);
    clap.attack("TRAPPY");
    trap.takeDamage(clap.getAttackDamage());
    for (int i = 0; i < 5; i++)
    {
        clap.attack("TRAPPY");
        trap.takeDamage(clap.getAttackDamage());
    }
    for (int i = 0; i < 3; i++)
    {
        trap.attack("CLAPPY");
        clap.takeDamage(trap.getAttackDamage());
    }
    clap.beRepaired(5);
}

///////////////////////////////////////////////

// int	main(void)	{
	
// 	{ ClapTrap d("sa");}

// 	ClapTrap	clap("clappy");
// 	ClapTrap	trap("trappy");

// 	clap.setAttackDamage(2);
// 	for (int i = 0; i < 11; i++)
// 		clap.attack("trappy");
// 	std::cout << "Clap attack damage: " << clap.getAttackDamage() << std::endl;
// 	//trap.operator=(clap);
// 	trap.attack("clappy");
// 	for (int i = 0; i < 3; i++)
// 	{
// 		trap.takeDamage(2);
// 		std::cout << "Trap hit point: " << trap.getHitPoints() << std::endl;
// 	}
// 	trap.beRepaired(5);
// 	std::cout << "Trap hit point: " << trap.getHitPoints() << std::endl;
// 	std::cout << "Trap energy point: " << trap.getEnergyPoints() << std::endl;
// }
// int main(void)
// {
//     ClapTrap a("A");
//     ClapTrap b("B");
//     ClapTrap C;
//     for(int i = 0; i < 10; i++)
//         a.attack("B");
//     a.takeDamage(3);
//     a.beRepaired(4);
// 	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
//     return(0);
// }

///////////////////////////////////////////////

// int main(void)
// {
//     ClapTrap a("A");
//     ClapTrap b("B");
// 	std::cout << std::endl;

//     a.attack("B");
// 	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
//     b.takeDamage(4);
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
// 	std::cout << std::endl;

//     b.beRepaired(2);
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
// 	std::cout << std::endl;
    
//     b.attack("A");
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
//     a.takeDamage(4);
// 	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
// 	std::cout << std::endl;

//     a.beRepaired(1);
// 	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
//     b.beRepaired(2);
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
// 	std::cout << std::endl;
//     return (0); 
// }

// SIC!
// the attack damage is always zero and never changes. 
// I could add a parameter to the constructor to set the attack damage?
// or you could create a setter method to change it?
