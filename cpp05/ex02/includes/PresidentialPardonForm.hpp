/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 19:22:15 by ego               #+#    #+#             */
/*   Updated: 2025/11/22 20:11:03 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

#define PRESIDENTIAL_NAME "Presidential Pardon Form"

class	PresidentialPardonForm	:	public	AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		const std::string	&getTarget(void) const;

		static const int	signGrade = 25;
		static const int	execGrade = 5;

	protected:
		void				_beExecuted(void) const;

	private:
		std::string			_target;
};
