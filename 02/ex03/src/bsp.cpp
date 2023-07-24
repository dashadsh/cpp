/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:55:11 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/24 12:27:34 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

/* 
Binary Space Partitioning :
1. compute barycentric coordinates of the point with respect to the triangle. 
Barycentric coordinates represent the point as a linear combination of the triangle's vertices.

2.check if all three barycentric coordinates are within the range [0, 1]. 
If they are, the point lies inside the triangle. 
If any of the coordinates are negative or greater than 1, 
the point lies outside the triangle.

If any coordinate is exactly 0 or 1, the point lies on the boundary of the triangle.
*/

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
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
//
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

// -------------------------------------------------------------------------------------------------
/*
In the Barycentric coordinate system, 
any point inside a triangle can be uniquely represented as a weighted sum of the triangle's vertices. 

Given a triangle ABC, any point P inside this triangle can be represented as:
	P = w1A + w2B + w3*C
where A, B, C are the vertices of the triangle, and w1, w2, and w3 are the weights or Barycentric coordinates. 

These weights satisfy the following conditions:
1. 0 <= w1, w2, w3 <= 1. This means each weight is between 0 and 1, inclusive.
2. w1 + w2 + w3 = 1. The sum of the weights is 1.

The idea here is that the weights w1, w2, and w3 give us information about the relative "closeness" 
of the point P to the vertices A, B, and C. 
If P is very close to A, then w1 will be close to 1, while w2 and w3 will be close to 0, and so on.

To calculate the Barycentric coordinates, we can use the following formulas:

w1 = ((B.y - C.y)*(P.x - C.x) + (C.x - B.x)*(P.y - C.y)) / ((B.y - C.y)*(A.x - C.x) + (C.x - B.x)*(A.y - C.y))

w2 = ((C.y - A.y)*(P.x - C.x) + (A.x - C.x)*(P.y - C.y)) / ((B.y - C.y)*(A.x - C.x) + (C.x - B.x)*(A.y - C.y))

w3 = 1 - w1 - w2

The denominator in both w1 and w2 is the same and is the area of the ABC triangle, multiplied by 2.
The numerators represent twice the area of the BCP triangle for w1, and twice the area of the ACP triangle for w2.

This gives us a nice geometric interpretation: w1 is the ratio of the area of triangle BCP to ABC, 
and similarly for w2.

Once we've calculated the Barycentric coordinates, we can use them to determine whether a point is:
 - inside the triangle (all weights are between 0 and 1),
 - on an edge of the triangle (one weight is 0, the others are between 0 and 1), 
 - on a vertex (one weight is 1, the others are 0), 
 - or outside the triangle (at least one weight is negative or greater than 1).
 */