/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:31:06 by ego               #+#    #+#             */
/*   Updated: 2025/08/19 16:15:39 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)	:	Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	return ;
}

Dog::Dog(std::string const &type)	:	Animal(type)
{
	std::cout << "Dog parameterized constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src)	:	Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &src)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << _type << ": woof" << std::endl;
	return ;
}
