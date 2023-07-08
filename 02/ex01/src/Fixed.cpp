/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:19 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/08 17:22:00 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath> // for roundf function
#include "../inc/Fixed.hpp"
// ------------------------------------ CONSTRUCTORS --------------------------------------------------------------
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. 
// The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

// takes a constant floating-point number as a parameter;
// converts it to the corresponding fixed-point value. 
// The fractional bits value is initialized to 8 like in exercise 00
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _fractionalBits));
}

// ---------------------------------------- DESTRUCTOR -----------------------------------------------------------------
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// --------------------------------- COPY ASSIGNMENT OPERATOR OVERLOAD -----------------------------------------------------
Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

// ------------------------------------------ MEMBER FUNC. -----------------------------------------------------------------
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

// converts the fixed-point value to a floating-point value,
// 1 << _fractionalBits is used for bit shifting which is equivalent to 2^_fractionalBits:
//
// _value is int. representation of the fixed-point nbr, with _fractionalBits nbr of bits dedicated 
// to the fractional part.
// 1 << _fractionalBits is a bit shift operation that calculates 2 to the power of _fractionalBits (8 in class definition). 
// So 1 << _fractionalBits equals 256 in this case.
// _value / (1 << _fractionalBits) divides _value by 256, effectively moving the binary point 8 places to the left. 
// This undoes the original fixed-point conversion and gives the original floating-point nbr 
// (or at least, an approximation of it).
// (float) cast ensures that division operation results in a float val. instead of an int. value - 
// needed bc both _value and (1 << _fractionalBits) are int's, and by default, dividing two integers in 
// C++ will perform int. division and result in an int. 
// The cast to (float) ensures that floating-point division is performed instead, giving a floating-point result.
float Fixed::toFloat() const {
    return (float)_value / (1 << _fractionalBits);
}

// converts the fixed-point value to an integer value:
// 
// _value member holds  fixed-point representation of a number.
// fixed-point representation consists of both the int. and fractional parts of a nbr, represented as a binary nbr.
// binary number is arranged such that the top bits (to the left) represent the int. part, 
// while the bottom bits (to the right) represent the fractional part. 
// _fractionalBits (8 in class definition) determines the number of bits used for the fractional part.
// operation _value >> _fractionalBits is a right shift op., which moves the bits in _value to the right by _fractionalBits pos. 
// Thisremoves the fractional part of the fixed-point representation by shifting it out of the binary number.
// result of this shift op. is the int. part of the fixed-point representation, i.e., the original integer.
//
// EXAMPLE: if _value represents the number 5.75 in fixed-point, its binary representation (assuming 8 fractional bits) 
// could be 00000101.11000000. 
// After right shifting by 8 (_fractionalBits), we get 00000001, which is 5 in binary, truncating the fractional part of the nbr.
int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

// -------------------------------------------------------------------------------------------------------------------------
// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
// This allows to directly use std::cout << someFixedObject to print the Fixed object in a meaningful way.
// 
// out << fixed.toFloat() - converts the Fixed object to a float using the toFloat() member function, 
// and then inserts that float into the output stream. 
// So, when you print a Fixed object, you see it as a floating-point number, which is easier to understand than the internal fixed-point representation.
// return out - returns the modified output stream, allowing for chaining of output operations. 
// This is why you can write something like std::cout << "a is " << a << std::endl; - 
// each << operation returns the output stream, which is then used as the input for the next << operation.

// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

// overloaded insertion operator (<<) is used multiple times in the main() function of:
// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// << operator is used to insert the Fixed objects (a, b, c, d) into the std::cout stream, 
// which is then printed to the console.
// << operator calls the overloaded operator<< function, which in turn calls the toFloat() method on the Fixed object 
// to convert it to a floating point value before it is printed.
// Without this overloaded operator<< function, it wouldn't be able to directly print Fixed objects using std::cout <<, and would instead have to manually call toFloat() or toInt() each time you wanted to print a Fixed object. So this operator overloading provides a convenient way to print Fixed objects.


// ------------------------------------- BIT SHIFTING ------------------------------------------------------------------------
// Bit shifting is an operation that you can perform on binary data. It shifts the bit values of a binary 
// number to the left or the right.

// Here are the two types of bit shifts:

// Left Shift (<<): 
// This operator shifts the bits of the number to the left by the specified number of positions. 
// Each shift to the left doubles the number, so it's equivalent to multiplying the number by 2. 
// For example, if we have the number 5 (which is 101 in binary), shifting it to the left by one position gives 1010, 
// which is the binary representation of 10:

// int number = 5;  // binary: 101
// number = number << 1;  // number now equals 10, binary: 1010

// Right Shift (>>): 
// This operator shifts the bits of the number to the right by the specified number of positions. 
// Each shift to the right halves the number, discarding the fractional part if the number is not even 
// (i.e., it performs a floor division by 2). 
// For example, if we have the number 10 (which is 1010 in binary), shifting it to the right by one position gives 101, 
// which is the binary representation of 5:

// int number = 10;  // binary: 1010
// number = number >> 1;  // number now equals 5, binary: 101

// In both cases, the vacant bit positions are filled differently depending on the type of shift. 
// In a left shift, the vacant bit positions on the right are filled with zeros.
// In a right shift, if the number is an unsigned number, the vacant positions on the left are filled with zeros. 
// If the number is a signed number, the vacant positions are filled with the sign bit (0 for positive and 1 for negative) 
// to preserve the sign of the number.

// Bit shifting is a very efficient operation because it takes significantly less processing time 
// than multiplication or division. 

// However, its usage is somewhat specialized and typically found in low-level programming, 
// algorithms involving binary data, or optimization efforts.