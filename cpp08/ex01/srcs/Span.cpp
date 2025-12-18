/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:16:36 by hcavet            #+#    #+#             */
/*   Updated: 2025/12/18 15:30:43 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
	:	_maxSize(0)
{
	return ;
}

Span::Span(const unsigned int size)
	:	_maxSize(size)
{
	return ;
}

Span::Span(const Span &src)
	:	_maxSize(src._maxSize),
		_vec(src._vec)
{
	return ;
}

Span	&Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_vec = src._vec;
	}
	return (*this);
}

Span::~Span(void)
{
	return ;
}

void	Span::addNumber(int n)
{
	if (_vec.size() == _maxSize)
		throw std::overflow_error("Span has reached maximum capacity");
	_vec.push_back(n);
	return ;
}

unsigned int	Span::shortestSpan(void) const
{
	if (_vec.size() < 2)
		throw std::runtime_error("Span has not enough elements");
	std::vector<int>	copy = _vec;
	std::sort(copy.begin(), copy.end());
	unsigned int	shortest = std::numeric_limits<unsigned int>::max();
	std::vector<int>::const_iterator	prev = copy.begin();
	std::vector<int>::const_iterator	it = prev;
	++it;
	for (; it != copy.end(); ++it, ++prev)
	{
		unsigned int	diff = static_cast<unsigned int>(
				static_cast<long long>(*it) - static_cast<long long>(*prev));
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	if (_vec.size() < 2)
		throw std::runtime_error("Span has not enough elements");
	long long	min = static_cast<long long>(*std::min_element(_vec.begin(), _vec.end()));
	long long	max = static_cast<long long>(*std::max_element(_vec.begin(), _vec.end()));
	return (static_cast<unsigned int>(max - min));
}

const std::vector<int>	&Span::getVec(void) const
{
	return (_vec);
}

std::ostream	&operator<<(std::ostream &os, const Span &s)
{
	const std::vector<int>	&v = s.getVec();
	os << "[";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (it != v.begin())
			os << ", ";
		os << *it;
	}
	os << "]";
	return (os);
}
