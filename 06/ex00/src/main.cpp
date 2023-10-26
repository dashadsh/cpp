#include "../inc/ScalarConverter.hpp"

// For each exercise, 
// the type conversion must be solved using one specific type of casting. 
// Your choice will be checked during defense.

// STATIC CAST IS THE MOST APPROPRIATE CAST FOR NUMERIC DATA TYPES !!!
// IMPLICIT CASTS ARE ALLOWED FOR PROMOTIONAL CASTS

// Allowed functions : 
// Any function to convert from a string to an int, a float or a double. 
// This will help, but won’t do the whole job.

// he code should make use of static_cast when it's necessary to convert values, 
// but can rely on the compiler's implicit casts when they involve change from smaller data type
//  to a larger one

int main(int ac, char **av) {
    if (ac != 2) {
        return (std::cerr << "enter one argument" << std::endl, 1);
    }

    std::string str(av[1]);
    ScalarConverter::convert(str); // since it's static, 
	// it allows us to use it as a utility w/o having to instantiate an object !!!

    return 0;
}

/*
use of explicit casts, like atoi and atof, is crucial to accurately 
and intentionally convert the input string to different data types. 
In the specific case where the input string represents a number, 
handling promotions (e.g., from int to long) and preventing overflow 
(choosing DOUBLE over INT) is a good practice to ensure data integrity 
and correct behavior in the face of potentially large or extreme values.
*/
