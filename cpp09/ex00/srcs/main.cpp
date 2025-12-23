/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 20:48:03 by ego               #+#    #+#             */
/*   Updated: 2025/12/23 16:06:39 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("could not open file");
		BitcoinExchange	be(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "." << std::endl;
		return (1);
	}
	return (0);
}
