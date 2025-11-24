/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:28:19 by ego               #+#    #+#             */
/*   Updated: 2025/11/23 13:32:39 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	Form;

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern(void);

		AForm	*makeForm(const std::string &form, const std::string &target) const;
};
