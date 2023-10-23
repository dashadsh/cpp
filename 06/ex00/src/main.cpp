#include "../inc/ScalarConverter.hpp"

// For each exercise, 
// the type conversion must be solved using one specific type of casting. 
// Your choice will be checked during defense.

// Allowed functions : 
// Any function to convert from a string to an int, a float or a double. 
// This will help, but won’t do the whole job.

int main(int ac, char **av) {
    if (ac != 2) {
        return (std::cerr << "enter one argument" << std::endl, 1);
    }

    std::string str(av[1]);
    ScalarConverter::convert(str); // since it's static, 
	// it allows us to use it as a utility w/o having to instantiate an object !!!

    return 0;
}