/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 21:45:06 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 16:03:33 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac < 2)
	{
		harl.complain("aaa");
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		std::string	level(av[i]);
		harl.complain(level);
	}
	return (0);
}
