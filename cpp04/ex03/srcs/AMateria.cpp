/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:23:46 by ego               #+#    #+#             */
/*   Updated: 2025/09/10 19:49:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)	:	_type("undefined")	{}

AMateria::AMateria(AMateria const &src)	:	_type(src._type)	{}

AMateria::AMateria(std::string const &type)	:	_type(type)	{}

AMateria	&AMateria::operator=(AMateria const &src)
{
	(void)src;
	return (*this);
}

AMateria::~AMateria(void)	{}

std::string const	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* unknown materia used at "<< target.getName() << " *" << std::endl;
	return ;
}
