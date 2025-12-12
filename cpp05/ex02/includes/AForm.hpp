/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:07:19 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 19:38:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
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
		class	UnsignedException	:	public	std::exception
		{
			public:
				const char	*what() const throw();
		};

		AForm(void);
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm(void);

		void				beSigned(const Bureaucrat &signer);
		void				execute(const Bureaucrat &executor) const;

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

	protected:
		virtual void		_beExecuted(void) const = 0;		

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &f);
