/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:45:06 by ego               #+#    #+#             */
/*   Updated: 2025/06/13 17:05:40 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Static variables

std::string const	ClapTrap::defaultName = "CL4P-TP";
unsigned int const	ClapTrap::defaultHitPoints = 10;
unsigned int const	ClapTrap::defaultEnergyPoints = 10;
unsigned int const	ClapTrap::defaultAttackDamage = 0;

// Constructors

ClapTrap::ClapTrap(void)
	:	_name(defaultName),
		_hitPoints(defaultHitPoints),
		_energyPoints(defaultEnergyPoints),
		_attackDamage(defaultAttackDamage)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hitPoints(defaultHitPoints),
		_energyPoints(defaultEnergyPoints),
		_attackDamage(defaultAttackDamage)
{
	std::cout << "String constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
	:	_name(src.getName()),
		_hitPoints(src.getHitPoints()),
		_energyPoints(src.getEnergyPoints()),
		_attackDamage(src.getAttackDamage())
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// Destructor

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Copy assignment

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "Copy assignment called" << std::endl;
	if (this != &src)
	{
		_hitPoints = src.getHitPoints();
		_energyPoints = src.getEnergyPoints();
	}
	return (*this);
}

// Getters

std::string const	&ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

// Public methods

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " is defunct, he cannot attack..." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << " is powered down, he cannot attack..." << std::endl;
		return ;
	}
	std::cout << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
	--_energyPoints;
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " is now powered down..." << std::endl;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " is already defunct, leave him be!" << std::endl;
		return ;
	}
	std::cout << " takes " << amount << " points of damage!" <<std::endl;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is defunct!" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPoints == 0)
	{
		std::cout << " is defunct, he cannot repair itself..." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << " is powered down, he cannot repair itself..." << std::endl;
		return ;
	}
	if (_hitPoints + amount > defaultHitPoints)
		amount = defaultHitPoints - _hitPoints;
	if (amount == 0)
	{
		std::cout << " is already shiny and fully operational! No repairs required." << std::endl;
		return ;
	}
	_hitPoints += amount;
	std::cout << " regains " << amount << " hit points!" << std::endl;
	--_energyPoints;
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " is now powered down..." << std::endl;
	}
	return ;
}
