#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value; // An integer to store the fixed-point number value.
    static const int    _fractionalBits = 8;

public:
	// Constructors
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed &src);

	// Destructor
    ~Fixed();

    Fixed&	operator=(const Fixed &rhs);	// Overload operator

    Fixed&	operator++();    // Prefix increment
    Fixed	operator++(int);  // Postfix increment
    Fixed&	operator--();    // Prefix decrement
    Fixed	operator--(int);  // Postfix decrement

    int		getRawBits(void) const; // getter
    void	setRawBits(int const raw); // setter

    // conversion functions
    float	toFloat(void) const;
    int		toInt(void) const;

    // comparison operators
    bool	operator>(const Fixed &rhs) const;
    bool	operator<(const Fixed &rhs) const;
    bool	operator>=(const Fixed &rhs) const;
    bool	operator<=(const Fixed &rhs) const;
    bool	operator==(const Fixed &rhs) const;
    bool	operator!=(const Fixed &rhs) const;

    // arithmetic operators
    Fixed	operator+(const Fixed &rhs) const;
    Fixed	operator-(const Fixed &rhs) const;
    Fixed	operator*(const Fixed &rhs) const;
    Fixed	operator/(const Fixed &rhs) const;

    // min/max func.
    static			Fixed& min(Fixed &a, Fixed &b);
    static const 	Fixed& min(const Fixed &a, const Fixed &b);
    static 			Fixed& max(Fixed &a, Fixed &b);
    static const 	Fixed& max(const Fixed &a, const Fixed &b);
};

// an overload of the "insertion operator" (<<) for output streams (represented by std::ostream)
std::ostream& operator<<(std::ostream &out, const Fixed &rhs);

// << operator - used to send the contents of variables, literals, and constants to an output stream, 
//such as std::cout (the standard console output), a file, a string, or any other kind of C++ output stream.

// By default, the << operator knows how to handle built-in types like int, double, char, and C-style strings, 
// but it doesn't know how to handle user-defined types, like your Fixed class.

// When we define this operator for our class, we're telling C++ how to output an object of type Fixed.
// In this case, std::ostream& operator<<(std::ostream &out, const Fixed &rhs); is a function that takes two arguments:
//
// Ref. to an std::ostream object, which is the stream that the Fixed object will be output to.
// Ref. to a constant Fixed object, which is the object that is being output.
// Function returns a reference to an std::ostream object, which allows for chain insertion operations like std::cout << a << b << c;

// This func. is usually defined to output some meaningful representation of the Fixed object, 
// for example by calling member functions of the Fixed class and inserting their results into the output stream.

#endif
