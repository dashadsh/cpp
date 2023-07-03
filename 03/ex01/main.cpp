#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// initializes two robots (instances of ScavTrap), makes them attack each other, repair themselves, and then display their status (hit points, energy points, attack damage).
// At the end, it also makes them guard the gate.
int main(void) {
    ScavTrap robot1("ROBOT1");
    ScavTrap robot2("ROBOT2");

    std::cout << std::endl;

    robot1.attack("ROBOT2");
    robot2.takeDamage(20);
    robot2.attack("ROBOT1");
    robot1.takeDamage(robot2.getAttackDamage());

    std::cout << std::endl;
    std::cout << "STATUS" << std::endl;
    std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
    std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
    std::cout << std::endl;

    robot1.beRepaired(2);
    robot2.beRepaired(10);

    std::cout << std::endl;
    std::cout << "STATUS" << std::endl;
    std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
    std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
    std::cout << std::endl;

    robot1.attack("ROBOT2");
    robot2.takeDamage(robot1.getAttackDamage());
    std::cout << std::endl;
    robot2.attack("ROBOT1");
    robot1.takeDamage(robot2.getAttackDamage());

    std::cout << std::endl;
    std::cout << "STATUS" << std::endl;
    std::cout << robot1.getName() << ": " << robot1.getAttackDamage() << " damage points, " << robot1.getEnergyPoints() << " energy points, " << robot1.getHitPoints() << " hit points." << std::endl;
    std::cout << robot2.getName() << ": " << robot2.getAttackDamage() << " damage points, " << robot2.getEnergyPoints() << " energy points, " << robot2.getHitPoints() << " hit points." << std::endl;
    std::cout << std::endl;

    robot1.guardGate();
    robot2.guardGate();

    return 0;
}
