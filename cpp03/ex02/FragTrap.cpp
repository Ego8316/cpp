/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:19:55 by ego               #+#    #+#             */
/*   Updated: 2025/08/01 15:42:27 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors

FragTrap::FragTrap(void)
	:	ClapTrap(FRAG_DEFAULT_NAME)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = FRAG_DEFAULT_HIT_POINTS;
	_energyPoints = FRAG_DEFAULT_ENERGY_POINTS;
	_attackDamage = FRAG_DEFAULT_ATTACK_DAMAGE;
	_maxHitPoints = FRAG_DEFAULT_HIT_POINTS;
	return ;
}

FragTrap::FragTrap(std::string const &name)
	:	ClapTrap(name)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	_hitPoints = FRAG_DEFAULT_HIT_POINTS;
	_energyPoints = FRAG_DEFAULT_ENERGY_POINTS;
	_attackDamage = FRAG_DEFAULT_ATTACK_DAMAGE;
	_maxHitPoints = FRAG_DEFAULT_HIT_POINTS;
	return ;
}

FragTrap::FragTrap(FragTrap const &src)
	:	ClapTrap(src.getName())
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_hitPoints = src.getHitPoints();
	_energyPoints = src.getEnergyPoints();
	_attackDamage = src.getAttackDamage();
	_maxHitPoints = src.getMaxHitPoints();
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
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

void	FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << _name;
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
		std::cout << "FragTrap " << _name;
		std::cout << " is now powered down..." << std::endl;
	}
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " kindly asks for a high-fives!" << std::endl;
	return ;
}
