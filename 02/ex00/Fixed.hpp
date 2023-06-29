#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
    Fixed(); // default constructor
    Fixed(const Fixed &source); // copy constructor
	~Fixed(); // destructor

    Fixed& operator=(const Fixed &source); // copy assignment operator
    int getRawBits() const; // returns raw value
    void setRawBits(int const raw); // sets raw value

private:
    int value; // fixed-point number value
    static const int fractionalBits = 8; // number of fractional bits
};

#endif
