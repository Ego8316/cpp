/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:45:52 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 19:09:57 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Memory address of the string variable :\t" << &string << std::endl;
	std::cout << "Memory address held by stringPTR :\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF :\t" << &stringREF << std::endl;

	std::cout << "Value of the string variable :\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR :\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF :\t" << stringREF << std::endl;
	return (0);
}
