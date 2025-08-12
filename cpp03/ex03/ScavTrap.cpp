/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:21:45 by ego               #+#    #+#             */
/*   Updated: 2025/08/12 13:25:17 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors

ScavTrap::ScavTrap(void)
	:	ClapTrap(SCAV_DEFAULT_NAME)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = SCAV_DEFAULT_HIT_POINTS;
	_energyPoints = SCAV_DEFAULT_ENERGY_POINTS;
	_attackDamage = SCAV_DEFAULT_ATTACK_DAMAGE;
	_maxHitPoints = SCAV_DEFAULT_HIT_POINTS;
	return ;
}

ScavTrap::ScavTrap(std::string const &name)
	:	ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	_hitPoints = SCAV_DEFAULT_HIT_POINTS;
	_energyPoints = SCAV_DEFAULT_ENERGY_POINTS;
	_attackDamage = SCAV_DEFAULT_ATTACK_DAMAGE;
	_maxHitPoints = SCAV_DEFAULT_HIT_POINTS;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src)
	:	ClapTrap(src.getName())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_hitPoints = src.getHitPoints();
	_energyPoints = src.getEnergyPoints();
	_attackDamage = src.getAttackDamage();
	_maxHitPoints = src.getMaxHitPoints();
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
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

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " is depleted, he cannot attack..." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "'s battery is down, he cannot attack..." << std::endl;
		return ;
	}
	std::cout << " maims " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
	--_energyPoints;
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " is now powered down..." << std::endl;
	}
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name;
	if (_hitPoints == 0)
		std::cout << " is depleted, he cannot get in Gate keeper mode" << std::endl;
	else
		std::cout << " is now in Gate keeper mode" << std::endl;
	return ;
}
