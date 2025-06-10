/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:16:11 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 18:09:09 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook			phonebook;
	std::string			input;

	phonebook.printWelcome();
	while (true)
	{
		phonebook.printPrompt();
		if (!std::getline(std::cin, input))
			break ;
		if (!phonebook.handleCommand(input))
			break ;
	}
	std::cout << std::endl;
	return (0);
}
