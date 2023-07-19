/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:53:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/19 10:01:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

Point::Point(void) : _x(0), _y(0) {
    // std::cout << "Point default constructor called." << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    // std::cout << "Point constructor called." << std::endl;
}

Point::Point(Point const &point) : _x(point._x) , _y(point._y) {
    // std::cout << "Point copy constructor called." << std::endl;
}

Point::~Point(void) {
    // std::cout << "Point destructor called." << std::endl;
}

// Assignment operator
// Point class has the members _x and _y as const. 
// As a result, we cannot assign to them in your copy assignment operator 
Point& Point::operator=(const Point &rhs) {
    std::cout << "Point assignment operator called." << std::endl;
    std::cout << "Warning: cannot assign to Point const attributes. "
                 "Use a Point copy constructor instead."
              << std::endl;
    (void)rhs;
    return (*this);
}

// Point& Point::operator=(const Point &rhs)
// {
// 	if (this == &rhs)
// 		return *this;
// 	(Fixed)this->_x = rhs.getX();
// 	(Fixed)this->_y = rhs.getY();
// 	return *this;
// }

Fixed const &Point::getX(void) const {
    return (this->_x);
}

Fixed const &Point::getY(void) const {
    return (this->_y);
}
