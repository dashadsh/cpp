#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type; // Private attribute to store the weapon type

public:
    Weapon(std::string type); // Constructor to initialize the weapon type
	~Weapon();
	
    std::string getType(); // Member function to get the weapon type
    void setType(std::string newType); // Member function to set the weapon type
};



//---------------------------------------------------------------------------------------------
// class Weapon {
// private:
//     std::string type; // Private attribute to store the weapon type

// public:
//     Weapon(const std::string& type); // Constructor to initialize the weapon type
// 	~Weapon();

//     const std::string& getType() const; // Member function to get the weapon type
//     void setType(const std::string& newType); // Member function to set the weapon type
// };

#endif
