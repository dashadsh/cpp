#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <cctype> // For std::isprint
#include <cstdlib> // For std::atof
#include <limits> // For numeric_limits

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