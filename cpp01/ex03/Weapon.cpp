/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:14:29 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 19:55:59 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
	:	_type("fists")
{
	return ;
}

Weapon::Weapon(std::string type)
	:	_type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const	&Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}