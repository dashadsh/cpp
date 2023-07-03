
#include "Harl.hpp"

// --------------------------------- CONSTRUCTOR -----------------------------------------
Harl::Harl() {
    //std::cout << "Harl called!" << std::endl;
}

// --------------------------------- DESTRUCTOR -----------------------------------------
Harl::~Harl(){
    //std::cout << "Harl destroyed!" << std::endl;
}

// -------------------------------- PUBLIC FUNC. ------------------------------------------
// The complain function is used to select an appropriate 
// complaint method based on the provided level.
void Harl::complain(std::string level)
{
	// defining array of function pointers:
	void (Harl::*fPtr[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	// void (Harl::*)() is a type representing a pointer to a member function of the Harl class,
	// takes no arguments and returns void.
	//
	// (Harl::*fptr[4])() is an array named fptr of 4 such function pointers.
	// Right side of the equal sign initializes array with the addresses of 4 member func's the Harl class.

    // array of the valid level strings:
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

// alternative solution could be:

// void Harl::complain(std::string level)
// {
//     Harl harl;
//
//     void (Harl::*fPtrDebug) () = &Harl::_debug;
//		void (Harl::*fPtrInfo) () = &Harl::_info;
//     void (Harl::*fPtrWarning) () = &Harl::_warning;
//     void (Harl::*fPtrError) () = &Harl::_error;
//
//     if(level.compare("DEBUG") == 0)
//         (harl.*fPtrDebug) ();
//     else if(level.compare("INFO") == 0)
//         (harl.*fPtrInfo) ();
// 	else if(level.compare("WARNING") == 0)
//         (harl.*fPtrWarning) ();
//     else if(level.compare("ERROR") == 0)
//         (harl.*fPtrError) ();
//     else
// 	{
// 		std::cout << "\n[ EXCEPTION ]" << std::endl;
//     	std::cout << "Harl left the chat." << std::endl; 
// 	}
// }

// ------------------------------ PRIVATE FUNC. ------------------------------------------
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
// to add a new level -  add new function + update the collection of func. pointers accordingly, 
// w/o having to modify any control flow logic.
