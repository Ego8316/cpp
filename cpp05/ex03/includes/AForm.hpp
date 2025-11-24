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
				const char	*what() const throw() { return "Grade is too low!";  }
		};
		class	GradeTooHighException	:	public	std::exception
		{
			public:
				const char	*what() const throw() { return "Grade is too high!"; } 
		};
		class	AlreadySignedException	:	public	std::exception
		{
			public:
				const char	*what() const throw() { return "Already signed!"; }
		};
		class	UnsignedException	:	public	std::exception
		{
			public:
				const char	*what() const throw() { return "Not signed!"; }
		};

		AForm(void);
		AForm(const std::string &name, unsigned int signGrade, unsigned int execGrade);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm(void);

		void				beSigned(const Bureaucrat &signer);
		void				execute(const Bureaucrat &executor) const;

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		unsigned int		getSignGrade(void) const;
		unsigned int		getExecGrade(void) const;

	protected:
		virtual void		_beExecuted(void) const = 0;		

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &f);
