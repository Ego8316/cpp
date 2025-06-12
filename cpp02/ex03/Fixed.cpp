/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:51:23 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 02:19:13 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

// Constructors

Fixed::Fixed(void)
	:	_rawBits(0)
{
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int src)
{
	_rawBits = src << _fractionalBits;
	return ;
}

Fixed::Fixed(const float src)
{
	_rawBits = roundf(src * (1 << _fractionalBits));
	return ;
}

// Destructor

Fixed::~Fixed(void)
{
	return ;
}

// Operator overloadings

Fixed	&Fixed::operator=(Fixed const &src)
{
	_rawBits = src.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (_rawBits > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (_rawBits < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (_rawBits >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (_rawBits <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (_rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (_rawBits != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

// Getter

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

// Setter

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
	return ;
}

// Converters

float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

// Static methods

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

const Fixed	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}
Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}
const Fixed	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

// Stream overloading

std::ostream	&operator<<(std::ostream &os, Fixed const &src)
{
	os << src.toFloat();
	return (os);
}
