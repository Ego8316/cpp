/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:45:38 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 20:02:37 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm(PRESIDENTIAL_NAME,
				PresidentialPardonForm::signGrade,
				PresidentialPardonForm::execGrade),
		_target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:	AForm(PRESIDENTIAL_NAME,
				PresidentialPardonForm::signGrade,
				PresidentialPardonForm::execGrade),
		_target(target)
{
	std::cout << "PresidentialPardonForm parametrized constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	:	AForm(other),
		_target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destructor

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Getters

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

// Method

void	PresidentialPardonForm::_beExecuted(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
	return ;
}
