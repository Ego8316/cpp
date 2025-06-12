/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 02:43:45 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 04:36:28 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors

Point::Point(void)
	:	_x(0), _y(0)
{
	return ;
}

Point::Point(Fixed const x, Fixed const y)
	:	_x(x), _y(y)
{
	return ;
}

Point::Point(const float x, const float y)
	:	_x(x), _y(y)
{
	return ;
}

Point::Point(Point const &src)
	:	_x(src.getX()), _y(src.getY())
{
	return ;
}

// Destructor

Point::~Point(void)
{
	return ;
}

// Operator overloadings

Point	&Point::operator=(Point const &src)
{
	(void)src;
	return (*this);
}

// Getters

Fixed const	&Point::getX(void) const
{
	return (this->_x);
}

Fixed const	&Point::getY(void) const
{
	return (this->_y);
}

// Stream operator overloading

std::ostream	&operator<<(std::ostream &os, Point const &src)
{
	os << "(" << src.getX() << ", " << src.getY() << ")";
	return (os);
}