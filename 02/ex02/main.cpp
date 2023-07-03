#include "Fixed.hpp"
#include <iostream>

int	main() { 

	// Default constructor called
	Fixed a; 

	// "Float constructor called"
	// "Int constructor called" 
	// "Destructor called" twice (temp. obj's Fixed(5.05f) and Fixed(2) are destroyed)
	Fixed const b(Fixed(5.05f) * Fixed(2));
 
	// "0" - value of a
	std::cout << a << std::endl;

	// "0.00390625" - value of a after the pre-increment operation (++a)
	// "Copy constructor called" - operation creates a temporary copy of a
	// "Copy assignment operator called" - result of the increment operation is assigned back to a.
	std::cout << ++a << std::endl;

	// "0.00390625" - prints the original value of a before the increment operation
	// The post-increment operator is used here. 
	// It increments a but returns the original value of a before the increment, 
	// which is why the output is still "0.00390625".
	// "Destructor called" - temp Fixed object (copy of a before the increment) is destroyed as it goes out of scope
	std::cout << a++ << std::endl; 

	// "0.0078125" -  new value of a after increment operation
	std::cout << a << std::endl;

	// "10.1016" - prints value of b, which was initialized with a result of multiplication operation
	std::cout << b << std::endl;

	// "10.1016" - prints larger of a and b, which is b
	std::cout << Fixed::max(a, b) << std::endl;
	
	// "Destructor called" is output twice, for a and b.
	return 0; 
}

// --------------------------------- ALTERNATIVE MAIN -------------------------------------------
// int main( void ) {

// 	Fixed a (1);
// 	Fixed b (6.05f);

// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "b: " << b << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "TEST basic calulations" << std::endl;
// 	std::cout << "result addition: " << (a + b) << std::endl;
// 	std::cout << "result subtraction: " << (a - b) << std::endl;
// 	std::cout << "result multiplication: " << (a * b) << std::endl;
// 	std::cout << "result division: " << (a / b) << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "TEST ++/--" << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "result a++: " << (a++) << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "result ++a: " << (++a) << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "result a--: " << (a--) << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << "result --a: " << (--a) << std::endl;
// 	std::cout << "a: " << a << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "TEST comparison" << std::endl;
// 	std::cout << "a > b: " << (a > b) << std::endl;
// 	std::cout << "a < b: " << (a < b) << std::endl;
// 	std::cout << "a >= b: " << (a >= b) << std::endl;
// 	std::cout << "a <= b: " << (a <= b) << std::endl;
// 	std::cout << "a == b: " << (a == b) << std::endl;
// 	std::cout << "a != b: " << (a != b) << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "TEST min/max" << std::endl;
// 	std::cout << "min(a,b): " << (Fixed::min(a,b)) << std::endl;
// 	std::cout << "max(a,b): " << (Fixed::max(a,b)) << std::endl;
// 	std::cout << std::endl;

// 	return 0;
// }

// --------------------------------- EXPECTED OUTPUT -------------------------------------------
// dasha_dsh@Darias-MBP ex02 % ./fixed02 
// Default constructor called
// Float constructor called
// Int constructor called
// Float constructor called
// Destructor called
// Destructor called
// 0
// 0.00390625
// 0.00390625
// Copy constructor called
// Copy assignment operator called
// 0.00390625
// Destructor called
// 0.0078125
// 10.1016
// 10.1016
// Destructor called
// Destructor called

// ------------------------------- OUTPUT BREAKDOWN -------------------------------------------
// "Default constructor called" - 
// Fixed a - creates an instance of the Fixed class using default constructor

// "Float constructor called" - 
// Fixed(5.05f) - creates a temporary Fixed object, initializing it with the floating-point number 5.05

// "Int constructor called" -
// Fixed(2) - creates another temp. Fixed object, initializing it with the int 2

// "Float constructor called" - 
// Fixed const b( Fixed(5.05f) * Fixed(2) ) - multiplication operator (*) creates new Fixed object, which in turn triggers the float constructor

// "Destructor called" - 
// temp. obj's Fixed(5.05f) and Fixed(2) are destroyed bc their scope (expression for initializing b) has ended

// "Destructor called" - 
// temp. obj. created by Fixed(5.05f) * Fixed(2) is destroyed after being used to initialize b

// "0" - 
// std::cout << a << std::endl - prints Fixed object a, which was initialized with the default constructor to the value 0

// "0.00390625" - 
// std::cout << ++a << std::endl - increments a by the smallest representable ε and then prints it

// "0.00390625" - 
// std::cout << a << std::endl - prints a again, which is still the same value from the last increment

// "Copy constructor called" - 
// Fixed a++ - creates a copy of a because the post-increment operator returns the value before incrementing

// "Copy assignment operator called" - 
// result of the post-increment operation on a - copy of a (before increment) is assigned to a temp. variable, then a is incremented

// "0.00390625" - 
// std::cout << a++ << std::endl;  - prints the original value of a before the increment operation

// "Destructor called" - 
// temp Fixed object (copy of a before the increment) is destroyed as it goes out of scope

// "0.0078125" - 
// std::cout << a << std::endl - prints new value of a after increment operation

// "10.1016" - 
// std::cout << b << std::endl - prints value of b, which was initialized with a result of multiplication operation

// "10.1016" - 
// std::cout << Fixed::max(a, b) << std::endl -  prints larger of a and b, which is b

// "Destructor called" - 
// Fixed a and Fixed b are destroyed at the end of the program's scope

// "Destructor called" - 
// all objects have been destroyed as the program has ended