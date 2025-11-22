/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:05 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 19:27:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	A("Marc", 15);
	Bureaucrat	B("Patrick", 25);
	std::cout << A << std::endl << B << std::endl;

	std::cout << std::endl;
	// Should throw exception grade too low
	try	{ Form	C("Martin", 156, 35); }
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	// Should throw exception grade too low
	try	{ Form	C("Martin", 35, 156); }
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	// Should throw exception grade too high
	try	{ Form	C("Martin", 0, 35); }
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	std::cout << std::endl;
	// Should throw exception grade too high
	try	{ Form	C("Martin", 35, 0); }
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	Form	F1("NDA", 10, 10);
	Form	F2("Contract", 20, 20);
	Form	F3("Lease", 30, 30);

	A.signForm(F1);
	B.signForm(F1);
	A.signForm(F2);
	B.signForm(F2);
	A.signForm(F3);
	B.signForm(F3);
}
