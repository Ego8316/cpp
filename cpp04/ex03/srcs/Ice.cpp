/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:50:19 by ego               #+#    #+#             */
/*   Updated: 2025/09/25 02:29:49 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)	:	AMateria("ice")	{}

Ice::Ice(Ice const &src)	:	AMateria(src) {}

Ice	&Ice::operator=(Ice const &src)
{
	(void)src;
	return (*this);
}

Ice::~Ice(void)	{}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}
		
void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
