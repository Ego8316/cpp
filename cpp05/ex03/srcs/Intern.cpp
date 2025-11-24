/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:31:43 by ego               #+#    #+#             */
/*   Updated: 2025/11/23 13:34:14 by ego              ###   ########.fr       */
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
	return ;
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
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

}
