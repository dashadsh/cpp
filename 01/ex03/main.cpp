#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() 
{
	{
    Weapon  club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
	} 
	{
	Weapon  club = Weapon("crude spiked club");

	HumanB jim("Jim");
	jim.setWeapon(club);
	// setWeapon() func. takes a reference to a Weapon object and 
	// assigns it to the weapon PTR,
	// this allows the HumanB object to be armed with the specified weapon 
	// and perform attacks correctly.
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}

return 0; 
}
