/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:21 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 11:37:13 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/DiamondTrap.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// implement a FragTrap class that inherits from ClapTrap. 
// It is very similar to ScavTrap. However, its construction and destruction messages must be different. 
// Proper construction/destruction chaining must be shown in your tests. 
// When a FragTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order.
// Same things for the attributes, but with different values this time:
// • Name, which is passed as parameter to a constructor 
// • Hit points (100), represent the health of the ClapTrap 
// • Energy points (100)
// • Attack damage (30)
// FragTrap has a special capacity too:
//    void highFivesGuys(void);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "SCAVTRAP\n";
	std::cout << partition << std::endl;
	{
		ScavTrap	scav("SCAVVY");
		scav.attack("SOMEONE");
		scav.takeDamage(1);
		scav.guardGate();
		scav.beRepaired(23);
		std::cout << "SCAVVY energy points: " << scav.getEnergyPoints() << std::endl;
	}
	std::cout << partition << std::endl;
	std::cout << "FRAGTRAP\n";
	std::cout << partition << std::endl;
	{
		FragTrap frog;
		frog.highFivesGuys();
		std::cout << "name: " << frog.getName() << std::endl;
		std::cout << "Frag attack damage: " << frog.getAttackDamage() << std::endl;
		frog.attack("FROG");
		frog.getAttackDamage();
		FragTrap fraggy("FRAGGY");
		fraggy.highFivesGuys();
		fraggy.beRepaired(12);
	}
	std::cout << partition << std::endl;
	std::cout << "DIAMONDTRAP\n";
	std::cout << partition << std::endl;
	{
		DiamondTrap diamond("DIAMONDY");
		diamond.attack("SOMEONE");
		diamond.whoAmI();
		std::cout << "Attack:" << diamond.getAttackDamage() << std::endl;
		std::cout << "Hit: " << diamond.getHitPoints() << std::endl;
		std::cout << "Energy: " << diamond.getEnergyPoints() << std::endl;
		std::cout << "Clap name: " << diamond.getName() << std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// int main() {

// 	ClapTrap a("A");
//     ScavTrap b("B");
// 	FragTrap c("C");
// 	DiamondTrap d("D");
// 	std::cout << std::endl;

// 	a.attack("D");
// 	b.attack("A");
//     b.guardGate();
// 	c.highFivesGuys();
// 	d.attack("A");
//     d.whoAmI();
// 	std::cout << std::endl;

// 	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
// 	std::cout << c.getName() << ": " << c.getAttackDamage() << " damage points, " << c.getEnergyPoints() << " energy points, " << c.getHitPoints() << " hit points." << std::endl;

// 	std::cout << std::endl;

//     return 0;

// }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// int main(void) {

// 	FragTrap robot3("ROBOT3");

// 	std::cout << std::endl;

// 	robot3.attack("ROBOT1");
// 	robot3.takeDamage(20);
// 	robot3.attack("ROBOT2");
// 	robot3.highFivesGuys();

// 	std::cout << std::endl;
// 	std::cout << "STATS" << std::endl;
// 	std::cout << robot3.getName() << ": " << robot3.getAttackDamage() << " damage points, " << robot3.getEnergyPoints() << " energy points, " << robot3.getHitPoints() << " hit points." << std::endl;
// 	std::cout << std::endl;

// 	robot3.beRepaired(2);

// 	std::cout << std::endl;
// 	std::cout << "STATS" << std::endl;
// 	std::cout << robot3.getName() << ": " << robot3.getAttackDamage() << " damage points, " << robot3.getEnergyPoints() << " energy points, " << robot3.getHitPoints() << " hit points." << std::endl;
// 	std::cout << std::endl;

// 	robot3.highFivesGuys();

// 	return 0;

// }

// ------------------- new compiler flags - for ex03 ----------------------------------
// -Wshadow: 
// enables a compiler warning when one variable shadows another. 
// Shadowing occurs when a variable declared within a certain scope has the same name as a variable declared in an outer scope. 
// When the variable with the same name is used, it refers to the innermost scoped variable, "shadowing" the variable in the outer scope. 
// The warning helps to catch situations where this might be occurring unintentionally, which could lead to bugs that are difficult to find.
// Example where -Wshadow would give a warning:
// int x = 5;
// if (true) {
//     int x = 10; // this declaration shadows the outer 'x'
//     std::cout << x; // prints '10', not '5'
// }
//
// -Wno-shadow: 
// disables the shadowing warning. 
// Useful if you're deliberately using shadowing and don't want the compiler to warn you about it.