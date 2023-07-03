#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap robot3("ROBOT3");

	std::cout << std::endl;

	robot3.attack("ROBOT1");
	robot3.takeDamage(20);
	robot3.attack("ROBOT2");
	robot3.highFivesGuys();

	std::cout << std::endl;
	std::cout << "STATS" << std::endl;
	std::cout << robot3.getName() << ": " << robot3.getAttackDamage() << " damage points, " << robot3.getEnergyPoints() << " energy points, " << robot3.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

	robot3.beRepaired(2);

	std::cout << std::endl;
	std::cout << "STATS" << std::endl;
	std::cout << robot3.getName() << ": " << robot3.getAttackDamage() << " damage points, " << robot3.getEnergyPoints() << " energy points, " << robot3.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

	robot3.highFivesGuys();
}
