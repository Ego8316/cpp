/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:00:03 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 20:02:32 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm(ROBOTOMY_NAME,
				RobotomyRequestForm::signGrade,
				RobotomyRequestForm::execGrade),
		_target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:	AForm(ROBOTOMY_NAME,
				RobotomyRequestForm::signGrade,
				RobotomyRequestForm::execGrade),
		_target(target)
{
	std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	:	AForm(other),
		_target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other)
		_target = other._target;
	return (*this);
}

// Destructor

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Getters

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

// Method

void	RobotomyRequestForm::_beExecuted(void) const
{
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << "'s robotomy failed" << std::endl;
	return ;
}
