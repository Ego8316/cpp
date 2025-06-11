/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:38:29 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 22:25:04 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const char	*Harl::_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", NULL};

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
	int	index = -1;

	for (int i = 0; _levels[i]; ++i)
	{
		if (level == _levels[i])
		{
			index = i;
			break ;
		}
	}
	switch (index)
	{
		case 0:
			_debug();
			// intentional fallthrough
		case 1:
			_info();
			// intentional fallthrough
		case 2:
			_warning();
			// intentional fallthrough
		case 3:
			_error();
			break ;
		default:
			std::cout << DEFAULT_MSG << std::endl;
	}
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
