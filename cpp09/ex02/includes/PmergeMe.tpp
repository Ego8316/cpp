/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 23:48:11 by ego               #+#    #+#             */
/*   Updated: 2026/02/05 01:06:01 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PmergeMe.hpp"

/**
 * @brief Builds the container from argv, starts timing, and precomputes
 * Jacobsthal numbers for later insertion order.
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
	_jacobstahl.clear();
	_jacobstahl.push_back(0);
	_jacobstahl.push_back(1);
	while (_jacobstahl.back() - _jacobstahl[_jacobstahl.size() - 2] <= static_cast<long>(_container.size()))
		_jacobstahl.push_back(_jacobstahl.back() + 2 * _jacobstahl[_jacobstahl.size() - 2]);
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
	_mergeInsertSort(1);
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
/**
 * @brief Recursive merge-insert (Ford-Johnson) driver for a given block size.
 *
 * Performs pair ordering, recurses on doubled block size, then builds chains
 * and inserts pend elements before copying back into the container.
 *
 * @param blockSize Current block size.
 */
void	PmergeMe<C>::_mergeInsertSort(int blockSize)
{
	typedef typename C::iterator	Iterator;

	if (_container.size() / blockSize < 2)
		return ;

	_blockSort(blockSize);
	_mergeInsertSort(blockSize * 2);

	std::vector<Iterator>	mainChain;
	std::vector<Iterator>	pendChain;

	_buildChains(blockSize, mainChain, pendChain);
	_insertPendIntoMain(mainChain, pendChain);
	_copyMain(blockSize, mainChain);
	return ;
}

template <typename C>
/**
 * @brief Orders adjacent blocks of size blockSize by their last element.
 *
 * For each pair of blocks, swaps them if the second block's last element is
 * smaller than the first's last element.
 *
 * @param blockSize Size of each block.
 */
void	PmergeMe<C>::_blockSort(int blockSize)
{
	typedef typename C::iterator	Iterator;

	int			blockCount = _container.size() / blockSize;
	Iterator	start = _container.begin();
	Iterator	end = _nextIt(start, blockCount / 2 * 2 * blockSize);

	for (Iterator it = start; it != end; std::advance(it, 2 * blockSize))
	{
		Iterator	thisBlock = _nextIt(it, blockSize - 1);
		Iterator	nextBlock = _nextIt(it, blockSize * 2 - 1);
		if (_comp(nextBlock, thisBlock))
			_swapBlock(thisBlock, blockSize);
	}
}

/**
 * @brief Builds the main and pend chains for the current block size.
 *
 * mainChain receives the last element of each "a" block (including a1),
 * while pendChain receives the last element of each "b" block (excluding b1).
 * If there is an odd leftover block, its last element is appended to pendChain.
 *
 * @param blockSize Size of each block at this stage.
 * @param mainChain Output vector of iterators for the main chain.
 * @param pendChain Output vector of iterators for the pending chain.
 */
template <typename C>
void	PmergeMe<C>::_buildChains(int blockSize,
	std::vector<typename C::iterator> &mainChain,
	std::vector<typename C::iterator> &pendChain)
{
	typedef typename C::iterator	Iterator;

	int	blockCount = _container.size() / blockSize;
	int	pairCount = blockCount / 2;
	Iterator	start = _container.begin();
	Iterator	end = _nextIt(start, pairCount * 2 * blockSize);

	mainChain.push_back(_nextIt(start, blockSize - 1));
	mainChain.push_back(_nextIt(start, blockSize * 2 - 1));

	for (int pairIndex = 2; pairIndex <= pairCount; ++pairIndex)
	{
		int	bIndex = 2 * pairIndex - 1;
		int	aIndex = 2 * pairIndex;
		pendChain.push_back(_nextIt(start, blockSize * bIndex - 1));
		mainChain.push_back(_nextIt(start, blockSize * aIndex - 1));
	}
	if (blockCount % 2 == 1)
		pendChain.push_back(_nextIt(end, blockSize - 1));
}

