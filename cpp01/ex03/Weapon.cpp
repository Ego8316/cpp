/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:14:29 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 19:42:48 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	_type = "fists";
	return ;
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const	&Weapon::getType(void) const
{
	std::string const	&ref = _type;
	return (ref);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}