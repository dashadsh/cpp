
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
public:
    HumanB(const std::string& name);
    void setWeapon(const Weapon& weapon);
    void attack() const;

private:
    std::string name;
    const Weapon* weapon;
};

#endif
