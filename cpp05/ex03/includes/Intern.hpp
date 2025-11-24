/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:28:19 by ego               #+#    #+#             */
/*   Updated: 2025/11/24 19:11:18 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class	Form;

class	Intern
{
	public:
		class	UnknownForm	:	public	std::exception
		{
			public:
				const char	*what(void) const throw() { return "Unknown form!"; }
		};
		Intern(void);
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern(void);

		AForm	*makeForm(const std::string &form, const std::string &target) const;

	private:
		typedef struct s_FormDict
		{
			const std::string	&formName;
			AForm				*(Intern::*formFunc)(const std::string &) const;
		}	FormDict;
		AForm	*_makeShrubberyCreationForm(const std::string &target) const;
		AForm	*_makeRobotomyRequestForm(const std::string &target) const;
		AForm	*_makePresidentialPardonForm(const std::string &target) const;
};
