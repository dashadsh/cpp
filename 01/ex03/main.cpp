#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {	
		// First code block:
		// a Weapon object named club is created with the type "crude spiked club". 
        Weapon club = Weapon("crude spiked club");
		// a HumanA object named bob is created with the name "Bob" and the club as a parameter. 
        HumanA bob("Bob", club);
		// attack member function of bob is called,
		// displays the attack message using the weapon's type
        bob.attack();
		// type of the club is changed to "some other type of club"
        club.setType("some other type of club");
		// another attack is performed by bob
        bob.attack();
    }

    {
		// Second code block:
		// a Weapon object named club is created with the type "crude spiked club". 
        Weapon club = Weapon("crude spiked club");
		// a HumanB object named jim is created with the name "Jim"
        HumanB jim("Jim");
		// setWeapon member function of jim is called to set the club as the weapon for jim
        jim.setWeapon(club);
		// attack member function of jim is then called, 
		// displays the attack message using the weapon's type.
        jim.attack();
		// type of the club is changed to "some other type of club"
        club.setType("some other type of club");
		// another attack is performed by jim
        jim.attack();
    }
    return 0;
}
