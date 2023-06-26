#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
	~Zombie();

	// member function takes a std::string parameter name and sets the name 
	// of the Zombie object to the provided value
    void setName(std::string name);
    void announce();

private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif

