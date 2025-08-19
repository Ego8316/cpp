/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:33:04 by ego               #+#    #+#             */
/*   Updated: 2025/08/19 14:50:29 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)	:	WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(std::string const &type)	:	WrongAnimal(type)
{
	std::cout << "WrongCat parameterized constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src)	:	WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << _type << ": meow" << std::endl;
	return ;
}
