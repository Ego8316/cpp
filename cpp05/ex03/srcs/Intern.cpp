/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:31:43 by ego               #+#    #+#             */
/*   Updated: 2025/11/24 19:21:20 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Constructors

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
	return ;
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

// Destructor

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

AForm	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	static const FormDict	forms[3] = {
		{"shrubbery creation", &Intern::_makeShrubberyCreationForm},
		{"robotomy request", &Intern::_makeRobotomyRequestForm},
		{"presidential pardon", &Intern::_makePresidentialPardonForm}
	};
	for (int i = 0; i < 3; ++i)
	{
		if (forms[i].formName == form)
		{
			std::cout << "Intern created a " << form << " form" << std::endl;
			return ((this->*(forms[i].formFunc))(target));
		}
	}
	throw UnknownForm();
}

AForm	*Intern::_makeShrubberyCreationForm(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::_makeRobotomyRequestForm(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::_makePresidentialPardonForm(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}
