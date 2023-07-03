#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(void); // Default constructor
	FragTrap(std::string name); // Parameterized constructor
	FragTrap(FragTrap const &src); // Copy constructor
	~FragTrap(void); // Destructor

	FragTrap & operator=(FragTrap const &rhs); // Assignment operator

	void highFivesGuys(void);
};

#endif
