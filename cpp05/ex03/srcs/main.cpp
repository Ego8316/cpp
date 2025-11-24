/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:05 by ego               #+#    #+#             */
/*   Updated: 2025/11/24 19:18:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	someRandomIntern;
	AForm	*form;

	try
	{
		form = someRandomIntern.makeForm("presidential pardon", "Marc");
		std::cout << "Form created: " << *form << std::endl << std::endl;
		delete form;

	}
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }

	
	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Marc");
		std::cout << "Form created: " << *form << std::endl << std::endl;
		delete form;

	}
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }
	
	try
	{
		form = someRandomIntern.makeForm("shrubbery creation", "Marc");
		std::cout << "Form created: " << *form << std::endl << std::endl;
		delete form;

	}
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }
	
	try
	{
		form = someRandomIntern.makeForm("accomodation lease", "Marc");
		std::cout << "Form created: " << *form << std::endl << std::endl;
		delete form;

	}
	catch (const std::exception &e)	{ std::cerr << "Error: " << e.what() << std::endl; }
    return 0;
}