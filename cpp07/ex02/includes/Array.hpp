/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:14:49 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 19:58:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>

template <typename T>
class	Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		Array	&operator=(const Array &src);
		~Array(void);

		T		&operator[](const unsigned int index);
		const T	&operator[](const unsigned int index) const;


		unsigned int	size(void) const;

	private:
		T				*_elements;
		unsigned int	_size;
};

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array);

#include "Array.tpp"