/**
 * @brief Builds the Jacobsthal-based insertion order for pend elements.
 *
 * The returned order contains 1-based indices into pendChain, grouped in
 * Jacobsthal blocks and filled in descending order within each block.
 *
 * @param pendSize Number of pending elements.
 * @return Vector of 1-based indices indicating insertion order.
 */
template <typename C>
std::vector<int>	PmergeMe<C>::_buildJacobOrder(int pendSize) const
{
	std::vector<int>	order;
	int					currJacob;
	int					prevJacob;

	if (pendSize <= 0)
		return (order);
	order.push_back(1);
	prevJacob = 1;
	for (size_t k = 3; k < _jacobstahl.size(); ++k)
	{
		currJacob = _jacobstahl[k];
		if (currJacob > pendSize)
			break ;
		for (int i = currJacob; i > prevJacob; --i)
			order.push_back(i);
		prevJacob = currJacob;
	}
	for (int i = pendSize; i > prevJacob; --i)
		order.push_back(i);
	return (order);
}

/**
 * @brief Inserts pend chain blocks into main chain using Jacobsthal order.
 *
 * Each pending block is inserted by binary search up to its corresponding
 * main-chain bound (a_i), minimizing comparisons.
 *
 * @param mainChain Main chain of block iterators.
 * @param pendChain Pending chain of block iterators.
 */
template <typename C>
void	PmergeMe<C>::_insertPendIntoMain(std::vector<typename C::iterator> &mainChain,
	std::vector<typename C::iterator> &pendChain)
{
	typedef typename C::iterator	Iterator;
	typedef typename std::vector<Iterator>::iterator ChainIt;

	std::vector<int>		order = _buildJacobOrder(pendChain.size());
	std::vector<Iterator>	aRefs = mainChain;

	for (size_t i = 0; i < order.size(); ++i)
	{
		int		orderIndex = order[i];
		ChainIt	pendIt = _nextIt(pendChain.begin(), orderIndex - 1);
		ChainIt	boundIt = mainChain.end();
		if (orderIndex + 1 < static_cast<int>(aRefs.size()))
			boundIt = std::find(mainChain.begin(), mainChain.end(), aRefs[orderIndex + 1]);
		ChainIt	low = mainChain.begin();
		ChainIt	high = boundIt;
		ChainIt	mid;

		while (low != high)
		{
			mid = low + (high - low) / 2;
			if (_comp(*pendIt, *mid))
				high = mid;
			else
				low = mid + 1;
		}
		mainChain.insert(low, *pendIt);
	}
}

/**
 * @brief Copies blocks from mainChain back into the container in order.
 *
 * @param blockSize Size of each block.
 * @param mainChain Main chain of block iterators.
 */
template <typename C>
void	PmergeMe<C>::_copyMain(int blockSize, const std::vector<typename C::iterator> &mainChain)
{
	typedef typename C::iterator	Iterator;
	Iterator						containerIt = _container.begin();
	std::vector<int>				copy;

	for (typename std::vector<Iterator>::const_iterator it = mainChain.begin();
		it != mainChain.end(); ++it)
	{
		Iterator	blockStart = _nextIt(*it, -blockSize + 1);
		for (int i = 0; i < blockSize; ++i)
		{
			Iterator	elem = _nextIt(blockStart, i);
			copy.push_back(*elem);
		}
	}
	for (std::vector<int>::iterator it = copy.begin();
		it != copy.end(); ++it, ++containerIt)
		*containerIt = *it;
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

/**
 * @brief Prints the original input order and the sorted container.
 * 
 * @param av Argument vector.
 * @param c Sorted container to display.
 */
template <typename C>
void	printBeforeAfter(const char **av, const C &c)
{
	std::cout << "Before:\t";
	for (int i = 1; av[i]; ++i)
	{
		if (i != 1)
			std::cout << " ";
		std::cout << std::atoi(av[i]);
	}
	std::cout << std::endl;
	std::cout << "After:\t" << c << std::endl;
}
