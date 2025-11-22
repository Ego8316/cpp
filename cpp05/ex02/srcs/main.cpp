/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:05 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 20:26:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	A("Marc", 135);
	Bureaucrat	B("Etienne", 40);
	Bureaucrat	C("Macron", 1);
	std::cout << A << std::endl << B << std::endl << C << std::endl;

	ShrubberyCreationForm	shrub("forest");
	RobotomyRequestForm		robo("Connor");
	PresidentialPardonForm	pres("Thierry");
	std::cout << std::endl << shrub << std::endl << robo << std::endl << pres << std::endl;

	std::cout << std::endl << "First trying to execute unsigned forms:" << std::endl;
	A.executeForm(shrub);
	B.executeForm(robo);
	C.executeForm(pres);

	std::cout << std::endl << "Not working! Lets sign them first:" << std::endl;
	A.signForm(shrub);
	B.signForm(robo);
	C.signForm(pres);

	std::cout << std::endl << "Now trying again should work:" << std::endl;
	A.executeForm(shrub);
	B.executeForm(robo);
	C.executeForm(pres);

	std::cout << std::endl;
	return (0);
}
