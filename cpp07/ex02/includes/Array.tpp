/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:24:38 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 20:12:40 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Constructors

template <typename T>
Array<T>::Array(void)
	:	_elements(NULL),
		_size(0)
{
	return ;
}

template <typename T>
Array<T>::Array(unsigned int n)
	:	_elements(n ? new T[n] : NULL),
		_size(n)
{
	return ;
}

template <typename T>
Array<T>::Array(const Array<T> &src)
{
	_size = src._size;
	_elements = src._size ? new T[src._size] : NULL;
	for (unsigned int i = 0; i < src._size; ++i)
		_elements[i] = src._elements[i];
	return ;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &src)
{
	if (this != &src)
	{
		delete[] _elements;
		_size = src._size;
		_elements = src._size ? new T[src._size] : NULL;
		for (unsigned int i = 0; i < src._size; ++i)
			_elements[i] = src._elements[i];
	}
	return (*this);
}

// Destructor

template <typename T>
Array<T>::~Array(void)
{
	delete[] _elements;
	return ;
}

// Subscript operator overloads

template <typename T>
T	&Array<T>::operator[](const unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_elements[index]);
}

template <typename T>
const T	&Array<T>::operator[](const unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_elements[index]);
}

// Getter for the size

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

// Stream operator overload

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array)
{
	os << "[";
	for (unsigned int i = 0; i < array.size(); ++i)
	{
		os << array[i];
		if (i != array.size() - 1)
			os << ", ";
	}
	os << "]";
	return (os);
}
