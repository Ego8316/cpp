/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:07:26 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 19:38:29 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Exceptions

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*AForm::AlreadySignedException::what() const throw()
{
	return ("Already signed!");
}

const char	*AForm::UnsignedException::what() const throw()
{
	return ("Not signed!");
}

// Constructors

AForm::AForm(void)
	:	_name("Form"),
		_signed(false),
		_signGrade(1),
		_execGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
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

AForm::AForm(const AForm &other)
	:	_name(other._name),
		_signed(other._signed),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

AForm	&AForm::operator=(const AForm &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		_signed = other._signed;
	return (*this);
}

// Destructor

AForm::~AForm(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

// Methods

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (_signed)
		throw AlreadySignedException();
	_signed = true;
	return ;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (!_signed)
		throw UnsignedException();
	_beExecuted();
	return ;
}

// Getters

const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::isSigned(void) const
{
	return (_signed);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

// Stream operator overload

std::ostream	&operator<<(std::ostream &os, const AForm &f)
{
	os << "Form \"" << f.getName() << "\": ";
	if (f.isSigned())
		os << "signed";
	else
		os << "not signed";
	os << ", sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade();
	return (os);
}
