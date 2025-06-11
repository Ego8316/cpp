/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:38:29 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 22:00:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const Harl::HarlDict	Harl::_dict[] = {
	{"DEBUG", &Harl::_debug},
	{"INFO", &Harl::_info},
	{"WARNING", &Harl::_warning},
	{"ERROR", &Harl::_error},
	{NULL, NULL}
};

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; _dict[i].level; ++i)
	{
		if (level == _dict[i].level)
		{
			(this->*_dict[i].complaint)();
			return ;
		}
	}
	std::cout << DEFAULT_MSG << std::endl;
	return ;
}

void	Harl::_debug(void) const
{
	std::cout << DEBUG_MSG << std::endl;
	return ;
}

void	Harl::_info(void) const
{
	std::cout << INFO_MSG << std::endl;
	return ;
}

void	Harl::_warning(void) const
{
	std::cout << WARNING_MSG << std::endl;
	return ;
}

void	Harl::_error(void) const
{
	std::cout << ERROR_MSG << std::endl;
	return ;
}
