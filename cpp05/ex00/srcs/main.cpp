/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:05 by ego               #+#    #+#             */
/*   Updated: 2025/12/12 13:50:25 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	A("Marc", 5);
	Bureaucrat	B("Patrick", 146);
	std::cout << A << std::endl << B << std::endl;

	std::cout << std::endl;
	// Should throw exception grade too low
	try	{ Bureaucrat	C("Martin", 156); }
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	// Should throw exception grade too high
	try	{ Bureaucrat	C("Martin", 0); }
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	// Now incrementing Marc until it raises an error
	for (int i = 0; i < 5; ++i)
	{
		try
		{
			++A;
			std::cout << A << std::endl;
		}
		catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }
	}

	std::cout << std::endl;
	// Now decrementing Patrick until it raises an error
	for (int i = 0; i < 5; ++i)
	{
		try
		{
			--B;
			std::cout << B << std::endl;
		}
		catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }
	}
	return (0);
}
