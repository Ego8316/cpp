/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:20:00 by ego               #+#    #+#             */
/*   Updated: 2025/12/16 16:12:15 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, const int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("No such value in container"));
	return (it);
}

template <typename T>
typename T::const_iterator	easyfind(const T &container, const int value)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw (std::out_of_range("No such value in container"));
	return (it);
}
