#include "Fixed.hpp"
#include <iostream>

// Default constructor - initializes the fixed-point number value to 0.
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor - creates a new instance that is a copy of the source instance.
Fixed::Fixed(const Fixed &source) : value(source.value) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator - assigns the source instance's values to the current instance.
Fixed& Fixed::operator=(const Fixed &source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &source)
        value = source.value; // Assign value
    return *this; // Return a reference to enable chain assignment
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Returns the raw value
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

// Sets the raw value
void Fixed::setRawBits(int const raw) {
    value = raw;
}
