/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/19 10:46:22 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --------------------------------- ORTHODOX CLASS -------------------------------------------
// The Orthodox Canonical Class Form in C++ is a best practice that was popularized 
// by the book "Advanced C++ Programming Styles and Idioms" by James O. Coplien. 

// It includes the following member functions:

// Default constructor

// Copy constructor:
// used to initialize a new object as a copy of an existing object.
// It is invoked whenever a new object is initialized to the value of an existing object upon creation. 
// This includes situations like:
//  - passing an object by value to a function, 
//  - returning an object by value from a function, 
//  - explicitly initializing a new object to the value of an existing object.

// Assignment operator:
// used to copy the value of an existing object to another already existing object. 
// This happens when you use the assignment operator (=) to give an existing object 
// the value of another existing object.

// Destructor: 
// This is called when an object is destroyed, and it's used to free any resources that the object may have 
// acquired during its lifetime. To clean up any resources the object has acquired. 
// This is critical for avoiding resource leaks (e.g., memory leaks).
// -------------------------------------------------------------------------------------------------

#include <iostream>
#include "../inc/Fixed.hpp"

int main(void) {
    Fixed a; // create a fixed-point number 'a' using the default constructor
    Fixed b(a); // create a fixed-point number 'b' as a copy of 'a' using the copy constructor
    Fixed c; // create another fixed-point number 'c' using the default constructor

	c = b; // assign the value of 'b' to 'c' using the assignment operator

	//  display the raw values of 'a', 'b', and 'c'
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}

// --------------------------------- EXPECTED OUTPUT -------------------------------------------
// dasha_dsh@Darias-MBP ex00 % ./orthodox_class 
// Default constructor called
// Copy constructor called
// Copy assignment operator called
// getRawBits member function called
// Default constructor called
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called
// Destructor called
// Destructor called

// ------------------------------- OUTPUT BREAKDOWN -------------------------------------------
// Default constructor called - 
// result of Fixed a -  Fixed object a is being constructed using the default constructor

// Copy constructor called - 
// from Fixed b(a) -  b is being created as a copy of a with copy constructor

// Copy assignment operator called - 
// due to *this = src in copy constructor 
// It's using copy assignment operator to copy src to the new object (b)

// getRawBits member function called - 
// inside copy assignment operator calling rhs.getRawBits() which is causing this

// Default constructor called - 
// result of Fixed c - Fixed object c is being constructed using default constructor

// Copy assignment operator called - 
// from c = b - object c is being assigned the value of b using assignment operator

// getRawBits member function called - 
// inside copy assignment operator calling rhs.getRawBits() which is causing this

// getRawBits member function called - 
// result of std::cout << a.getRawBits() << std::endl - calling the getRawBits method on a,
// 0 - output of the previous getRawBits() call

// getRawBits member function called - 
// result of std::cout << b.getRawBits() << std::endl - calling the getRawBits method on a,
// 0 - output of the previous getRawBits() call

// getRawBits member function called - 
// result of std::cout << c.getRawBits() << std::endl - calling the getRawBits method on a,
// 0 - output of the previous getRawBits() call

// Destructor called - 
// called when a goes out of scope and is being destructed at the end of the main()

// Destructor called - 
// called when b goes out of scope and is being destructed.

// Destructor called - 
// called when c goes out of scope and is being destructed.

// ------------------------------------------ FIXED-POINT NUMBERS --------------------------------------------------------
// Fixed-point number representation is a way of encoding real numbers within a computer. 
// It is an alternative to floating-point numbers, and the reason you might use one over the other depends on the 
// specific needs of your application.

// Here's why you might use fixed-point numbers:

// Accuracy: 
// Fixed-point arithmetic is exact. There are no rounding errors (as long as you don't overflow). 
// This can be particularly important in certain types of numerical algorithms where rounding errors can accumulate 
// and cause significant inaccuracies in the results.

// Performance: 
// In some systems (especially older or simpler processors), fixed-point arithmetic can be faster than floating-point arithmetic. 
// This is because fixed-point operations can often be implemented using integer operations which are usually faster.

// Predictability: 
// Fixed-point arithmetic has no surprise behaviours such as NaN or infinity, and no sudden huge jumps in the size of the error 
// (as you can get with floating-point when denormals kick in).

// Space Efficiency: 
// Fixed-point numbers can require less memory than floating-point numbers. This might be important in memory-constrained systems.

// The trade-off is that fixed-point numbers have a smaller range than floating-point numbers for the same bit-width,
// and handling the fixed-point fractional numbers might be a bit tricky, especially for division and multiplication.

// Fixed-point numbers are a way of representing real numbers in computer systems using a fixed number of digits after the decimal point. 
// They are a simple and efficient way to represent fractional numbers, and they are commonly used in systems that need to 
// perform a lot of mathematical operations quickly and accurately.

// A fixed-point number is essentially an integer that is scaled by a certain factor, usually a power of 2. 
// For example, you might represent the number 1.23 as the integer 123 with a scaling factor of 100.

// Here's where the concept of fractional bits comes in. Fractional bits are a method of representing fractions in binary, 
// using a fixed-point number system.

// To understand this, you need to know that, in binary, each bit represents a power of 2. 
// For example, in an 8-bit integer, the bits represent 2^7, 2^6, ..., down to 2^0.

// Now, let's say you have a fixed-point number with 4 fractional bits. Those 4 bits represent fractions of 1, not whole numbers. 
// They represent 2^-1, 2^-2, 2^-3, and 2^-4, or 0.5, 0.25, 0.125, and 0.0625 in decimal, respectively.

// So if you have a binary fixed-point number 1101.0101, it means 12^3 + 12^2 + 02^1 + 12^0 (for the integer part) + 
// 02^-1 + 12^-2 + 02^-3 + 12^-4 (for the fractional part). This equals to 13.3125 in decimal.

// Using fixed-point and fractional bits gives us a way to perform arithmetic with real numbers in a way that's faster and uses 
// less memory than floating-point arithmetic, which is why they're commonly used in certain types of computer systems, 
// especially embedded systems and digital signal processing.