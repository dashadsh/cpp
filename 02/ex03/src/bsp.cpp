/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:55:11 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/07/18 15:13:17 by dgoremyk         ###   ########.fr       */
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
    Fixed w1, w2;

    // Calculate the denominator of the formula for w1. This is the determinant 
    // of the matrix formed by the differences between the triangle vertices' coordinates.
    Fixed denominator = (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY());

    // Calculate w1. The numerator is a bit complex and is based on the coordinates 
    // of the points a, b, c, and the point we're checking.
    // w1 gives the weight of point B in the Barycentric representation.
    Fixed numerator_w1 = a.getX() * (c.getX() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY());
    w1 = numerator_w1 / denominator;
        
    // Calculate w2 similarly. w2 gives the weight of point C in the Barycentric representation.
    Fixed numerator_w2 = point.getY() - a.getY() - w1 * (b.getY() - a.getY());
    w2 = numerator_w2 / (c.getY() - a.getY());
    
    // The sum of the weights w1 and w2 should be less than or equal to one for the point to be inside the triangle.
    // Also, we check that both weights are non-negative.
    // To exclude the case where the point is exactly at a vertex, we have the conditions (w1 != 0 || w2 != 0) 
    // and !((w1 == 1 && w2 == 0) || (w1 == 0 && w2 == 1)).
    bool isInside = w1 >= Fixed(0) && w2 >= Fixed(0) && (w1 + w2) <= Fixed(1) && (w1 != 0 || w2 != 0)
        && !((w1 == 1 && w2 == 0) || (w1 == 0 && w2 == 1));

    return isInside; // If the point is inside the triangle, return true. 
						// Otherwise, return false.
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
