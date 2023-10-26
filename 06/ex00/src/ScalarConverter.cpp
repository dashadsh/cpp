#include "../inc/ScalarConverter.hpp"
// # include <iomanip>
#include <cmath>

// static_cast:
// static_cast is a compile-time type cast operator.
// It is used for general type conversions that are known to be safe at compile time.
// It performs a wide range of conversions, such as between related types 
// (e.g., subclasses to base classes), primitive types, and user-defined types.
// static_cast does not perform runtime type checking, so it may lead to undefined behavior 
// if the conversion is not safe.
// int integer = 42;
// double floating = static_cast<double>(integer);

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

// enum Type {
//     INT,
//     FLOAT,
//     DOUBLE,
//     CHAR,
//     PSEUDO,
//     INVALID
// };

// func. to determine the type of input
int	findType(std::string s)
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
// where input string represents values like :
// positive infinity, 
// negative infinity,
// "not-a-number" (NaN). 
void handle_infs(std::string str) {
	// converts input string to float using 
	// ATOF function to convert the string to a double and then casting it to a float. 
    float floatVal = static_cast<float>(atof(str.c_str()));
	// further converts floating-point val to double=>preciser & larger than float
    double doubleVal = static_cast<double>(floatVal);
	// Behavior when trying to cast infinity to int:
	// int value set to INT_MIN, bc converting infinity (positive or negative) to an int isn't possible 
	// due to limited range of ints. 
	// By setting it to INT_MIN, it indicates: converting infinity to an int is impossible
    int intVal = INT_MIN; 
	// floatVal is cast to a char. 
	// This step is made to attempt conversion, even though its weird in most cases, 
	// as the result might not be possible to display.
    char charVal = static_cast<char>(floatVal);
    printResult(charVal, false, intVal, floatVal, doubleVal);
}

// determine type of input & perform the appropriate conversion
void ScalarConverter::convert(std::string const &str) {
    int type = findType(str);
	// string -> long int
    long tmp = atol(str.c_str()); // PROMOTIONAL CAST

    // protect int from overflow
    if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min()) {
        type = DOUBLE; // FLOAT;
		// "DOUBLE" represents double-precision floating-point numbers, 
		// which have a wider range and higher precision compared to "FLOAT."
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

/*
"Infinity" and "NaN" are special floating-point values used to represent 
certain exceptional conditions in computer programming, 
particularly in scientific and engineering applications. 
Here's what these terms mean:

1. **Infinity (`+inf` and `-inf`):**
   - `+inf` stands for positive infinity, while `-inf` stands for negative infinity.
   - These values represent mathematical infinity, which means 
   a number that is infinitely large (positive or negative).
   - In the context of floating-point representation, 
   positive and negative infinity are used to represent overflow conditions or extremely large 
   (positive or negative) values.
   - For example, if you perform a calculation that results 
   in a number too large to be represented within the range of a floating-point 
   data type (e.g., `float` or `double`), it may be represented as positive or negative infinity.

   When to use them:
   - You may encounter positive or negative infinity when dealing with mathematical computations, 
   such as solving equations, calculating limits, or performing other numerical analyses.
   - In programming, they can be used to handle situations where a value exceeds 
   the representable range of a data type or when dealing with asymptotic behaviors in 
   mathematical functions.

2. **NaN (Not-a-Number):**
   - `NaN` is a special value used to represent the result of an undefined 
   or unrepresentable mathematical operation.
   - It indicates that the result of a computation is not a valid number.
   - `NaN` can result from operations like taking the square root of a negative number, 
   dividing zero by zero, or any other undefined mathematical operation.

   When to use it:
   - `NaN` is often used to handle errors or exceptional conditions in numeric computations.
   - It's especially useful in numerical libraries, scientific computing, 
   and engineering applications to indicate when a calculation could not produce a meaningful result.

In programming, you may encounter these special values in the context of floating-point arithmetic. 
It's important to handle them appropriately to avoid unexpected behavior and to identify 
when calculations have resulted in infinity or non-numeric values. 
Libraries and languages that support floating-point operations often provide functions or constants 
to work with these special values and detect them in your code.
*/