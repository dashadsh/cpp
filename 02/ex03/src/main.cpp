/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:54 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 14:47:05 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"
#include <iostream>

int	main(void)
{
	{
	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << "------------- test fixed class -------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
    Fixed a(10); // using the integer constructor
    Fixed b(5.5f); // using the float constructor
    Fixed c(a); // using the copy constructor

    // testing overloaded operators
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    // testing comparison operators
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;

    // testing min/max functions
    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
	}
	
	{
	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << "------------- test point class -------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	
	Point p1(10.5f, 5.5f);
    Point p2 = p1; // using the copy assignment operator

    std::cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    std::cout << "p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
	}
	
	{	
	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << "------------- test BSP 1 -------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	Point a(0.0, 0.0);
	Point b(5.0, 0.0);
	Point c(0.0, 5.0);
	Point p(6.0, 2.0);

	if (bsp(a, b, c, p))
		std::cout << "Point is part of the triangle." << std::endl;
	else
		std::cout << "Point is not part of the triangle." << std::endl;
	}
	
	{
	std::cout << std::endl << "------------------------------------------" << std::endl;
	std::cout << "------------- test BSP 2 -------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
    Point triangle[3] = {
        Point(0.0, 0.0),
        Point(5.0, 0.0),
        Point(0.0, 5.0)
    };

    Point testPoints[4] = {
        Point(2.5, 2.5),
        Point(6.0, 2.0),
        Point(-1.0, -1.0),
        Point(3.0, 0.0)
    };

    for (int i = 0; i < 4; ++i) {
        if (bsp(triangle[0], triangle[1], triangle[2], testPoints[i]))
            std::cout << "Point " << i+1 << " is part of the triangle." << std::endl;
        else
            std::cout << "Point " << i+1 << " is not part of the triangle." << std::endl;
    }

	}
}

// bool	bsp( Point const a, Point const b, Point const c, Point const point);

// void printIsPointInsideTriangle(Point const a, Point const b, Point const c, Point const p, bool expected) {
//     std::cerr << "-- Triangle: A(" << a.getX() << ", " << a.getY() << ") "
//               << "B(" << b.getX() << ", " << b.getY() << ") "
//               << "C(" << c.getX() << ", " << c.getY() << ")"
//               << "-- Point: P(" << p.getX() << ", " << p.getY() << ")" << std::endl;
//     std::cout << "Is point P inside triangle ABC? ";
//     if (bsp(a, b, c, p) == true)
//         std::cout << "YES!";
//     else
//         std::cout << "NO.";
//     std::cout << " (Expected: ";
//     if (expected == true)
//         std::cout << "YES";
//     else
//         std::cout << "NO";
//     std::cout << ")" << std::endl << std::endl;
//     return;
// }

// void testSimpleTriangle(void) {
//     bool expect;
//     Point const a(0, 0);
//     Point const b(6, 0);
//     Point const c(0, 6);

//     std::cout << "--- Simple triangle test" << std::endl; {
//         Point const p(1.5f, 1.5f);
//         expect = true;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     } {
//         Point const p(a);
//         expect = false;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     } {
//         Point const p(10.0f, 1.5f);
//         expect = false;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     } {
//         Point const p(4.5f, 0.5f);
//         expect = true;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     }
//     return;
// }

// void testFloatPointTriangle(void) {
//     bool expect;
//     Point const a(-5.44f, 0.29f);
//     Point const b(2.62f, 2.95f);
//     Point const c(1.0f, -1.45f);

//     std::cout << "--- Floating point triangle test" << std::endl; {
//         Point const p;
//         expect = true;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     } {
//         Point const p(c);
//         expect = false;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     } {
//         Point const p(-5.45f, 0.29f);
//         expect = false;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     } {
//         Point const p(3.5f, 1.5f);
//         expect = false;
//         printIsPointInsideTriangle(a, b, c, p, expect);
//     }
//     return;
// }

// int main() {
//     testSimpleTriangle();
//     testFloatPointTriangle();
//     return 0;
// }
