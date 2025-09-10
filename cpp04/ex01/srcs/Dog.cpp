/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:31:06 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 21:59:30 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)	:	Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src)	:	Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
	return ;
}

Dog	&Dog::operator=(Dog const &src)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src)
	{
		_type = src._type;
		if (_brain != NULL)
			delete _brain;
		_brain = new Brain(*src._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << _type << ": woof" << std::endl;
	return ;
}

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
