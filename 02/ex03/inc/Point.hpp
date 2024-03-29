/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:51:50 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 12:22:40 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

// Point class  context is used to represent a 2D point with x and y coordinates.
// 
// Point object is being used to represent each vertex of the triangle (a, b, c) 
// and the point we're checking (point).
// Each of these will be an instance of the Point class.

class Point {
private:
    const Fixed _x; // no matter how to declare - const Fixed or Foxed const - same effect
    const Fixed _y;

public:
    // Constructors
    Point();
    Point(const float x, const float y); 
    Point(const Point &src); 

    // Destructor
    ~Point();

    // Overload assignment operator
    Point& operator=(const Point &rhs);	

    // Getters
    const Fixed& getX(void) const; // returns const + promises not to modify
    const Fixed& getY(void) const; 
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);


#endif
