/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:55:11 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 16:29:21 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

/* 
Barycentric coordinate system. 
a point is represented as a linear combination of the vertices of a triangle
*/

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Define weights for the Barycentric coordinate system
    Fixed w1, w2, w3;

    // Calculate w1, w2
	// // Calculate weight w1, which is the ratio between the area of the triangle BCP and ABC.
    // If w1 is in [0, 1], it means that the point lies on the same side of line BC as vertex A.
    w1 = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) /
         ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	// Calculate weight w2, which is the ratio between the area of the triangle ACP and ABC.
    // If w2 is in [0, 1], it means that the point lies on the same side of line AC as vertex B.
    w2 = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) /
         ((b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY()));
	// Calculate weight w3 as the remaining weight, i.e., 1 - w1 - w2.
    // If w3 is in [0, 1], it means that the point lies on the same side of line AB as vertex C.
    w3 =  Fixed(1) - w1 - w2;

    // The point is inside the triangle if and only if all weights are within the range [0, 1]
    return w1 >= 0 && w1 <= 1 && w2 >= 0 && w2 <= 1 && w3 >= 0 && w3 <= 1;
}

// area-based Solution
// The principle behind this solution is simple: 
// if a point is inside a triangle -> the sum of the areas of the three smaller triangles it forms with the vertices 
// of the larger triangle will be equal to the area of the larger triangle.
//
// This solution calculates the area of the overall triangle and the areas of the three smaller triangles.
//  If the sum of the areas of the smaller triangles equals the area of the larger triangle, the point is inside the triangle.
// 
// However, it requires more computations (four area calculations instead of two weight calculations).

// It doesn't account for edge cases where the point is on the edge of the triangle.
//  To handle this -  add additional checks to see if the point lies on any of the triangle's edges.
