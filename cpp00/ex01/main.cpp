/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcavet <hcavet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:16:11 by ego               #+#    #+#             */
/*   Updated: 2025/06/12 13:55:49 by hcavet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Trims leading and trailing whitespace characters from a string.
 * 
 * @param s The input string to trim.
 * 
 * @return A trimmed copy of the input string.
 */
static std::string	trim(const std::string &s)
{
	const std::string	ws = " \t\n\v\f\r";
	size_t				start = s.find_first_not_of(ws);
	size_t				end = s.find_last_not_of(ws);

	if (start == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}


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
		if (!phonebook.handle_command(trim(input)))
			break ;
	}
	std::cout << COLOR_B << "\nExited PhoneBook.\n" << C_RESET;
	return (0);
}
