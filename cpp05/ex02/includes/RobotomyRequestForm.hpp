/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:57:50 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 19:59:52 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>

#include "AForm.hpp"

#define ROBOTOMY_NAME "Robotomy Request Form"

class	RobotomyRequestForm	:	public	AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		const std::string	&getTarget(void) const;

		static const int	signGrade = 72;
		static const int	execGrade = 45;

	protected:
		void				_beExecuted(void) const;

	private:
		std::string			_target;
};
