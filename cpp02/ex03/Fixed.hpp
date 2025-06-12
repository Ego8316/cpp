/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 23:48:32 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 02:43:18 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits;
	
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);

		Fixed	&operator=(Fixed const &src);

		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &src);

#endif