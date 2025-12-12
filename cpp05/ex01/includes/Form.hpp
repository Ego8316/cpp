/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:07:19 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 19:26:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
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
		class	AlreadySignedException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		Form(void);
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form(void);

		void				beSigned(const Bureaucrat &signer);
		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &os, const Form &f);
