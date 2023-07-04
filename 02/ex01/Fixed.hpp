/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:25 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/04 14:23:26 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

