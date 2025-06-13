/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:00:36 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 15:52:18 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
	:	_name("Frank")
{
	return ;
}

Zombie::Zombie(std::string name)
	:	_name(name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " died\n";
	return ;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
