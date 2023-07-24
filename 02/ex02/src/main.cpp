/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:54 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 15:58:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>

// int	main() { 

// 	Fixed a; 
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
 
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
	
// 	std::cout << b << std::endl;
	
// 	std::cout << Fixed::max(a, b) << std::endl;
	
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

// ------------------------------- OUTPUT BREAKDOWN - 2 -------------------------------------------
// int main() {
//     Fixed a(1);
//     Fixed b(6.05f);
//     ...
// }
// a: 1 and b: 6.05078: The constructor Fixed::Fixed(const int val) takes the integer value 1, shifts it left by 8 bits (multiplied by 256), and initializes _value with 256. The constructor Fixed::Fixed(const float val) takes the float value 6.05f, rounds it to the nearest fixed-point value (6.05f * 256), and initializes _value with 1556.
// -----------------------------------------------------------------
// std::cout << "TEST basic calulations" << std::endl;
//
// result addition: 9.05078: The + operator is overloaded, which converts a and b to floats, performs the addition (1 + 6.05), and returns a new Fixed object with the result 7.05 as a fixed-point value (7.05 * 256).
// result subtraction: -5.05078: The - operator is overloaded, which converts a and b to floats, performs the subtraction (1 - 6.05), and returns a new Fixed object with the result -5.05 as a fixed-point value (-5.05 * 256).
// result multiplication: 6.05859: The * operator is overloaded, which converts a and b to floats, performs the multiplication (1 * 6.05), and returns a new Fixed object with the result 6.05 as a fixed-point value (6.05 * 256).
// result division: 0.00259: The / operator is overloaded, which converts a and b to floats, performs the division (1 / 6.05), and returns a new Fixed object with the result 0.16528 as a fixed-point value (0.16528 * 256).
// -----------------------------------------------------------------
// std::cout << "TEST ++/--" << std::endl;
// 
// a: 1: Prints the current value of a, which is 1.
// result a++: 1: The post-increment operator returns the original value of a (before incrementing) and then increments a (_value becomes 2).
// a: 2: Prints the updated value of a, which is 2.
// result ++a: 3: The pre-increment operator increments a (_value becomes 3) and then returns the updated value of a.
// a: 3: Prints the updated value of a, which is 3.
// result a--: 3: The post-decrement operator returns the original value of a (before decrementing) and then decrements a (_value becomes 2).
// a: 2: Prints the updated value of a, which is 2.
// result --a: 1: The pre-decrement operator decrements a (_value becomes 1) and then returns the updated value of a.
// a: 1: Prints the updated value of a, which is 1.
// -----------------------------------------------------------------
// std::cout << "TEST comparison" << std::endl;
//
// a > b: 0: The > operator is overloaded, which converts a and b to floats and compares them. As 1 is not greater than 6.05, it returns false, represented as 0.
// a < b: 1: The < operator is overloaded, which converts a and b to floats and compares them. As 1 is less than 6.05, it returns true, represented as 1.
// a >= b: 0: The >= operator is overloaded, which converts a and b to floats and compares them. As 1 is not greater than or equal to 6.05, it returns false, represented as 0.
// a <= b: 1: The <= operator is overloaded, which converts a and b to floats and compares them. As 1 is less than or equal to 6.05, it returns true, represented as 1.
// a == b: 0: The == operator is overloaded, which converts a and b to floats and compares them. As 1 is not equal to 6.05, it returns false, represented as 0.
// a != b: 1: The != operator is overloaded, which converts a and b to floats and compares them. As 1 is not equal to 6.05, it returns true, represented as 1.
// -----------------------------------------------------------------
// std::cout << "TEST min/max" << std::endl;
//
// min(a,b): 1: The min function compares a and b and returns a since a is less than b.
// max(a,b): 6.05078: The max function compares a and b and returns b since b is greater than a



// --------------------------------- ALTERNATIVE MAIN - 2 -------------------------------------------
int main() {
    // Create Fixed objects using different constructors
    Fixed a; // Default constructor
    Fixed b(5); // Integer constructor
    Fixed c(2.34f); // Float constructor

    // Test arithmetic operators
    Fixed sum = b + c;
    Fixed difference = b - c;
    Fixed product = b * c;
    Fixed quotient = b / c;

    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "Sum (b + c): " << sum << std::endl;
    std::cout << "Difference (b - c): " << difference << std::endl;
    std::cout << "Product (b * c): " << product << std::endl;
    std::cout << "Quotient (b / c): " << quotient << std::endl;

    // Test comparison operators
    if (b > c) {
        std::cout << "b is greater than c." << std::endl;
    } else {
        std::cout << "b is not greater than c." << std::endl;
    }

    // Test prefix and postfix increment and decrement
    Fixed d = b++; // Postfix increment
    Fixed e = ++c; // Prefix increment
    std::cout << "Postfix increment of b: " << d << std::endl;
    std::cout << "Prefix increment of c: " << e << std::endl;

    // Test min and max static member functions
    Fixed minVal = Fixed::min(b, c);
    Fixed maxVal = Fixed::max(b, c);
    std::cout << "Min value between b and c: " << minVal << std::endl;
    std::cout << "Max value between b and c: " << maxVal << std::endl;

	// Test comparison using static member functions
    Fixed x = 3.14f;
    Fixed y = 1.5f;
    std::cout << "Min value between x and y: " << Fixed::min(x, y) << std::endl;
    std::cout << "Max value between x and y: " << Fixed::max(x, y) << std::endl;
    return 0;
}