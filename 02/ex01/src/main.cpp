/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:28 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 15:01:57 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compare to EX00, added:
// constructor - takes an integer and converts it into fixed-point format
// constructor - takes a float and converts it into fixed-point format
// func. toFloat - converts the fixed-point number to a floating-point number
// func. toInt - converts the fixed-point number to an integer
// overload of the stream insertion operator  - to output the float representation of the fixed-point number

#include <iostream>
#include "../inc/Fixed.hpp"

int main(void) {

	// {
	// Fixed a; // Default constructor called
    // Fixed const b(10); // Int constructor called
    // Fixed const c(43.42f); // Float constructor called
    // Fixed const d(b); // Copy constructor called

    // a = Fixed(1234.4321f);

    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;

    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	// }

	{
    Fixed a(2.75f); // Float constructor called
    Fixed b(1.5f);  // Float constructor called

    // Perform arithmetic operations using toFloat() function
    float result_addition = a.toFloat() + b.toFloat();
    float result_subtraction = a.toFloat() - b.toFloat();
    float result_multiplication = a.toFloat() * b.toFloat();
    float result_division = a.toFloat() / b.toFloat();

    std::cout << "a: " << a.toFloat() << std::endl; // Output: a: 2.75
    std::cout << "b: " << b.toFloat() << std::endl; // Output: b: 1.5
    std::cout << std::endl;
    std::cout << "TEST basic calculations" << std::endl;
    std::cout << "result addition: " << result_addition << std::endl;
    std::cout << "result subtraction: " << result_subtraction << std::endl;
    std::cout << "result multiplication: " << result_multiplication << std::endl;
    std::cout << "result division: " << result_division << std::endl;
    std::cout << std::endl;
	}


    return 0;
	
}

// SIC! 1 << _fractionalBits is used for bit shifting which is equivalent to 2^_fractionalBits.

// --------------------------------- EXPECTED OUTPUT -------------------------------------------
// dasha_dsh@Darias-MBP ex01 % ./orthodox_class 
// Default constructor called
// Int constructor called
// Float constructor called
// Copy constructor called
// Copy assignment operator called
// getRawBits member function called
// Float constructor called
// Copy assignment operator called
// getRawBits member function called
// Destructor called
// a is 1234.43
// b is 10
// c is 42.4219
// d is 10
// a is 1234 as integer
// b is 10 as integer
// c is 42 as integer
// d is 10 as integer
// Destructor called
// Destructor called
// Destructor called
// Destructor called

// ------------------------------- OUTPUT BREAKDOWN -------------------------------------------
// Default constructor called: 
// Fixed a - default constructor is used to initialize a.

// Int constructor called: 
// Fixed const b(10) - constructor that takes an integer is used

// Float constructor called: 
// Fixed const c(42.42f) - constructor that takes a float is used.

// Copy constructor called: 
// Fixed const d(b) - copy constructor is used to initialize d with b.

// Copy assignment operator called: 
// a = Fixed(1234.4321f) - temp. Fixed obj. is created and then assigned to a.

// getRawBits member function called: 
// called inside operator= when copying the raw bits of the temporary object to a.

// Float constructor called: 
// corresponds to a = Fixed(1234.4321f) - when new temp. Fixed obj. is created from the float 1234.4321f.

// Copy assignment operator called: 
// again, corresponds to a = Fixed(1234.4321f) - when temp. obj. is assigned to a.

// getRawBits member function called: 
// again, this is called inside the operator= when copying the raw bits of the temporary object to a.

// Destructor called: 
// temp. Fixed obj. created in a = Fixed(1234.4321f) - is destroyed after the assignment.

// 'a is 1234.43' is the output of std::cout << "a is " << a << std::endl - a is converted to a float for output.
// 'b is 10' is the output of std::cout << "b is " << b << std::endl -  b is converted to a float for output.
// 'c is 42.4219' is the output of std::cout << "c is " << c << std::endl - c is converted to a float for output.
// 'd is 10' is the output of std::cout << "d is " << d << std::endl - d is converted to a float for output.

// 'a is 1234 as integer' to 'd is 10' as integer  - outputs of converting a to d to integers and outputting them.

// Destructor called is printed four times because at the end of main() - four Fixed objects a, b, c, d are destroyed.

// -------------------------- a = Fixed(1234.4321f); BREAKDOWN ----------------------------------------------------------
// Fixed class implements some member functions and constructors that output lines when they are called:

// Copy assignment operator called
// getRawBits member function called
// Float constructor called
// Copy assignment operator called
// getRawBits member function called
// Destructor called

// Fixed(1234.4321f) - creates temp. Fixed obj using FLOATING POINT CONSTRUCTOR => "Float constructor called",
// takes a float (1234.4321f) & converts it into the internal fixed-point representation.

// a = Fixed(1234.4321f) - uses the COPY ASSIGNMENT OPERATOR to assign the temporary Fixed object to a => 
// "Copy assignment operator called". Copies the state of one Fixed object to another.

// Inside the copy assignment operator, getRawBits() FUNCTION is called to get the raw fixed-point value from the 
// RHS object (the temporary object) => 1st "getRawBits member function called".

// After raw value is obtained from the temp. object, it's assigned to _value of the Fixed obj. 
// on the LHS (a) using COPY ASSIGNMENT OPERATOR => "Copy assignment operator called".
// SIC! It's called twice because the raw value is used twice: 
// 1. to check if this and rhs are not the same object, 
// 2. to assign the raw value to _value of the Fixed object on the left-hand side (a).

// Inside the copy assignment operator, getRawBits() function is called to get the raw fixed-point value from the 
// RHS object (the temporary object) => 2nd "getRawBits member function called".

// After assignment operation (a = Fixed(1234.4321f);) finishes, temporary Fixed obj. that was created is no longer needed,
// temporary object is destroyed => "Destructor called".