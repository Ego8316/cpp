/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:24:51 by ego               #+#    #+#             */
/*   Updated: 2025/10/16 19:21:17 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _maxTemplates; ++i)
		_templates[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < _maxTemplates; ++i)
		_templates[i] = src._templates[i] ? src._templates[i]->clone() : NULL;
	return ;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < _maxTemplates; ++i)
		{
			if (_templates[i])
				delete _templates[i];
			if (src._templates[i])
				_templates[i] = src._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _maxTemplates; ++i)
		if (_templates[i])
			delete _templates[i];
	return ;
}

void	MateriaSource::learnMateria(AMateria *src)
{
	for (int i = 0; i < _maxTemplates; ++i)
	{
		if (!_templates[i])
		{
			_templates[i] = src;
			std::cout << "Materia learnt" << std::endl;
			return ;
		}
	}
	delete src;
	std::cout << "Memory is full!" << std::endl;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _maxTemplates; ++i)
		if (_templates[i] && _templates[i]->getType() == type)
		{
			std::cout << "Successfully created Materia" << std::endl;
			return (_templates[i]->clone());
		}
	std::cout << "Materia " << type << " is not learnt" << std::endl;
	return (NULL);
}
