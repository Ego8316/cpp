/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:26:20 by ego               #+#    #+#             */
/*   Updated: 2025/12/16 16:15:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

static void	printVector(const std::vector<int> &v)
{
	std::cout << "[";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (it != v.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << "]" << std::endl;
}

static void	testMutableContainer(void)
{
	std::vector<int>	values;
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	values.push_back(4);

	std::cout << "Mutable test before: ";
	printVector(values);
	try
	{
		std::vector<int>::iterator it = easyfind(values, 3);
		*it = 99;
		std::cout << "Found 3, changed to 99" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception (unexpected): " << e.what() << std::endl;
	}
	std::cout << "Mutable test after:  ";
	printVector(values);
}

static void	testConstContainer(void)
{
	std::list<int>	original;
	original.push_back(10);
	original.push_back(20);
	original.push_back(30);

	const std::list<int>	constList(original);
	std::cout << "Const test: ";
	for (std::list<int>::const_iterator it = constList.begin(); it != constList.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	try
	{
		std::list<int>::const_iterator it = easyfind(constList, 25);
		(void)it;
		std::cout << "Found 25 (unexpected)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception (expected): " << e.what() << std::endl;
	}
	try
	{
		std::list<int>::const_iterator it = easyfind(constList, 20);
		std::cout << "Found 20: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception (unexpected): " << e.what() << std::endl;
	}
}

int	main(void)
{
	testMutableContainer();
	std::cout << "----------------" << std::endl;
	testConstContainer();
	return (0);
}
