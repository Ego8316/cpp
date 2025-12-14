/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:04:48 by ego               #+#    #+#             */
/*   Updated: 2025/12/12 14:23:21 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || !*argv[1])
	{
		std::cerr << "Usage: ./convert <value>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
