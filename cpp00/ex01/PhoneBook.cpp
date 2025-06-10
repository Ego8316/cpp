/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:30:27 by ego               #+#    #+#             */
/*   Updated: 2025/06/10 23:41:51 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const std::string PhoneBook::_CMD_ADD = "ADD";
const std::string PhoneBook::_CMD_SEARCH = "SEARCH";
const std::string PhoneBook::_CMD_EXIT = "EXIT";

PhoneBook::PhoneBook(void)
{
	_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::print_welcome(void)
{
	std::cout << COLOR_B << "---- Welcome to My Awesome PhoneBook ----\n" << C_RESET;
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
	if (cmd == _CMD_EXIT)
	{
		std::cout << "Thank you for using My Awesome PhoneBook!";
		return (false);
	}
	if (cmd == _CMD_ADD)
		std::cout << "command typed: add" << std::endl;
	else if (cmd == _CMD_SEARCH)
		std::cout << "command typed: search" << std::endl;
	else
		std::cerr << COLOR_R << cmd << ": command not found\n";
	return (true);
}

void	PhoneBook::add_contact(void)
{
	Contact		c;
	std::string	input;

	std::cout << "First name :";
	std::getline(std::cin, input);
	c.set_first_name(input);

	_contacts[_index++ % 8] = c;
	return ;
}