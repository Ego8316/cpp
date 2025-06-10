/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:05:40 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 16:11:34 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/**
 * @brief If only one argument (program name), prints the default message.
 * Otherwise, converts the arguments to C++ strings and iterate over it to put
 * them to uppercase before printing them. Prints a newline afterwards.
 * 
 * @param ac Argument count.
 * @param av Argument vector.
 */
int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		std::string	s(av[i]);
		for (std::string::iterator j = s.begin(); j != s.end(); j++)
			*j = std::toupper(*j);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
