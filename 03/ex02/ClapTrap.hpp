
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
	ClapTrap(void); // Default constructor
	ClapTrap(std::string name); // Parameterized constructor
	ClapTrap(ClapTrap const &src); // Copy constructor

	~ClapTrap(); // Destructor

	ClapTrap & operator=(ClapTrap const &rhs); // Assignment operator

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int	getHitPoints(void) const;
	int	getEnergyPoints(void) const;
	int	getAttackDamage(void) const;
	
protected:
	std::string _name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;	
};

#endif