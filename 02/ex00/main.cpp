
/*
The Orthodox Canonical Class Form in C++ is a best practice that was popularized 
by the book "Advanced C++ Programming Styles and Idioms" by James O. Coplien. 

It includes the following member functions:

Default constructor: 
This is a constructor that can be called with no arguments. 
It is used to create an object with default values.
To provide a way to create an object of the class with default values.

Copy constructor: 
This constructor is used when an object is initialized with another object of the same class.
To provide a way to create a new object as a copy of an existing object. 
This is especially important for classes that manage resources such as memory, file handles, network connections, etc., 
where copying the resource requires specific actions.

Assignment operator:
This operator is used when an already initialized object is assigned the values of another object of the same class.
To allow one object to be assigned the values of another. Like the copy constructor, 
this is important for classes that manage resources.

Destructor: 
This is called when an object is destroyed, and it's used to free any resources that the object may have 
acquired during its lifetime. To clean up any resources the object has acquired. 
This is critical for avoiding resource leaks (e.g., memory leaks).
*/

#include <iostream>
#include "Fixed.hpp"

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

// ----------------------------------------------------------------------------------------------------------

// FIXED-POINT NUMBERS
// Fixed-point number representation is a way of encoding real numbers within a computer. 
// It is an alternative to floating-point numbers, and the reason you might use one over the other depends on the specific needs of your application.

// Here's why you might use fixed-point numbers:

// Accuracy: 
// Fixed-point arithmetic is exact. There are no rounding errors (as long as you don't overflow). 
// This can be particularly important in certain types of numerical algorithms where rounding errors can accumulate and cause significant inaccuracies in the results.

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

