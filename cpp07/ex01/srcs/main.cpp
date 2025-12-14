/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:04:48 by ego               #+#    #+#             */
/*   Updated: 2025/12/14 18:08:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

void	mult(int &i)
{
	i *= 2;
	return ;
}

void	mult_const(const int &i)
{
	(void)i;
	return ;
}

void	toupper(char &c)
{
	if (c >= 'a' &&  c <= 'z')
		c += 'A' - 'a';
	return ;
}

void	toupper_const(const char &c)
{
	(void)c;
	return ;
}

int	main(void)
{
	int		array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char	str[] = "salut ca va";

	std::cout << "Array before iter: " << ::arrayToStr(array, 10) << std::endl;
	::iter(array, 10, mult);
	std::cout << "Array after iter: " << ::arrayToStr(array, 10) << std::endl;
	::iter(array, 10, mult_const);
	std::cout << "Array after iter const: " << ::arrayToStr(array, 10) << std::endl;

	std::cout << "String before iter: " << str << std::endl;
	::iter(str, sizeof(str), toupper);
	std::cout << "String after iter: " << str << std::endl;
	::iter(str, sizeof(str), toupper_const);
	std::cout << "String after iter const: " << str << std::endl;
	return (0);
}
