/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:03:33 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 20:09:32 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm(SHRUBBERY_NAME,
				ShrubberyCreationForm::signGrade,
				ShrubberyCreationForm::execGrade),
		_target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:	AForm(SHRUBBERY_NAME,
				ShrubberyCreationForm::signGrade,
				ShrubberyCreationForm::execGrade),
		_target(target)
{
	std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	:	AForm(other),
		_target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other)
		_target = other._target;
	return (*this);
}

// Destructor

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Getters

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

// Method

void	ShrubberyCreationForm::_beExecuted(void) const
{
	std::ofstream	ofs;

	ofs.open((_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
	ofs <<	"              v .   ._, |_  .,\n"
			"           `-._\\/  .  \\ /    |/_\n"
			"               \\\\  _\\, y | \\\\\n"
			"         _\\_.___\\\\, \\\\/ -.\\||\n"
			"           `7-,--.`._||  / / ,\n"
			"           /'     `-. `./ / |/_.'\n"
			"                     |    |//\n"
			"                     |_    /\n"
			"                     |-   |\n"
			"                     |   =|\n"
			"                     |    |\n"
			"--------------------/ ,  . \\--------._\n";
	ofs.close();
	return ;
}
