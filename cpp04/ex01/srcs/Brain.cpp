/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:26:09 by ego               #+#    #+#             */
/*   Updated: 2025/09/01 15:45:43 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < nbIdeas; ++i)
		_ideas[i] = "";
	return ;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain	&Brain::operator=(Brain const &src)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < nbIdeas; ++i)
		_ideas[i] = src._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

void	Brain::setIdea(int index, std::string const &idea)
{
	if (index < 0 || index >= nbIdeas)
	{
		std::cout << "Error 404: neuron not found" << std::endl;
		return ;
	}
	_ideas[index] = idea;
	std::cout << "Idea successfully implanted" << std::endl;
	return ;
}

void	Brain::sayIdea(int index) const
{	
	if (index < 0 || index >= nbIdeas)
	{
		std::cout << "Error 404: neuron not found" << std::endl;
		return ;
	}
	std::cout << "Here's an idea: " << _ideas[index] << std::endl;
	return ;
}
