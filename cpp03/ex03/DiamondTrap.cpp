/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:22:48 by ego               #+#    #+#             */
/*   Updated: 2025/08/12 13:38:22 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors

DiamondTrap::DiamondTrap(void)
	:	ClapTrap("D14M-TP_clap_name"), FragTrap("D14M-TP"), ScavTrap("D14M-TP")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = "D14M-TP";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_maxHitPoints = FragTrap::_maxHitPoints;
	return ;
}

DiamondTrap::DiamondTrap(std::string const &name)
	:	ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap string constructor called" << std::endl;
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_maxHitPoints = FragTrap::_maxHitPoints;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
	:	ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
{
	if (this != &src)
	{
		_name = src.getName();
		_hitPoints = src.getHitPoints();
		_energyPoints = src.getEnergyPoints();
		_attackDamage = src.getAttackDamage();
		_maxHitPoints = src.getMaxHitPoints();
	}
	return (*this);
}

// Methods

void	DiamondTrap::whoAmI(void)
{
	if (_hitPoints == 0)
		std::cout << "Here lies " << _name << ", son of son of " << ClapTrap::_name << std::endl;
	else
		std::cout << "I am " << _name << ", son of son of " << ClapTrap::_name << std::endl;
	return ;
}
