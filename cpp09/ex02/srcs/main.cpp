/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:57:15 by ego               #+#    #+#             */
/*   Updated: 2026/01/09 15:40:09 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Validates that a string is a positive integer.
 * 
 * @param s String to be checked.
 * 
 * @return true if s is a valid positive integer (> 0), false otherwise.
 */
static bool	isPositiveInt(const char *s)
{
	int			i = 0;
	long long	n = 0;

	if (s[i] == '+' || s[i] == '-')
		++i;
	for (; std::isdigit(static_cast<unsigned char>(s[i])); ++i)
	{
		n = n * 10 + s[i] - '0';
		if (n > std::numeric_limits<int>::max())
			return (false);
	}
	if (s[i] || (n > 0 && s[0] == '-'))
		return (false);
	// if (n == 0)
	// 	return (false);
	return (true);
}

/**
 * @brief Checks if there is any duplicate number in the argument vector.
 * Compares numeric values, so "1", "+1", and "01" are treated as duplicates.
 * 
 * @param av Argument vector.
 * 
 * @return true if there is any duplicate, false otherwise.
 */
static bool	haveDuplicates(const char **av)
{
	for (int i = 1; av[i]; ++i)
		for (int j = 1; av[j]; ++j)
			if (i != j && std::atoi(av[i]) == std::atoi(av[j]))
				return (true);
	return (false);
}

/**
 * @brief Checks the integrity of the input. Ensures every argument is a
 * strictly positive integer and that there is no duplicate.
 * 
 * @param ac Argument count.
 * @param av Argument vector.
 * 
 * @return true if input is correct, false otherwise.
 */
static bool	checkInput(const int ac, const char **av)
{
	if (ac == 1)
		return (false);
	for (int i = 1; av[i]; ++i)
	{
		if (!isPositiveInt(av[i]))
			return (false);
	}
	if (haveDuplicates(av))
		return (false);
	return (true);
}

/**
 * @brief Prints the original input order and the sorted container.
 * 
 * @param av Argument vector.
 * @param v Sorted container to display.
 */
static void	printBeforeAfter(const char **av, const std::vector<int> &v)
{
	std::cout << "Before:\t";
	for (int i = 1; av[i]; ++i)
	{
		if (i != 1)
			std::cout << " ";
		std::cout << std::atoi(av[i]);
	}
	std::cout << std::endl;
	std::cout << "After:\t" << v << std::endl;
	return ;
}

/**
 * @brief Prints timing information in the subject's expected format.
 * 
 * @param n Number of elements processed.
 * @param c Container name to display.
 * @param t Time in milliseconds.
 */
static void	printTime(const int n, const std::string	&c, const double t)
{
	std::cout << "Time to process a range of "
		<< std::setfill(' ') << std::setw(4) << n
		<< " elements with std::" << c << " :\t"
		<< t << " ms" << std::endl;
	return ;
}

/**
 * @brief Ford-Johnson's entrypoint.
 * 
 * @param ac Argument count.
 * @param av Argument vector.
 * 
 * @return 1 in case of any error, 0 otherwise.
 */
int	main(int ac, const char **av)
{
	if (!checkInput(ac, av))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	PmergeMe<std::vector<int> >	vec(av);
	vec.run();
	PmergeMe<std::list<int> >	lis(av);
	lis.run();
	printBeforeAfter(av, vec.getContainer());
	printTime(ac - 1, "vector", vec.getTime());
	printTime(ac - 1, "list", lis.getTime());
	return (0);
}
