/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ego <ego@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:30:27 by ego               #+#    #+#             */
/*   Updated: 2025/06/11 22:58:58 by ego              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const std::string				PhoneBook::_CMD_ADD = "ADD";
const std::string				PhoneBook::_CMD_SEARCH = "SEARCH";
const std::string				PhoneBook::_CMD_EXIT = "EXIT";
const PhoneBook::FieldConfig	PhoneBook::_fields[] = {
	{"First name", &Contact::set_first_name, &Contact::get_first_name, NAME_ERR},
	{"Last name", &Contact::set_last_name, &Contact::get_last_name, NAME_ERR},
	{"Nickname", &Contact::set_nickname, &Contact::get_nickname, NAME_ERR},
	{"Phone number", &Contact::set_phone_number, &Contact::get_phone_number, NUMB_ERR},
	{"Darkest secret", &Contact::set_darkest_secret, &Contact::get_darkest_secret, EMPT_ERR},
	{NULL, NULL, NULL, NULL}
};

/**
 * @brief Default constructor for PhoneBook.
 */
PhoneBook::PhoneBook(void)
	:	_index(0), _size(0)
{
	return ;
}

/**
 * @brief Destructor for PhoneBook.
 */
PhoneBook::~PhoneBook(void)
{
	return ;
}

/**
 * @brief Prints the welcome message and list of available commands.
 */
void	PhoneBook::print_welcome(void) const
{
	std::cout << COLOR_B << "---- Welcome to My Awesome PhoneBook ----\n"
			 << C_RESET;
	std::cout << "Available commands: ADD, SEARCH and EXIT\n";
	return ;
}

/**
 * @brief Prints the command prompt.
 */
void	PhoneBook::print_prompt(void) const
{
	std::cout << COLOR_B << "phonebook > " << C_RESET;
	return ;
}

/**
 * @brief Handles the user command by executing the appropriate functionality.
 * 
 * @param cmd The user input command.
 * 
 * @return false if the user wants to exit the program, true otherwise.
 */
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
		return (_add());
	else if (cmd == _CMD_SEARCH)
		return (_search());
	else
		std::cerr << COLOR_R << cmd << ": command not found\n";
	return (true);
}

/**
 * @brief Adds a new contact to the phone book.
 * 
 * Prompts the user to fill in all the fields, validates the input, and stores
 * the contact. If the phone book is full (8 entries), it will overwrite the
 * oldest contact.
 * 
 * @return false if input fails (EOF), true otherwise.
 */
bool	PhoneBook::_add(void)
{
	Contact		c;
	std::string	input;

	std::cout << "Please enter the new contact information.\n";
	for (int i = 0; _fields[i].prompt; ++i)
	{
		while (true)
		{
			std::cout << "\t" << _fields[i].prompt << " : ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				return (false);
			if ((c.*_fields[i].setter)(input))
				break ;
			std::cerr << COLOR_R << _fields[i].prompt << " " << _fields[i].error
					<< std::endl << C_RESET;
		}
	}
	_contacts[_index++ % 8] = c;
	_size = std::min(_size + 1, 8);
	return (true);
}

/**
 * @brief Formats a string to fit within a 10-character column for table display.
 * 
 * If the string is longer than 10 characters, it truncates and appends a dot.
 * 
 * @param s The string to format.
 * 
 * @return The formatted string.
 */
std::string	PhoneBook::_format_column(std::string s) const
{
	if (s.length() > 10)
	{
		s = s.substr(0, 9);
		s += ".";
	}
	return (std::string(10 - s.length(), ' ') + s);
}

/**
 * @brief Prints the header and all stored contact summaries in a table format.
 */
void	PhoneBook::_print_columns(void) const
{
	std::cout << "+-------------------------------------------+\n";
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << "+-------------------------------------------+\n";
	for (int i = 0; i < _size; ++i)
	{
		std::cout << "|" << "         " << i + 1 << "|";
		for (int j = 0; j < 3; ++j)
			std::cout << _format_column((_contacts[i].*_fields[j].getter)()) << "|";
		std::cout << std::endl;
	}
	std::cout << "+-------------------------------------------+\n";
}

/**
 * @brief Allows the user to search for and view detailed information about a
 * specific contact.
 * 
 * Displays the list of contacts and prompts the user to select one by index.
 * 
 * @return false if input fails (EOF), true otherwise.
 */
bool	PhoneBook::_search(void) const
{
	std::string			input;
	int					index;

	if (_size == 0)
	{
		std::cout << "PhoneBook is empty :(\n";
		return (true);
	}
	_print_columns();
	std::cout << "Which entry would you like to display? (0 to exit SEARCH)\n";
	while (true)
	{
		std::cout << "Please enter a valid number : ";
		std::getline(std::cin, input);
		std::stringstream	ss(input);
		if (std::cin.eof())
			return (false);
		if (ss >> index && ss.eof() && index >= 0 && index <= _size)
			break ;
	}
	if (index == 0)
		return (true);
	std::cout << "Sure, here is " << (_contacts[index - 1].*_fields[0].getter)() << "'s information:\n";
	for (int i = 0; _fields[i].prompt; ++i)
		std::cout << "\t" << _fields[i].prompt << " : " << (_contacts[index - 1].*_fields[i].getter)() << std::endl;
	return (true);
}
