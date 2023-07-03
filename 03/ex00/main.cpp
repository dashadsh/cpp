#include "ClapTrap.hpp"

// SIC!
// the attack damage is always zero and never changes. 
// I could add a parameter to the constructor to set the attack damage?
// or you could create a setter method to change it?
int main(void)
{
	ClapTrap robot1("ROBOT1");
	ClapTrap robot2("ROBOT2");

	std::cout << std::endl;

	robot1.attack("ROBOT2");
	robot2.takeDamage(20);
	robot2.attack("ROBOT1");

	std::cout << std::endl;
	std::cout << "STATS" << std::endl;
	std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
	std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

	robot1.beRepaired(2);
	robot2.beRepaired(0);

	std::cout << std::endl;
	std::cout << "STATS" << std::endl;
	std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
	std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

	robot1.attack("ROBOT2");
	robot2.takeDamage(5);
	std::cout << std::endl;
	robot2.attack("ROBOT1");
	robot1.takeDamage(3);

	std::cout << std::endl;
	std::cout << "STATUS" << std::endl;
	std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
	std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;	
}