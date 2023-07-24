/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:21 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 16:39:09 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"

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


int main () 
{
    FragTrap    a("AAA");
    FragTrap    b("BBB");
    a.attack("BBB");
    b.takeDamage(a.getAttackDamage());
    b.beRepaired(2);
    b.setAttackDamage(5);
    b.attack(a.getName());
    a.takeDamage(b.getAttackDamage());
    b.highFivesGuys();
}
// int main() {

// 	ClapTrap a("A");
//     ScavTrap b("B");
// 	FragTrap c("C");
// 	std::cout << std::endl;

// 	a.attack("D");
// 	b.attack("A");
//     b.guardGate();
// 	c.highFivesGuys();
// 	std::cout << std::endl;

// 	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
// 	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
// 	std::cout << c.getName() << ": " << c.getAttackDamage() << " damage points, " << c.getEnergyPoints() << " energy points, " << c.getHitPoints() << " hit points." << std::endl;

// 	std::cout << std::endl;

//     return 0;

// }

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