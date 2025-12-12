/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:07:26 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 19:26:50 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Exceptions

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("Already signed!");
}

// Constructors

Form::Form(void)
	:	_name("Form"),
		_signed(false),
		_signGrade(1),
		_execGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::Form(const std::string &name, int signGrade, int execGrade)
	:	_name(name),
		_signed(false),
		_signGrade(signGrade),
		_execGrade(execGrade)
{
	std::cout << "Form parametrized constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	return ;
}

Form::Form(const Form &other)
	:	_name(other._name),
		_signed(other._signed),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

// Destructor

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

// Method

void	Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed)
		throw AlreadySignedException();
	_signed = true;
	return ;
}

// Getters

const std::string	&Form::getName(void) const
{
	return (_name);
}

bool	Form::isSigned(void) const
{
	return (_signed);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (_execGrade);
}

// Stream operator overload

std::ostream	&operator<<(std::ostream &os, const Form &f)
{
	os << "Form \"" << f.getName() << "\": ";
	if (f.isSigned())
		os << "signed";
	else
		os << "not signed";
	os << ", sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade();
	return (os);
}
