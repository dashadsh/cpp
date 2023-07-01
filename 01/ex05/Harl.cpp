#include "Harl.hpp"

void Harl::_debug() {
	std::cout << "\n[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::_info() {
	std::cout << "\n[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::_warning() {
	std::cout << "\n[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::_error() {
	std::cout << "\n[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
// to add a new level -  sadd a new function and update the collection of func. pointers accordingly, 
// w/o having to modify any control flow logic. If you wanted to add a new level, 
// you'd simply add a new function and update the collection of function pointers accordingly, 
// without having to modify any control flow logic.

// --------------------------------------------------------------------------------------------------------------------------------------
/**
 * The complain function is used to select an appropriate 
 * complaint method based on the provided level.
 *
 * @param level A string that represents the level of the complaint. 
 * This can be "DEBUG", "INFO", "WARNING", or "ERROR".
 */
void Harl::complain(std::string level)
{
	// defining array of function pointers.
	void (Harl::*fPtr[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	// void (Harl::*)() is a type representing a pointer to a member function of the Harl class. 
	// This function takes no arguments and returns void.
	//
	// (Harl::*fptr[4])() is an array named fptr of four such function pointers.
	//
	// The right side of the equal sign, {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}, 
	// initializes the array with the addresses of four member functions of the Harl class.

    // array of the valid level strings
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)	// iterates through the levels array
    {
        if (levels[i] == level)	// if level matches the current level in the array
        {
            (this->*fPtr[i])();	// call corresponding member function
            return;	// return early to exit the function
        }
    }

    // provided level was invalid:
	std::cout << "\n[ EXCEPTION ]" << std::endl;
    std::cout << "Harl left the chat." << std::endl; 

    return;
}
