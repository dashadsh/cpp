#include "ClapTrap.hpp"


int main(void)
{
    ClapTrap a("A");
    ClapTrap b("B");
	std::cout << std::endl;

    a.attack("B");
	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
    b.takeDamage(4);
	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

    b.beRepaired(2);
	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;
    
    b.attack("A");
	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
    a.takeDamage(4);
	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;

    a.beRepaired(1);
	std::cout << a.getName() << ": " << a.getAttackDamage() << " damage points, " << a.getEnergyPoints() << " energy points, " << a.getHitPoints() << " hit points." << std::endl;
    b.beRepaired(2);
	std::cout << b.getName() << ": " << b.getAttackDamage() << " damage points, " << b.getEnergyPoints() << " energy points, " << b.getHitPoints() << " hit points." << std::endl;
	std::cout << std::endl;
    return (0); 
}
// SIC!
// the attack damage is always zero and never changes. 
// I could add a parameter to the constructor to set the attack damage?
// or you could create a setter method to change it?
