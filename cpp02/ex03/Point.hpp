/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 02:35:29 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 04:36:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class	Point
{
	private:
		Fixed const	_x;
		Fixed const _y;
	
	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(const float x, const float y);
		Point(Point const &src);
		~Point(void);

		Point	&operator=(Point const &src);

		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;
};

std::ostream	&operator<<(std::ostream &os, Point const &src);

#endif