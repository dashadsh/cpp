#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
    Fixed(); // Default constructor
    Fixed(const Fixed &source); // Copy constructor
    Fixed& operator=(const Fixed &source); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits() const; // Returns the raw value
    void setRawBits(int const raw); // Sets the raw value

private:
    int value; // Fixed-point number value
    static const int fractionalBits = 8; // Number of fractional bits
};

#endif // FIXED_HPP
