/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:33:58 by ego               #+#    #+#             */
/*   Updated: 2025/09/10 19:49:12 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)	:	AMateria("cure")	{}

Cure::Cure(Cure const &src)	:	AMateria(src)	{}

Cure	&Cure::operator=(Cure const &src)
{
	(void)src;
	return (*this);
}

Cure::~Cure(void)	{}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}
		
void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
