/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:21:28 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 18:41:10 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*heapZombie = newZombie("HeapZombie");

	heapZombie->announce();
	delete heapZombie;
	randomChump("StackZombie");
	std::cout << "All zombies are dead!\n";
	return (0);
}
