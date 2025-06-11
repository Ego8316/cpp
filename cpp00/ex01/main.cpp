/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:16:11 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 14:51:40 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief The main function of the PhoneBook program.
 * 
 * Prints the welcome message and enters a loop where the user can enter
 * commands ("ADD", "SEARCH", "EXIT"). Handles user input and delegates command
 * execution to the PhoneBook object.
 * 
 * @return int Returns 0 on normal exit.
 */
int	main(void)
{
	PhoneBook			phonebook;
	std::string			input;

	phonebook.print_welcome();
	while (true)
	{
		phonebook.print_prompt();
		if (!std::getline(std::cin, input))
			break ;
		if (!phonebook.handle_command(input))
			break ;
	}
	std::cout << COLOR_B << "\nExited PhoneBook.\n" << C_RESET;
	return (0);
}
