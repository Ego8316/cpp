/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:33:04 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 21:58:25 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)	:	Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src)	:	Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
	return ;
}

Cat	&Cat::operator=(Cat const &src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src)
	{
		_type = src._type;
		if (_brain)
			delete (_brain);
		_brain = new Brain(*src._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << _type << ": meow" << std::endl;
	return ;
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
