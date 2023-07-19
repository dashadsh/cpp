/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:23:54 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/19 10:04:37 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"
#include <iostream>
// allowed function: roundf in the constructor for Fixed class where converting a
// float value to a fixed-point number.

int	main(void)
{
	// {
	// std::cout << std::endl << "------------------------------------------" << std::endl;
	// std::cout << "------------- test fixed class -------------" << std::endl;
	// std::cout << "------------------------------------------" << std::endl;
    // Fixed a(10); // using the integer constructor
    // Fixed b(5.5f); // using the float constructor
    // Fixed c(a); // using the copy constructor

    // // testing overloaded operators
    // std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    // std::cout << "a + b = " << a + b << std::endl;
    // std::cout << "a - b = " << a - b << std::endl;
    // std::cout << "a * b = " << a * b << std::endl;
    // std::cout << "a / b = " << a / b << std::endl;

    // // testing comparison operators
    // std::cout << "a > b: " << (a > b) << std::endl;
    // std::cout << "a < b: " << (a < b) << std::endl;
    // std::cout << "a == c: " << (a == c) << std::endl;

    // // testing min/max functions
    // std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    // std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
	// }
	
	// {
	// std::cout << std::endl << "------------------------------------------" << std::endl;
	// std::cout << "------------- test point class -------------" << std::endl;
	// std::cout << "------------------------------------------" << std::endl;
	
	// Point p1(10.5f, 5.5f);
    // Point p2 = p1; // using the copy assignment operator

    // std::cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
    // std::cout << "p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
	// }
	
	// {	
	// std::cout << std::endl << "------------------------------------------" << std::endl;
	// std::cout << "------------- test BSP 1 -------------" << std::endl;
	// std::cout << "------------------------------------------" << std::endl;
	// Point a(0.0, 0.0);
	// Point b(5.0, 0.0);
	// Point c(0.0, 5.0);
	// Point point(6.0, 2.0);

	// if (bsp(a, b, c, point))
	// 	std::cout << "Point is part of the triangle." << std::endl;
	// else
	// 	std::cout << "Point is not part of the triangle." << std::endl;
	// }
	
	{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "---------------- test BSP ----------------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
    // Define some triangles
    Point triangles[3][3] = {
        {
            Point(0.0, 0.0),
            Point(5.0, 0.0),
            Point(0.0, 5.0)
        },
		
        {
            Point(2.0, 2.0),
            Point(6.0, 2.0),
            Point(2.0, 6.0)
        },
		
        {
            Point(-1.0, -1.0),
            Point(-1.0, 4.0),
            Point(4.0, -1.0)
        }
    	};
	
    // Define some test points
    Point testPoints[5] = {
        Point(2.5, 2.5),
        Point(6.0, 2.0),
        Point(-1.0, -1.0),
        Point(3.0, 0.0),
        Point(3.5, 3.5)
    	};

/* For Triangle 1:

// Point 1 (2.5, 2.5) is inside the triangle.
// Point 2 (6.0, 2.0) is outside the triangle.
// Point 3 (-1.0, -1.0) is outside the triangle.
// Point 4 (3.0, 0.0) isinside the triangle.
// Point 5 (3.5, 3.5) is outside the triangle.
// For Triangle 2:

// Point 1 (2.5, 2.5) is inside the triangle.
// Point 2 (6.0, 2.0) is inside the triangle.
// Point 3 (-1.0, -1.0) is outside the triangle.
// Point 4 (3.0, 0.0) is outside the triangle.
// Point 5 (3.5, 3.5) is inside the triangle.
// For Triangle 3:

// Point 1 (2.5, 2.5) is outside the triangle.
// Point 2 (6.0, 2.0) is outside the triangle.
// Point 3 (-1.0, -1.0) is inside the triangle.
// Point 4 (3.0, 0.0) is inside the triangle.
// Point 5 (3.5, 3.5) is outside the triangle.
*/

    // Loop over each triangle
    for(int i = 0; i < 3; ++i) {
        std::cout << "Testing triangle " << i + 1 << std::endl;

        // Loop over each test point
        for(int j = 0; j < 5; ++j) {
            bool isInside = bsp(triangles[i][0], triangles[i][1], triangles[i][2], testPoints[j]);
            
            // Print whether the point is inside the triangle or not
            std::cout << "Point " << j + 1 << " is " << (isInside ? "inside" : "outside") << " the triangle" << std::endl;
        	}
		}
		std::cout << "------------------------------------------" << std::endl;
	}
}
