
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

private:
    int                 _value; // integer to store the fixed-point number value
    static const int    _fractionalBits = 8; // static constant integer to store the number of fractional bits,
										   	// its value will always be the integer literal 8

public:
    Fixed(); // default constructor that initializes the fixed-point number value to 0
    Fixed(const Fixed &src);  // copy constructor 

	~Fixed(); // destructor

    Fixed& operator=(const Fixed &rhs);  // copy assignment operator overload

    int getRawBits(void) const; // getRawBits function returns raw value of the fixed-point number
    void setRawBits(int const raw); // setRawBits function sets the raw value of the fixed-point number

};

#endif
