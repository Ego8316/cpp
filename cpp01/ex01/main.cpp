/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:45:52 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 18:53:19 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int		N;
	Zombie	*zombies;

	N = 10;
	zombies = zombieHorde(N, "Zombie");
	for (int i = 0; i < N; ++i)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}