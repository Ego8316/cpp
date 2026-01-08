/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:57:30 by ego               #+#    #+#             */
/*   Updated: 2026/01/09 00:41:11 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <limits>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <unistd.h>

template <typename C>
class	PmergeMe
{
	public:
		PmergeMe(const char **);
		~PmergeMe(void);

		int		run(void);

		const C	&getContainer(void) const;
		int		getComps(void) const;
		double	getTime(void) const;

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &);
		PmergeMe	&operator=(const PmergeMe &);

		C		_container;
		int		_comps;
		clock_t	_start;
		double	_time;

		long	_jacobsthal(long n);
};

template <template <typename, typename> class C, typename T, typename Alloc>
std::ostream	&operator<<(std::ostream &, const C<T, Alloc> &);

#include "PmergeMe.tpp"
