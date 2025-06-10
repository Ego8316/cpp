/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:30:27 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 18:25:45 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const std::string PhoneBook::CMD_ADD = "ADD";
const std::string PhoneBook::CMD_SEARCH = "SEARCH";
const std::string PhoneBook::CMD_EXIT = "EXIT";

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::print_welcome(void)
{
	std::cout << COLOR_B << "--- Welcome to My Awesome PhoneBook ---\n" << C_RESET;
	std::cout << "Available commands: ADD, SEARCH and EXIT\n";
	return ;
}

void	PhoneBook::print_prompt(void)
{
	std::cout << COLOR_B << "phonebook > " << C_RESET;
	return ;
}

bool	PhoneBook::handle_command(const std::string &cmd)
{
	if (cmd.empty())
		return (true);
	if (cmd == CMD_EXIT)
	{
		std::cout << "Thank you for using My Awesome PhoneBook!";
		return (false);
	}
	if (cmd == CMD_ADD)
		std::cout << "command typed: add" << std::endl;
	else if (cmd == CMD_SEARCH)
		std::cout << "command typed: search" << std::endl;
	else
		std::cout << COLOR_R << cmd << ": command not found\n";
	return (true);
}
