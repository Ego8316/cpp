/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:23 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 15:55:08 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
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

		Bureaucrat(void);
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		Bureaucrat	&operator++(void);
		Bureaucrat	&operator--(void);

		const std::string	&getName(void) const;
		unsigned int		getGrade(void) const;
	
	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);
