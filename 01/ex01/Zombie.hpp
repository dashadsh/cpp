#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
    void setName(std::string name);
    void announce();
    ~Zombie();

private:
    std::string name;
};

#endif

