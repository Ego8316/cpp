/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:22:12 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 17:14:24 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat(void)	:	_name("Bureaucrat"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)	:	_name(name)
{
	std::cout << "Bureaucrat parametrized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)	:	_name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat operator assignment operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

// Destructor

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

// Increment and decrement operators overload

Bureaucrat	&Bureaucrat::operator++(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
	return (*this);
}

// Method

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << ", because " << e.what() << std::endl;
	}
	return ;
}

// Getters

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// Stream operator overload

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
