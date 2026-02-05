/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:57:30 by ego               #+#    #+#             */
/*   Updated: 2026/02/04 20:57:56 by ego              ###   ########.fr       */
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
#include <iterator>
#include <unistd.h>
#include <cmath>

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

		C					_container;
		int					_comps;
		clock_t				_start;
		double				_time;
		std::vector<long>	_jacobstahl;

		void				_mergeInsertSort(int);
		void				_blockSort(int);
		void				_buildChains(int, std::vector<typename C::iterator> &, std::vector<typename C::iterator> &);
		std::vector<int>	_buildJacobOrder(int) const;
		void				_insertPendIntoMain(std::vector<typename C::iterator> &, std::vector<typename C::iterator> &);
		void				_copyMain(int, const std::vector<typename C::iterator> &);

		template <typename It> bool	_comp(It, It);
		template <typename It> It	_nextIt(It, int) const;
		template <typename It> void	_swapBlock(It, int);
		template <typename It> It	_blockLast(It, int);
};

template <template <typename, typename> class C, typename T, typename Alloc>
std::ostream	&operator<<(std::ostream &, const C<T, Alloc> &);

#include "PmergeMe.tpp"
