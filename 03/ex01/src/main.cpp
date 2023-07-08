/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:24:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 19:27:23 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// create a derived robot. 
// It will be named ScavTrap and will inherit the constructors and destructor from Clap- Trap. 
// Its constructors, destructor and attack() will print different messages.

// Note that proper construction/destruction chaining must be shown in your tests. W
// hen a ScavTrap is created, the program starts by building a ClapTrap. 
// Destruction is in reverse order. WHY?

// ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and must initialize them to:
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)
// ScavTrap will also have its own special capacity:
//    void guardGate();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ---------------------- reversed destruction order -------------------------------------------------------------------------------
// When a derived object (ScavTrap) is created, the base object (ClapTrap) must first be constructed bc the derived object can 
// rely on the base obj. being properly initialized. 
// Derived object's construction begins with its base class's constructor.
// Reverse order during destruction is due to the principle of Resource Acquisition Is Initialization (RAII), which is fundamental in C++. 
// When an obj. of a derived class is destroyed, destructor of the derived class gets executed first bc it may have to clean up
// resources that depend on the base class.
// Only after that can the base class destructor safely run, as it may clean up resources that the derived class destructor may depend on. 
// This is why destruction happens in the reverse order of construction.

int main(void)
{
	ClapTrap a("A");
	ScavTrap b("B");
	std::cout << std::endl;

    a.attack("C");
    a.takeDamage(6);
	std::cout << std::endl;

	b.attack("A");
	b.beRepaired(3);
	std::cout << std::endl;

    a.attack("B");
	b.takeDamage(6);
	std::cout << std::endl;

    b.guardGate();
	std::cout << std::endl;

	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
    std::cout << std::endl;

	return(0);
}

// int main(void) {
//     ScavTrap robot1("ROBOT1");
//     ScavTrap robot2("ROBOT2");

//     std::cout << std::endl;

//     robot1.attack("ROBOT2");
//     robot2.takeDamage(20);
//     robot2.attack("ROBOT1");
//     robot1.takeDamage(robot2.getAttackDamage());

//     std::cout << std::endl;
//     std::cout << "STATUS" << std::endl;
//     std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
//     std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
//     std::cout << std::endl;

//     robot1.beRepaired(2);
//     robot2.beRepaired(10);

//     std::cout << std::endl;
//     std::cout << "STATUS" << std::endl;
//     std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
//     std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
//     std::cout << std::endl;

//     robot1.attack("ROBOT2");
//     robot2.takeDamage(robot1.getAttackDamage());
//     std::cout << std::endl;
//     robot2.attack("ROBOT1");
//     robot1.takeDamage(robot2.getAttackDamage());

//     std::cout << std::endl;
//     std::cout << "STATUS" << std::endl;
//     std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
//     std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
//     std::cout << std::endl;

//     robot1.guardGate();
//     robot2.guardGate();

//     return 0;
// }
