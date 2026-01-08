/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 23:48:11 by ego               #+#    #+#             */
/*   Updated: 2026/01/09 00:36:14 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"

template <typename C>
PmergeMe<C>::PmergeMe(const char **av)
	:	_comps(0),
		_time(0)
{
	_start = std::clock();
	for (int i = 1; av[i]; ++i)
		_container.push_back(std::atoi(av[i]));
	return ;
}

template <typename C>
PmergeMe<C>::~PmergeMe(void)
{
	return ;
}

template <typename C>
int	PmergeMe<C>::run(void)
{
	_time = 1000.0 * static_cast<double>(std::clock() - _start) / CLOCKS_PER_SEC;
	return (_comps);
}

template <typename C>
const C	&PmergeMe<C>::getContainer(void) const
{
	return (_container);
}

template <typename C>
int	PmergeMe<C>::getComps(void) const
{
	return (_comps);
}

template <typename C>
double	PmergeMe<C>::getTime(void) const
{
	return (_time);
}

template <template <typename, typename> class C, typename T, typename Alloc>
std::ostream	&operator<<(std::ostream &os, const C<T, Alloc> &c)
{
	for (typename C<T, Alloc>::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		if (it != c.begin())
			os << " ";
		os << *it;
	}
	return (os);
}
