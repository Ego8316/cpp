/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:11:46 by hcavet            #+#    #+#             */
/*   Updated: 2025/12/18 14:47:02 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <limits>
#include <iterator>

class	Span
{
	public:
		Span(void);
		Span(const unsigned int);
		Span(const Span &);
		Span	&operator=(const Span &);
		~Span(void);

		void				addNumber(int);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;

		template <typename T>
		void	addNumber(T begin, T end)
		{
			typename std::iterator_traits<T>::difference_type	count = std::distance(begin, end);
			if (count < 0)
				throw std::invalid_argument("Invalid iterator range");
			if (_vec.size() + static_cast<size_t>(count) > static_cast<size_t>(_maxSize))
				throw std::overflow_error("Span has reached maximum capacity");
			_vec.insert(_vec.end(), begin, end);
		}

		const std::vector<int>	&getVec(void) const;

	private:
		unsigned int		_maxSize;
		std::vector<int>	_vec;
};

std::ostream	&operator<<(std::ostream &, const Span &);
