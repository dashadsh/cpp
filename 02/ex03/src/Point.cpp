/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:53:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 16:11:18 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include "../inc/Point.hpp"

Point::Point(void) : _x(0), _y(0) {
    // std::cout << "Point default constructor called." << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    // std::cout << "Point fixed constructor called." << std::endl;
}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {
    // std::cout << "Point copy constructor called." << std::endl;
}

Point::~Point(void) {
    // std::cout << "Point destructor called." << std::endl;
}

Point& Point::operator=(Point const &rhs) {
    // std::cout << "Point assignment operator called." << std::endl;
    // std::cout << "Warning: cannot assign to Point const attributes. "
    //              "Use a Point copy constructor instead."
    //           << std::endl;
    // (void)rhs;
	if (this != &rhs) {
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	
    return (*this);
}

Fixed const &Point::getX(void) const {
    return (this->_x);
}

Fixed const &Point::getY(void) const {
    return (this->_y);
}
