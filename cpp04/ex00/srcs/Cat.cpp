/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:33:04 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 21:40:23 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)	:	Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	return ;
}

Cat::Cat(Cat const &src)	:	Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << _type << ": meow" << std::endl;
	return ;
}
