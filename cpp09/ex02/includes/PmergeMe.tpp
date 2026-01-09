/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 23:48:11 by ego               #+#    #+#             */
/*   Updated: 2026/01/09 16:33:01 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"

/**
 * @brief Builds the container from argument vector and starts timing.
 * 
 * @param av Argument vector.
 */
template <typename C>
PmergeMe<C>::PmergeMe(const char **av)
	:	_comps(0),
		_time(0.0)
{
	_start = std::clock();
	for (int i = 1; av[i]; ++i)
		_container.push_back(std::atoi(av[i]));
	return ;
}

/**
 * @brief Destructor.
 */
template <typename C>
PmergeMe<C>::~PmergeMe(void)
{
	return ;
}

/**
 * @brief Runs a simple pairwise pass to validate helper utilities.
 * 
 * @return The comparison count.
 */
template <typename C>
int	PmergeMe<C>::run(void)
{
	_blockSort(1);
	_time = 1000.0 * static_cast<double>(std::clock() - _start) / CLOCKS_PER_SEC;
	return (_comps);
}

/**
 * @brief Getter for the container holding the sequence.
 */
template <typename C>
const C	&PmergeMe<C>::getContainer(void) const
{
	return (_container);
}

/**
 * @brief Getter for the number of comparisons made.
 */
template <typename C>
int	PmergeMe<C>::getComps(void) const
{
	return (_comps);
}

/**
 * @brief Getter for the elapsed time (ms) recorded for run().
 */
template <typename C>
double	PmergeMe<C>::getTime(void) const
{
	return (_time);
}

template <typename C>
void	PmergeMe<C>::_blockSort(int blockSize)
{
	typedef typename C::iterator	Iterator;

	int	blockCount = _container.size() / blockSize;
	if (blockCount < 2)
		return ;

	Iterator	start = _container.begin();
	Iterator	end = _nextIt(start, blockCount / 2 * 2 * blockSize);

	for (Iterator it = start; it != end; std::advance(it, 2 * blockSize))
	{
		Iterator	thisBlock = _nextIt(it, blockSize - 1);
		Iterator	nextBlock = _nextIt(it, blockSize * 2 - 1);
		if (_comp(nextBlock, thisBlock))
			_swapBlock(thisBlock, blockSize);
	}
	_blockSort(blockSize * 2);
	return ;
}

/**
 * @brief Comparison helper that increments the comparison counter.
 * 
 * @param lhs Left iterator.
 * @param rhs Right iterator.
 * 
 * @return true if *lhs < *rhs, false otherwise.
 */
template <typename C>
template <typename It>
bool	PmergeMe<C>::_comp(It lhs, It rhs)
{
	++_comps;
	return (*lhs < *rhs);
}

/**
 * @brief Returns an iterator advanced by a number of steps.
 * 
 * @param it Iterator to advance.
 * @param steps Number of steps (can be negative for bidirectional iterators).
 * 
 * @return Advanced iterator.
 */
template <typename C>
template <typename It>
It	PmergeMe<C>::_nextIt(It it, int steps) const
{
	std::advance(it, steps);
	return (it);
}

/**
 * @brief Swaps two consecutive blocks of equal size in the container.
 * 
 * @param lastOfFirst Iterator to the last element of the first block.
 * @param blockSize Size of each block.
 */
template <typename C>
template <typename It>
void	PmergeMe<C>::_swapBlock(It lastOfFirst, int blockSize)
{
	It	first = _nextIt(lastOfFirst, - blockSize + 1);
	for (int i = 0; i < blockSize; ++i)
		std::iter_swap(_nextIt(first, i), _nextIt(first, i + blockSize));
	return ;
}

/**
 * @brief Returns the iterator to the last element of a block.
 * 
 * @param blockStart Iterator to the first element of the block.
 * @param blockSize Size of the block.
 * 
 * @return Iterator to the last element in the block.
 */
template <typename C>
template <typename It>
It	PmergeMe<C>::_blockLast(It blockStart, int blockSize)
{
	return (_nextIt(blockStart, blockSize - 1));
}

/**
 * @brief Streams a sequential container as a space-separated list.
 */
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
