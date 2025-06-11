/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:51:23 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 01:28:28 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed(void)
	:	_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int src)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = src << _fractionalBits;
	return ;
}

Fixed::Fixed(const float src)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(src * (1 << _fractionalBits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}


std::ostream	&operator<<(std::ostream &os, Fixed const &src)
{
	os << src.toFloat();
	return (os);
}
