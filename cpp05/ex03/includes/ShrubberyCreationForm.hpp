/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:02:52 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 20:23:25 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>

#include "AForm.hpp"

#define SHRUBBERY_NAME "Shrubbery Creation Form"

class	ShrubberyCreationForm	:	public	AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		const std::string	&getTarget(void) const;

		static const int	signGrade = 145;
		static const int	execGrade = 137;

	protected:
		void				_beExecuted(void) const;

	private:
		std::string			_target;
};
