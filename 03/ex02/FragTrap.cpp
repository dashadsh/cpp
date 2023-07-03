
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Fragtrap default robot") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called with name: " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called with name: " << _name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " is asking for high fives!" << std::endl;
}
