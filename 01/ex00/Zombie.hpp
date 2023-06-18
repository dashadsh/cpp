
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	// constructor
    Zombie(std::string name);

	// Function that announces the zombie by printing
    void announce();

	// destructor
    ~Zombie();

private:
	// private attribute 'name'
    std::string name;
};

#endif
