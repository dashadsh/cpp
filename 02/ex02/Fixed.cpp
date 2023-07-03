
#include "Fixed.hpp"
#include <cmath>

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
Fixed::Fixed(const int val) : _value(val << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}
// ALTERNATIVE:
// Fixed::Fixed(const int value) {
//     std::cout << "Int constructor called" << std::endl;
//     _value = value << _fractionalBits;
// }

// takes a constant floating-point number as a parameter;
// converts it to the corresponding fixed-point value. 
// The fractional bits value is initialized to 8 like in exercise 00
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
Fixed& Fixed::operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs._value;
    return *this;
}

// ------------------------ prefix/postfix in-/decrement -----------------------------------------------------------------
Fixed& Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// ------------------------------ comparison operators -----------------------------------------------------------------
bool Fixed::operator>(const Fixed &rhs) const {
    return _value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return _value != rhs._value;
}
// ALTERNATIVE:
// bool Fixed::operator>(Fixed fixed) const {
//     return (this->toFloat() > fixed.toFloat());
// }

// bool Fixed::operator<(Fixed fixed) const {
//     return (this->toFloat() < fixed.toFloat());
// }

// bool Fixed::operator>=(Fixed fixed) const {
//     return (this->toFloat() >= fixed.toFloat());
// }

// bool Fixed::operator<=(Fixed fixed) const {
//     return (this->toFloat() <= fixed.toFloat());
// }

// bool Fixed::operator==(Fixed fixed) const {
//     return (this->toFloat() == fixed.toFloat());
// }

// bool Fixed::operator!=(Fixed fixed) const {
//     return (this->toFloat() != fixed.toFloat());
// }

// ------------------------------ comparison operators -----------------------------------------------------------------
Fixed Fixed::operator+(const Fixed &rhs) const {
    return Fixed(toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    return Fixed(toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    return Fixed(toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs._value == 0) {
        std::cerr << "Division by zero is not allowed!" << std::endl;
        return Fixed();
    }
    return Fixed(toFloat() / rhs.toFloat());
}

// ALTERNATIVE: 
// float Fixed::operator+(Fixed fixed) const {
//     return (this->toFloat() + fixed.toFloat());
// }

// float Fixed::operator-(Fixed fixed) const {
//     return (this->toFloat() - fixed.toFloat());
// }

// float Fixed::operator*(Fixed fixed) const {
//     return (this->toFloat() * fixed.toFloat());
// }

// float Fixed::operator/(Fixed fixed) const {
//     if (fixed.toFloat() == 0) {
//         std::cerr << "Division by zero is not allowed!" << std::endl;
//         return 0;
//     }
//     return (this->toFloat() / fixed.toFloat());
// }

// ------------------------------ min/max. functions -----------------------------------------------------------------
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

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
float Fixed::toFloat() const {
    return (float)_value / (1 << _fractionalBits);
}

// float Fixed::toFloat(void) const {
//     return static_cast<float>(_value) / (1 << _fractionalBits);
// }

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}


// ------ overload of the "insertion operator" (<<) for output streams (represented by std::ostream) -------------------
// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
std::ostream& operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
