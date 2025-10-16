/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:41:45 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:28:13 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	_name = "John Doe";
	for (int i = 0; i < _maxSlots; ++i)
		_inventory[i] = NULL;
	return ;
}

Character::Character(std::string const &name)
{
	_name = name;
	for (int i = 0; i < _maxSlots; ++i)
		_inventory[i] = NULL;
	return ;
}

Character::Character(const Character &src)
{
	_name = src._name;
	for (int i = 0; i < _maxSlots; ++i)
		_inventory[i] = src._inventory[i] ? src._inventory[i]->clone() : NULL;
	return ;
}

Character	&Character::operator=(const Character &src)
{
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < _maxSlots; ++i)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < _maxSlots; ++i)
		if (_inventory[i])
			delete _inventory[i];
	return ;
}

std::string const	&Character::getName(void) const
{
	return (_name);
}

AMateria	*Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= _maxSlots)
		return (NULL);
	return (_inventory[idx]);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < _maxSlots; ++i)
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "Materia equipped at index " << i << std::endl;
			return ;
		}
	std::cout << "Inventory full!" << std::endl;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= _maxSlots)
	{
		std::cout << "Out of " << _name << "'s inventory range" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << _name << " does not have anything equipped at this index" << std::endl;
		return ;
	}
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= _maxSlots)
	{
		std::cout << "Out of " << _name << "'s inventory range" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << _name << " does not have anything equipped at this index" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
