#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _value; // this int stores raw value of the fixed-point number
    static const int    _fractionalBits = 8; // this is the number of fractional bits

public:
    // DEFAULT CONSTRUCTOR:
    Fixed();    
	// COPY CONSTRUCTOR: 
    Fixed(const Fixed &src); 
    // INT CONSTRUCTOR:
    Fixed(const int value);
    // FLOAT CONSTRUCTOR:
    Fixed(const float value);  
	// DESTRUCTOR:
    ~Fixed();

	// ASSIGNMENT OPERATOR: 
    Fixed& operator=(const Fixed &rhs);  

    int getRawBits(void) const; // getRawBits function returns raw value of the fixed-point number
    void setRawBits(int const raw); // setRawBits function sets the raw value of the fixed-point number

    float toFloat(void) const; // convert the fixed point number to float
    int toInt(void) const; // convert the fixed point number to int
};

// ------------------------------------------------------------------------------------------------------
// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // overload of the '<<' operator

#endif

