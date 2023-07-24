/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:25:21 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 17:20:17 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/DiamondTrap.hpp"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
implement a FragTrap class that inherits from ClapTrap. 
It is very similar to ScavTrap. However, its construction and destruction messages must be different. 
Proper construction/destruction chaining must be shown in your tests. 
When a FragTrap is created, the program starts by building a ClapTrap. Destruction is in reverse order.
Same things for the attributes, but with different values this time:
• Name, which is passed as parameter to a constructor 
• Hit points (100), represent the health of the ClapTrap 
• Energy points (100)
• Attack damage (30)
FragTrap has a special capacity too:
   void highFivesGuys(void);

diamond problem arises when a class inherits from two or more classes that share a common base class. 
this can lead to ambiguous member access, conflicting function implementations, and unexpected behavior.

we need to use virtual inheritance in the appropriate base classes. 
Virtual inheritance ensures there is only one shared instance of the common base class among the derived classes.

steps to avoid the diamond problem:

1. identify the classes that participate in the diamond problem 
(usually intermediate classes with shared base classes).

2. apply virtual inheritance to the common base class by using the virtual keyword when inheriting.

3. ensure that all intermediate classes inherit virtually from the common base class.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

// int	main(void)
// {
//     DiamondTrap    a("AAA");
//     DiamondTrap    b("BBB");
//     a.attack("BBB");
//     b.takeDamage(a.getAttackDamage());
//     b.beRepaired(2);
//     b.setAttackDamage(5);
//     b.attack(a.getName());
//     a.takeDamage(b.getAttackDamage());
//     b.highFivesGuys();
// 	   b.whoAmI();
// }

int	main(void)
{
	std::string partition(50, '-');

	// std::cout << partition << std::endl;
	// std::cout << "SCAVTRAP\n";
	// std::cout << partition << std::endl;
	// {
	// 	ScavTrap	scav("SCAVVY");
	// 	scav.attack("SOMEONE");
	// 	scav.takeDamage(1);
	// 	scav.guardGate();
	// 	scav.beRepaired(23);
	// 	std::cout << "SCAVVY energy points: " << scav.getEnergyPoints() << std::endl;
	// }
	// std::cout << partition << std::endl;
	// std::cout << "FRAGTRAP\n";
	// std::cout << partition << std::endl;
	// {
	// 	FragTrap frog;
	// 	frog.highFivesGuys();
	// 	std::cout << "name: " << frog.getName() << std::endl;
	// 	std::cout << "Frag attack damage: " << frog.getAttackDamage() << std::endl;
	// 	frog.attack("FROG");
	// 	frog.getAttackDamage();
	// 	FragTrap fraggy("FRAGGY");
	// 	fraggy.highFivesGuys();
	// 	fraggy.beRepaired(12);
	// }
	std::cout << partition << std::endl;
	std::cout << "DIAMONDTRAP\n";
	std::cout << partition << std::endl;
	{
		DiamondTrap diamond("DIAMONDY");
		std::cout << "Hit: " << diamond.getHitPoints() << std::endl;
		std::cout << "Energy: " << diamond.getEnergyPoints() << std::endl;
		std::cout << "Attack: " << diamond.getAttackDamage() << std::endl;
		std::cout << "Clap name: " << diamond.getName() << std::endl;
		diamond.attack("SOMEONE");
		diamond.whoAmI();
		// std::cout << "Hit: " << diamond.getHitPoints() << std::endl;
		// std::cout << "Energy: " << diamond.getEnergyPoints() << std::endl;
		// std::cout << "Attack: " << diamond.getAttackDamage() << std::endl;
		// std::cout << "Clap name: " << diamond.getName() << std::endl;
	}
	// 	std::cout << partition << std::endl;
	// std::cout << "DIAMONDTRAP 2\n";
	// std::cout << partition << std::endl;
	// {
	// 	DiamondTrap diamond;
	// 	diamond.attack("SOMEONE");
	// 	diamond.whoAmI();
	// 	std::cout << "Attack:" << diamond.getAttackDamage() << std::endl;
	// 	std::cout << "Hit: " << diamond.getHitPoints() << std::endl;
	// 	std::cout << "Energy: " << diamond.getEnergyPoints() << std::endl;
	// 	std::cout << "Clap name: " << diamond.getName() << std::endl;
	// }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* // DIAMOD PROBLEM
// common issue in C++ when a class inherits from two or more classes 
// that share a common base class, can lead to ambiguity in how certain members 
// and functions are accessed

 // Base class
class Animal {
public:
    void speak() { std::cout << "Animal speaks!" << std::endl; }
};

// Intermediate classes
class Mammal : public Animal {
public:
    void breathe() { std::cout << "Mammal breathes!" << std::endl; }
};

class Bird : public Animal {
public:
    void fly() { std::cout << "Bird flies!" << std::endl; }
};

// Diamond problem occurs here
class Bat : public Mammal, public Bird {
};

int main() {
    Bat bat;
    bat.speak(); // Ambiguity - which 'speak' to call?
    // bat.breathe(); // Error - ambiguous function call
    // bat.fly(); // Error - ambiguous function call

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Base class
class Animal {
public:
    void speak() { std::cout << "Animal speaks!" << std::endl; }
};

// Intermediate classes with virtual inheritance
class Mammal : virtual public Animal {
public:
    void breathe() { std::cout << "Mammal breathes!" << std::endl; }
};

class Bird : virtual public Animal {
public:
    void fly() { std::cout << "Bird flies!" << std::endl; }
};

// No diamond problem occurs here due to virtual inheritance
class Bat : public Mammal, public Bird {
};

int main() {
    Bat bat;
    bat.speak(); // No ambiguity - calls Animal's 'speak'
    bat.breathe(); // No ambiguity - calls Mammal's 'breathe'
    bat.fly(); // No ambiguity - calls Bird's 'fly'

    return 0;
}

// In this example, both Mammal and Bird virtually inherit from Animal. 
// As a result, when Bat inherits from both Mammal and Bird, 
// there is only one shared instance of the Animal base class. 
// This resolves the diamond problem, and the code no longer suffers from 
// ambiguity and compilation errors.
*/