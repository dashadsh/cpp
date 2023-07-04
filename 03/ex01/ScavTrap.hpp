
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	
	~ScavTrap();

	ScavTrap & operator=(ScavTrap const &rhs);

	// Overridden attack function
	void attack(const std::string& target);
	// New function
	void guardGate();

	private:

};

#endif