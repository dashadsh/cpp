#include "ScavTrap.hpp"

// --------------------- CONSTRUCT / DESTRUCT -----------------------------

ScavTrap::ScavTrap(void) : ClapTrap() {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap() {

	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap() {
	
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap destructor called with name: " << _name << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs) {
	
	this->_attackDamage = rhs.getAttackDamage();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_hitPoints = rhs.getHitPoints();
	this->_name = rhs.getName();
	
	return (*this);
}

// --------------------- FUNC. ---------------------------

void ScavTrap::attack(const std::string& target) {

	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have energy points and cannot attack." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;	
	}
}

void ScavTrap::guardGate(void) {

	std::cout << "ScavTrap " << this->_name << " is in gatekeeper mode" << std::endl;
}