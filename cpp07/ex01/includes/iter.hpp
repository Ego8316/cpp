/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:12:34 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 18:12:11 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <iostream>

template <typename T> std::string	arrayToStr(T *array, const size_t len)
{
	std::ostringstream	oss;

	oss << "[";
	for (size_t i = 0; i < len; ++i)
	{
		oss << array[i];
		if (i != len - 1)
			oss << ", ";
	}
	oss << "]";
	return (oss.str());
}

template <typename T> void	iter(T *array, const size_t len, void (*func)(T &))
{
	if (array == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
	return ;
}

template <typename T> void	iter(const T *array, const size_t len, void (*func)(const T &))
{
	if (array == NULL || func == NULL)
		return ;
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
	return ;
}
