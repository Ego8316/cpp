/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 00:12:38 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 05:03:09 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

#define COLOR_R "\033[31m"
#define COLOR_B "\033[34m"
#define COLOR_G "\033[32m"
#define C_RESET "\033[0m"

bool bsp( Point const a, Point const b, Point const c, Point const p );

int	testTriangle(Point const a, Point const b, Point const c, Point const p, bool expected)
{
	bool		result;

	result = bsp(a, b, c, p);
	std::cout << "Triangle: A" << a << " B" << b << " C" << c << std::endl;
	std::cout << "Point: P" << p << std::endl;
	std::cout << "Point inside triangle: " << (result ? "yes"  : "no");
	std::cout << " (expected " << (expected ? "yes"  : "no")  << ")" << std::endl;
	if (result == expected)
		std::cout << COLOR_G << "[OK]" << C_RESET << std::endl;
	else
		std::cout << COLOR_R << "[KO]" << C_RESET << std::endl;
	std::cout << std::endl;
	return ((result == expected) ? 1 : 0);
}

void	test(void)
{
	int	count = 0;
	std::cout << std::endl << "--- BSP Tests ---" << std::endl << std::endl;
	// Right triangle on axes
	Point const	a(0, 0);
	Point const	b(10, 0);
	Point const	c(0, 10);
	count += testTriangle(a, b, c, Point(5, 5), false);   // vertex
	count += testTriangle(a, b, c, Point(10, 10), false); // outside
	count += testTriangle(a, b, c, Point(0, 0), false);   // vertex
	count += testTriangle(a, b, c, Point(5, 0), false);   // edge
	count += testTriangle(a, b, c, Point(0, 5), false);   // edge
	count += testTriangle(a, b, c, Point(1, 1), true);   // inside
	count += testTriangle(a, b, c, Point(5, 4), true);   // inside
	count += testTriangle(a, b, c, Point(9, 0.5f), true);   // inside
	// Obtuse triangle
	Point const	h(0, 0);
	Point const	i(4, 1);
	Point const	j(1, 7);
	count += testTriangle(h, i, j, Point(2, 2), true);   // inside
	count += testTriangle(h, i, j, Point(5, 5), false);  // outside
	// Equilateral triangle
	Point const	k(0, 0);
	Point const	l(5, 0);
	Point const	m(2.5f, 4.33f);
	count += testTriangle(k, l, m, Point(2.5f, 2.0f), true);  // inside
	count += testTriangle(k, l, m, Point(2.5f, 5.0f), false); // outside
	count += testTriangle(k, l, m, Point(0, 0), false);       // vertex
	// Collinear points triangle (degenerate)
	Point const	n(1, 1);
	Point const	o(2, 2);
	Point const	p(3, 3);
	count += testTriangle(n, o, p, Point(2, 2), false);  // on line, should be false since no area
	count += testTriangle(n, o, p, Point(1.5f, 1.5f), false); // on line
	count += testTriangle(n, o, p, Point(4, 4), false);  // outside
	if (count == 16)
		std::cout << COLOR_G << "[OK] All tests passed!" << C_RESET << std::endl;
	else
		std::cout << COLOR_R << "[KO] Failed (" << count << "/" << 16 << ")" << C_RESET << std::endl;
}

int	main(void)
{
	test();
	return (0);
}
