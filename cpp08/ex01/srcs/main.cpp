/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:15:27 by ego               #+#    #+#             */
/*   Updated: 2025/12/18 15:37:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void	basicTest(void)
{
	Span	s1(10);
	for (int i = 0; i < 10; ++i)
		s1.addNumber(i);
	std::cout << s1 << std::endl;
	std::cout << "Shortest span: " << s1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << s1.longestSpan() << std::endl;

	Span				s2(10);
	std::vector<int>	vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 2);
	s2.addNumber(vec.begin(), vec.end());
	std::cout << s2 << std::endl;
	std::cout << "Shortest span: " << s2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << s2.longestSpan() << std::endl;
}

static void	errorTest(void)
{
	Span	s(1);
	try { s.addNumber(1); }
	catch (const std::exception &e) { std::cerr << "Unexpected: " << e.what() << std::endl;}
	try { s.addNumber(1); }
	catch (const std::exception &e) { std::cerr << "Expected: " << e.what() << std::endl;}
	try { s.shortestSpan(); }
	catch (const std::exception &e) { std::cerr << "Expected: " << e.what() << std::endl; }
	try { s.longestSpan(); }
	catch (const std::exception &e) { std::cerr << "Expected: " << e.what() << std::endl; }
	std::vector<int>	vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(3);
	try { s.addNumber(vec.begin(), vec.end()); }
	catch (const std::exception &e) { std::cerr << "Expected: " << e.what() << std::endl; }
	try { s.addNumber(vec.end(), vec.begin()); }
	catch (const std::exception &e) { std::cerr << "Expected: " << e.what() << std::endl; }
}

static void	bigTest(void)
{
	const unsigned int	count = 15000;
	const long long		minVal = static_cast<long long>(std::numeric_limits<int>::min());
	const long long		maxVal = static_cast<long long>(std::numeric_limits<int>::max());
	const long long		range = maxVal - minVal;

	std::vector<int>	values;
	values.reserve(count);
	for (unsigned int i = 0; i < count; ++i)
	{
		long long	value = minVal;
		if (count > 1)
			value = minVal + (range * i) / (count - 1);
		values.push_back(static_cast<int>(value));
	}
	std::random_shuffle(values.begin(), values.end());

	Span	sp(count);
	sp.addNumber(values.begin(), values.end());
	std::cout << "Big test (" << count << " numbers from INT_MIN to INT_MAX)" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "Expected shortest span: "
		<< static_cast<unsigned int>(range / (count - 1)) << std::endl;
	std::cout << "Expected longest span: "
		<< static_cast<unsigned int>(range) << std::endl;
}

int	main(void)
{
	basicTest();
	std::cout << "--------------------------" << std::endl;
	errorTest();
	std::cout << "--------------------------" << std::endl;
	bigTest();
	return (0);
}
