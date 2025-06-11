/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:27:13 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 19:46:14 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	:	_name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	*_weapon = weapon;
	return ;
}

void	HumanB::attack(void) const
{
	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}