#ifndef SCALARCONVERTER
#define SCALARCONVERTER

/*
* C++ standard header <limits> contains <climits> in which is <limits.h>. Doesn't work here!
*/
#include <iostream>
#include <cctype> // For std::isprint
#include <cstdlib> // For std::atof
#include <limits> // For numeric_limits !!! 
// #include <cfloat> // for DBL_MIN, DBL_MAX
// #include <climits> //max_min
#include <cmath> // fmod
// # include <iomanip> // for setprecision

# define INT 0
# define FLOAT 1
# define DOUBLE 2
# define CHAR 3
# define PSEUDO 4
# define INVALID 5
// static class doesnt really exist  - it contains static member functions
class ScalarConverter {
	private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &src);

		ScalarConverter &operator=(ScalarConverter const &src);

    public:
        static void convert(std::string const &str);
};

#endif
