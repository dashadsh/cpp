#include "../inc/ScalarConverter.hpp"
// # include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter constructor called"  << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called"  << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	// copy constructor, not needed for this exercise
    // (void)src;
	*this = src; // copy assignment operator
}

ScalarConverter  &ScalarConverter::operator=(ScalarConverter   const &src) {
    // copy assignment operator, not needed for this exercise
	(void)src;
    return *this;
}

enum Type {
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    PSEUDO,
    INVALID
};

// func. to determine the type of input
Type	findType(std::string s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return CHAR;
    if (s == "+inff" || s == "+INFF" || s == "-inff" || s == "-INFF" || s == "nan" || s == "NAN")
        return PSEUDO;
    for(size_t i = 0; i < s.length(); i++) {
        if (!isdigit(s.at(i)) && s.at(i) != '.' && s.at(i) != 'f' && s.at(i) != '-' && s.at(i) != '+')
            return INVALID;
        else if (i != 0 && (s[i] == '+' || s[i] == '-'))
            return INVALID;
    }
    if (s.find('.') != std::string::npos) {
        if (s.find_first_of('.') != s.find_last_of('.') || s.find_first_of('f') != s.find_last_of('f'))
            return INVALID;
        if (s.find('f') == s.length() - 1)
            return FLOAT;
        if (s.find('f') != std::string::npos)
            return INVALID;
        return DOUBLE;
    }
    if (s.find('f') != std::string::npos)
        return INVALID;
    return INT;
}

// func. to print conversion results
// added conditions to check if the floatVal and doubleVal 
// have a fractional part, and if they don't, 
// it appends .0 to the output. 
// this ensures that the format of float and double 
// conversions matches desired output format.
void printResult(char charVal, bool validChar, int intVal, float floatVal, double doubleVal) {
    if (validChar && isprint(charVal)) {
        std::cout << "char: '" <<  charVal << "'\n";
        std::cout << "int: " << intVal << "\n";
        // std::cout << "float: " << floatVal << "f\n";
        // std::cout << "double: " << doubleVal << "\n";
		std::cout << "float: " << floatVal;
		if (std::fmod(floatVal, 1.0) == 0.0)
            std::cout << ".0f\n";
        else
            std::cout << "f\n";
        std::cout << "double: " << doubleVal;
        if (std::fmod(doubleVal, 1.0) == 0.0)
            std::cout << ".0\n";
		else
            std::cout << "\n";
    }
    else if (validChar) {
        std::cout << "char: non displayable\n";
        std::cout << "int: " << intVal << "\n";
        // std::cout << "float: " << floatVal << "f\n";
        // std::cout << "double: " << doubleVal << "\n";
		std::cout << "float: " << floatVal;
		if (std::fmod(floatVal, 1.0) == 0.0)
            std::cout << ".0f\n";
        else
            std::cout << "f\n";
        std::cout << "double: " << doubleVal;
        if (std::fmod(doubleVal, 1.0) == 0.0)
            std::cout << ".0\n";
        else
            std::cout << "\n";
    }
    else {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        // std::cout << "float: " << floatVal << "f\n";
        // std::cout << "double: " << doubleVal << "\n";
		std::cout << "float: " << floatVal;
		if (std::fmod(floatVal, 1.0) == 0.0)
            std::cout << ".0f\n";
        else
            std::cout << "f\n";
        std::cout << "double: " << doubleVal;
        if (std::fmod(doubleVal, 1.0) == 0.0)
            std::cout << ".0\n";
        else
            std::cout << "\n";
    }
}

// func. to handle integer conversion
void handleInteger(int intValue)  {
    float floatVal = static_cast<float>(intValue);
    double doubleVal = static_cast<double>(intValue);
    char charVal = static_cast<char>(intValue);
    printResult(charVal, true, intValue, floatVal, doubleVal);
}

// func. to handle float conversion
void handleFloat(float floatVal) {
    double doubleVal = static_cast<double>(floatVal);
    char charVal = static_cast<char>(floatVal);
    if (floatVal > INT_MAX || floatVal < INT_MIN) {
        int intValue = INT_MIN;
        printResult(charVal, false, intValue, floatVal, doubleVal);
        return;
    }
    int intValue = static_cast<int>(floatVal);
    printResult(charVal, true, intValue, floatVal, doubleVal);
}

// func to handle  conversion of a double value
void handle_double(double doubleVal) {
    float floatVal = static_cast<float>(doubleVal);
    char charVal = static_cast<char>(doubleVal);
    if (doubleVal > INT_MAX || doubleVal < INT_MIN) {
        // if double value cannot be converted to an int due to overflow, set intVal to INT_MIN
        int intVal = INT_MIN;
        printResult(charVal, false, intVal, floatVal, doubleVal);
        return;
    }
    int intVal = static_cast<int>(doubleVal);
    printResult(charVal, true, intVal, floatVal, doubleVal);
}

// func to handle conversion of a character
void handle_char(char charVal) {
    float floatVal = static_cast<float>(charVal);
    double doubleVal = static_cast<double>(charVal);
    int intVal = static_cast<int>(charVal);
    printResult(charVal, true, intVal, floatVal, doubleVal);
}

// f. to handle special cases: +inff, -inff, nan, etc.
void handle_infs(std::string str) {
    float floatVal = static_cast<float>(atof(str.c_str()));
    double doubleVal = static_cast<double>(floatVal);
    int intVal = INT_MIN; // Behavior when trying to cast infinity to int
    char charVal = static_cast<char>(floatVal);
    printResult(charVal, false, intVal, floatVal, doubleVal);
}

// determine type of input & perform the appropriate conversion
void ScalarConverter::convert(std::string const &str) {
    int type = findType(str);
    long tmp = atol(str.c_str());

    // protect int from having big numbers (overflow)
    if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min()) {
        type = FLOAT;
    }

    switch (type) {
        case INT:
            handleInteger(atoi(str.c_str()));
            break;
        case FLOAT:
            handleFloat(atof(str.c_str()));
            break;
        case DOUBLE:
            handle_double(atof(str.c_str()));
            break;
        case CHAR:
            handle_char(str.at(0));
            break;
        case PSEUDO:
            handle_infs(str);
            break;
        case INVALID:
            std::cerr << "error: invalid string input" << std::endl;
            return;
    }
}