/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:22:12 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 17:01:48 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Exceptions

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

// Constructors

Bureaucrat::Bureaucrat(void)	:	_name("Bureaucrat"), _grade(1)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)	:	_name(name)
{
	std::cout << "Parametrized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)	:	_name(other._name), _grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

// Destructor

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
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

// Getters

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// Stream operator overload

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
