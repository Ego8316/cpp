/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:23 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 17:15:20 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

class	Form;

class	Bureaucrat
{
	public:
		class	GradeTooLowException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	GradeTooHighException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		Bureaucrat	&operator++(void);
		Bureaucrat	&operator--(void);

		void				signForm(Form &form) const;

		const std::string	&getName(void) const;
		int					getGrade(void) const;
	
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);
