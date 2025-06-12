/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 03:10:57 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 04:37:46 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Determines on which side of the half-plane defined by `a` and `b` the
 * point `p` is by computing the z-component of the cross product of vectors
 * pa and pb.
 * 
 * MA x MB . ez = (x_A - x_M) * (y_B - y_M) - (x_B - x_M) * (y_A - y_M)
 */
static Fixed	sign(Point const &p, Point const &a, Point const &b)
{
	return ((a.getX() - p.getX()) * (b.getY() - p.getY())
			- (b.getX() - p.getX()) * (a.getY() - p.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	s1 = sign(point, a, b);
	Fixed	s2 = sign(point, b, c);
	Fixed	s3 = sign(point, c, a);
	
	return ((s1 > 0 && s2 > 0 && s3 > 0) || (s1 < 0 && s2 < 0 && s3 < 0));
}
