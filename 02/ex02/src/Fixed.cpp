/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:38 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/09 22:50:39 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <cmath>

// ------------------------------------ CONSTRUCTORS --------------------------------------------------------------
// Default constructor. 
// It initializes the _value to 0.
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor.
// It creates a new object as a copy of the existing src object.
Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Integer constructor. 
// takes a constant integer as a parameter.
// It initializes the _value by shifting the integer input val 
// left by _fractionalBits (8 in this case).
Fixed::Fixed(const int val) : _value(val << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}
// ALTERNATIVE:
// Fixed::Fixed(const int value) {
//     std::cout << "Int constructor called" << std::endl;
//     _value = value << _fractionalBits;
// }

// Float constructor. 
// takes a constant floating-point number as a parameter;
// converts it to the corresponding fixed-point value. 
// It initializes the _value by rounding the float input val 
// and then shifting left by _fractionalBits.
Fixed::Fixed(const float val) : _value(roundf(val * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}
// ALTERNATIVE:
// Fixed::Fixed(const float value) {
//     std::cout << "Float constructor called" << std::endl;
//     _value = roundf(value * (1 << _fractionalBits));
// }

// ---------------------------------------- DESTRUCTOR -----------------------------------------------------------------
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// --------------------------------- COPY ASSIGNMENT OPERATOR OVERLOAD -----------------------------------------------------
// Overloaded copy assignment operator. 
// It assigns the value of rhs to the current object if they are not the same.
Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs._value;
    return *this;
}

// ------------------------ prefix/postfix in-/decrement -----------------------------------------------------------------
// Overloaded prefix increment operator.
Fixed& Fixed::operator++() {
    ++_value;
    return *this;
}

// Overloaded postfix increment operator.
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

// Overloaded prefix decrement operator.
Fixed& Fixed::operator--() {
    --_value;
    return *this;
}

// Overloaded postfix decrement operator.
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// ------------------------------ comparison operators -----------------------------------------------------------------
// Overloaded greater than operator.
bool Fixed::operator>(const Fixed &rhs) const {
    return _value > rhs._value;
}

// Overloaded less than operator.
bool Fixed::operator<(const Fixed &rhs) const {
    return _value < rhs._value;
}

// Overloaded greater than or equal to operator.
bool Fixed::operator>=(const Fixed &rhs) const {
    return _value >= rhs._value;
}

// Overloaded less than or equal to operator.
bool Fixed::operator<=(const Fixed &rhs) const {
    return _value <= rhs._value;
}

// Overloaded equals to operator.
bool Fixed::operator==(const Fixed &rhs) const {
    return _value == rhs._value;
}

// Overloaded not equals to operator.
bool Fixed::operator!=(const Fixed &rhs) const {
    return _value != rhs._value;
}

// ------------------------------ comparison operators -----------------------------------------------------------------
// Overloaded addition operator.
Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(toFloat() + rhs.toFloat());
}

// Overloaded subtraction operator.
Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(toFloat() - rhs.toFloat());
}

//  Overloaded multiplication operator.
Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(toFloat() * rhs.toFloat());
}

// Overloaded division operator. 
// Returns a default constructed Fixed object if division by zero is attempted.
Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs._value == 0) {
        std::cerr << "Division by zero is not allowed!" << std::endl;
        return Fixed();
    }
    return Fixed(toFloat() / rhs.toFloat());
}

// ------------------------------ min/max. functions -----------------------------------------------------------------
// Returns the lesser of two Fixed objects.
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

// Returns the lesser of two Fixed objects, accepting const references.
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

// Returns the greater of two Fixed objects.
Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

// Returns the greater of two Fixed objects, accepting const references.
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

// ------------------------------ getter/setter -----------------------------------------------------------------
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// ------------------------------ conversion functions -----------------------------------------------------------------
// Converts the Fixed object to a float.
float Fixed::toFloat() const {
    return (float)_value / (1 << _fractionalBits);
}

// Converts the Fixed object to an integer.
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// ------ overload of the "insertion operator" (<<) for output streams (represented by std::ostream) -------------------
// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
// Overloaded insertion operator for output streams. It outputs the float representation of a Fixed object. 
// It returns an output stream reference to enable chaining.
std::ostream& operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
